/* file     : pandigital_division.c */
/* author   : XueJin Cui */
/* date     : 2025/12/09 */
/* version  : 1.0 */
/* Description:
 * Given an integer n (1 < n < 80), find all divisions ABCDE/FGHIJ = n
 * where:
 *   - A..J are digits 0..9
 *   - every digit 0..9 is used exactly once
 *   - leading zeros are allowed, but not both A and F are zero
 * For every valid division, print it as ABCDE/FGHIJ with five digits
 * on each side (including possible leading zeros), in descending
 * order of ABCDE.  If no division exists, print "NONE".
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
   int numerator;
   int denominator;
} DivisionPair;

/* Convert value to a 5-digit string with leading zeros */
void toFiveDigitString(int value, char buffer[6])
{
   sprintf(buffer, "%05d", value);
}

/* Check if the 10 digits from numStr and denStr are a permutation of 0..9
 * with no repetitions, and that not both first digits are zero.
 */
int isValidPandigital(const char numStr[6], const char denStr[6])
{
   int used[10];
   int i;
   int digit;

   if (numStr[0] == '0' && denStr[0] == '0')
   {
      return 0;
   }

   for (i = 0; i < 10; i++)
   {
      used[i] = 0;
   }

   for (i = 0; i < 5; i++)
   {
      digit = numStr[i] - '0';
      if (used[digit])
      {
         return 0;
      }
      used[digit] = 1;
   }

   for (i = 0; i < 5; i++)
   {
      digit = denStr[i] - '0';
      if (used[digit])
      {
         return 0;
      }
      used[digit] = 1;
   }

   /* If we reached here, we have 10 different digits from 0..9 */
   return 1;
}

int main(void)
{
   int n;
   int maxDenominator;
   int denominator;
   int numerator;
   DivisionPair solutions[100];
   int solutionCount;
   char numStr[6];
   char denStr[6];
   int i;
   int j;

   if (scanf("%d", &n) != 1)
   {
      return 0;
   }

   solutionCount = 0;
   maxDenominator = 99999 / n;

   for (denominator = 1; denominator <= maxDenominator; denominator++)
   {
      numerator = denominator * n;

      if (numerator > 99999)
      {
         continue;
      }

      toFiveDigitString(numerator, numStr);
      toFiveDigitString(denominator, denStr);

      if (isValidPandigital(numStr, denStr))
      {
         solutions[solutionCount].numerator = numerator;
         solutions[solutionCount].denominator = denominator;
         solutionCount++;
      }
   }

   if (solutionCount == 0)
   {
      printf("NONE\n");
      return 0;
   }

   /* Sort solutions in descending order of numerator */
   for (i = 0; i < solutionCount; i++)
   {
      for (j = i + 1; j < solutionCount; j++)
      {
         if (solutions[i].numerator < solutions[j].numerator)
         {
            DivisionPair temp;

            temp = solutions[i];
            solutions[i] = solutions[j];
            solutions[j] = temp;
         }
      }
   }

   for (i = 0; i < solutionCount; i++)
   {
      toFiveDigitString(solutions[i].numerator, numStr);
      toFiveDigitString(solutions[i].denominator, denStr);
      printf("%s/%s\n", numStr, denStr);
   }

   return 0;
}