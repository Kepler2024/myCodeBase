/* file     : against_all_odds.c */
/* author   : XueJin Cui */
/* date     : 2025/12/17 */
/* version  : 2.0 */
/* Description:
 * Backtracking solver with strong pruning:
 * - Row/column digit distinctness via bitmasks.
 * - MRV (choose cell with fewest candidates).
 * - Precomputed feasibility bounds for parity constraint (evenSum == oddSum)
 *   for any used-digit mask and remaining cell count.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MaxN 9
#define DigitCount 10
#define AllDigitsMask ((1 << DigitCount) - 1)

int popCountByMask[1 << DigitCount];
int sumEvenByMask[1 << DigitCount];
int sumOddByMask[1 << DigitCount];
int minDiffAddByMaskAndCount[1 << DigitCount][MaxN + 1];
int maxDiffAddByMaskAndCount[1 << DigitCount][MaxN + 1];

int sizeN;
int grid[MaxN][MaxN];

int rowUsedMask[MaxN];
int colUsedMask[MaxN];

int emptyCellRow[MaxN * MaxN];
int emptyCellCol[MaxN * MaxN];
int emptyCellCount;

int solutionFound;

int computePopCount(int mask)
{
   int count = 0;
   while (mask != 0)
   {
      count += (mask & 1);
      mask >>= 1;
   }
   return count;
}

void precomputeMaskTables(void)
{
   int usedMask;
   int digit;

   for (usedMask = 0; usedMask <= AllDigitsMask; usedMask++)
   {
      int evenSum = 0;
      int oddSum = 0;

      popCountByMask[usedMask] = computePopCount(usedMask);

      for (digit = 0; digit < DigitCount; digit++)
      {
         if (usedMask & (1 << digit))
         {
            if (digit % 2 == 0)
            {
               evenSum += digit;
            }
            else
            {
               oddSum += digit;
            }
         }
      }

      sumEvenByMask[usedMask] = evenSum;
      sumOddByMask[usedMask] = oddSum;
   }

   for (usedMask = 0; usedMask <= AllDigitsMask; usedMask++)
   {
      int remainingCount;

      for (remainingCount = 0; remainingCount <= MaxN; remainingCount++)
      {
         minDiffAddByMaskAndCount[usedMask][remainingCount] = INT_MAX;
         maxDiffAddByMaskAndCount[usedMask][remainingCount] = INT_MIN;
      }

      {
         int availableMask = (~usedMask) & AllDigitsMask;
         int subsetMask = availableMask;

         while (1)
         {
            int subsetSize = popCountByMask[subsetMask];
            if (subsetSize <= MaxN)
            {
               int diffAdd = sumEvenByMask[subsetMask] - sumOddByMask[subsetMask];
               if (diffAdd < minDiffAddByMaskAndCount[usedMask][subsetSize])
               {
                  minDiffAddByMaskAndCount[usedMask][subsetSize] = diffAdd;
               }
               if (diffAdd > maxDiffAddByMaskAndCount[usedMask][subsetSize])
               {
                  maxDiffAddByMaskAndCount[usedMask][subsetSize] = diffAdd;
               }
            }

            if (subsetMask == 0)
            {
               break;
            }
            subsetMask = (subsetMask - 1) & availableMask;
         }
      }
   }
}

int isParityFeasibleForLineMask(int usedMask, int lineLength)
{
   int placedCount = popCountByMask[usedMask];
   int remainingCount;
   int currentDiff;
   int minAdd;
   int maxAdd;
   int minPossible;
   int maxPossible;

   if (placedCount > lineLength)
   {
      return 0;
   }

   remainingCount = lineLength - placedCount;
   currentDiff = sumEvenByMask[usedMask] - sumOddByMask[usedMask];

   if (remainingCount == 0)
   {
      return (currentDiff == 0);
   }

   minAdd = minDiffAddByMaskAndCount[usedMask][remainingCount];
   maxAdd = maxDiffAddByMaskAndCount[usedMask][remainingCount];

   if (minAdd == INT_MAX || maxAdd == INT_MIN)
   {
      return 0;
   }

   minPossible = currentDiff + minAdd;
   maxPossible = currentDiff + maxAdd;

   return (minPossible <= 0 && 0 <= maxPossible);
}

int computeCandidateMask(int rowIndex, int colIndex)
{
   int usedMask = rowUsedMask[rowIndex] | colUsedMask[colIndex];
   return (~usedMask) & AllDigitsMask;
}

int computeCandidateCount(int candidateMask)
{
   return popCountByMask[candidateMask];
}

void swapEmptyCellPositions(int firstIndex, int secondIndex)
{
   int tempRow = emptyCellRow[firstIndex];
   int tempCol = emptyCellCol[firstIndex];

   emptyCellRow[firstIndex] = emptyCellRow[secondIndex];
   emptyCellCol[firstIndex] = emptyCellCol[secondIndex];

   emptyCellRow[secondIndex] = tempRow;
   emptyCellCol[secondIndex] = tempCol;
}

void solveFromIndex(int filledCount)
{
   int bestIndex;
   int bestCandidateCount;
   int searchIndex;

   if (solutionFound)
   {
      return;
   }

   if (filledCount == emptyCellCount)
   {
      int r;
      int c;

      for (r = 0; r < sizeN; r++)
      {
         for (c = 0; c < sizeN; c++)
         {
            printf("%d", grid[r][c]);
         }
         printf("\n");
      }
      solutionFound = 1;
      return;
   }

   bestIndex = -1;
   bestCandidateCount = INT_MAX;

   for (searchIndex = filledCount; searchIndex < emptyCellCount; searchIndex++)
   {
      int rowIndex = emptyCellRow[searchIndex];
      int colIndex = emptyCellCol[searchIndex];
      int candidateMask = computeCandidateMask(rowIndex, colIndex);
      int candidateCount = computeCandidateCount(candidateMask);

      if (candidateCount == 0)
      {
         return;
      }

      if (candidateCount < bestCandidateCount)
      {
         bestCandidateCount = candidateCount;
         bestIndex = searchIndex;
         if (bestCandidateCount == 1)
         {
            break;
         }
      }
   }

   swapEmptyCellPositions(filledCount, bestIndex);

   {
      int rowIndex = emptyCellRow[filledCount];
      int colIndex = emptyCellCol[filledCount];
      int candidateMask = computeCandidateMask(rowIndex, colIndex);
      int digit;

      for (digit = 0; digit < DigitCount; digit++)
      {
         int digitBit = 1 << digit;
         if ((candidateMask & digitBit) == 0)
         {
            continue;
         }

         {
            int nextRowMask = rowUsedMask[rowIndex] | digitBit;
            int nextColMask = colUsedMask[colIndex] | digitBit;

            if (!isParityFeasibleForLineMask(nextRowMask, sizeN))
            {
               continue;
            }
            if (!isParityFeasibleForLineMask(nextColMask, sizeN))
            {
               continue;
            }

            grid[rowIndex][colIndex] = digit;
            rowUsedMask[rowIndex] = nextRowMask;
            colUsedMask[colIndex] = nextColMask;

            solveFromIndex(filledCount + 1);

            if (solutionFound)
            {
               return;
            }

            rowUsedMask[rowIndex] ^= digitBit;
            colUsedMask[colIndex] ^= digitBit;
            grid[rowIndex][colIndex] = -1;
         }
      }
   }

   swapEmptyCellPositions(filledCount, bestIndex);
}

int main(void)
{
   int r;
   int c;
   char rowString[32];

   precomputeMaskTables();

   if (scanf("%d", &sizeN) != 1)
   {
      return 0;
   }

   for (r = 0; r < sizeN; r++)
   {
      rowUsedMask[r] = 0;
   }
   for (c = 0; c < sizeN; c++)
   {
      colUsedMask[c] = 0;
   }

   emptyCellCount = 0;

   for (r = 0; r < sizeN; r++)
   {
      if (scanf("%s", rowString) != 1)
      {
         return 0;
      }

      for (c = 0; c < sizeN; c++)
      {
         char ch = rowString[c];

         if (ch == '.')
         {
            grid[r][c] = -1;
            emptyCellRow[emptyCellCount] = r;
            emptyCellCol[emptyCellCount] = c;
            emptyCellCount++;
         }
         else
         {
            int digit = ch - '0';
            int digitBit = 1 << digit;

            if ((rowUsedMask[r] & digitBit) != 0)
            {
               return 0;
            }
            if ((colUsedMask[c] & digitBit) != 0)
            {
               return 0;
            }

            grid[r][c] = digit;
            rowUsedMask[r] |= digitBit;
            colUsedMask[c] |= digitBit;
         }
      }
   }

   for (r = 0; r < sizeN; r++)
   {
      if (!isParityFeasibleForLineMask(rowUsedMask[r], sizeN))
      {
         return 0;
      }
   }
   for (c = 0; c < sizeN; c++)
   {
      if (!isParityFeasibleForLineMask(colUsedMask[c], sizeN))
      {
         return 0;
      }
   }

   solutionFound = 0;
   solveFromIndex(0);

   return 0;
}