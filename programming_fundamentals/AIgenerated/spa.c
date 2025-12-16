/* file     : spa.c */
/* author   : Harry (qilin2603379191@gmail.com) */
/* date     : 2025/10/22 */
/* version  : 1.1 */
/* Description:
 * Program to check if two binary matrices (n x n) are equal.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Return 1 if a text line contains only whitespace, otherwise 0. */
int isBlankLine(const char *lineText) {
   for (int charIndex = 0; lineText[charIndex] != '\0'; charIndex++) {
      if (lineText[charIndex] != ' ' && lineText[charIndex] != '\t' && lineText[charIndex] != '\r' && lineText[charIndex] != '\n') {
         return 0;
      }
   }
   return 1;
}

/* Parse integers from a line into countsBuffer[], return how many were parsed. */
int parseCounts(const char *lineText, int *countsBuffer, int maxCount) {
   char workingCopy[4096];
   int parsedCount = 0;
   strncpy(workingCopy, lineText, sizeof(workingCopy) - 1);
   workingCopy[sizeof(workingCopy) - 1] = '\0';
   char *tokenPtr = strtok(workingCopy, " \t\r\n");
   while (tokenPtr != NULL) {
      if (parsedCount < maxCount) {
         countsBuffer[parsedCount] = atoi(tokenPtr);
         parsedCount++;
      }
      tokenPtr = strtok(NULL, " \t\r\n");
   }
   return parsedCount;
}

int main(void) {
   int matrixSize;
   if (scanf("%d", &matrixSize) != 1) {
      return 0;
   }

   /* Allocate memory for the two reconstructed matrices. */
   int **rowWiseMatrix = (int **)malloc(matrixSize * sizeof(int *));
   for (int rowIndex = 0; rowIndex < matrixSize; rowIndex++) {
      rowWiseMatrix[rowIndex] = (int *)malloc(matrixSize * sizeof(int));
   }
   int **columnWiseMatrix = (int **)malloc(matrixSize * sizeof(int *));
   for (int rowIndex = 0; rowIndex < matrixSize; rowIndex++) {
      columnWiseMatrix[rowIndex] = (int *)malloc(matrixSize * sizeof(int));
   }

   /* Consume the newline after n. */
   int dummyChar;
   dummyChar = getchar();

   char inputLine[4096];
   int runCounts[205];

   /* Decode first matrix (row-wise) */
   for (int rowIndex = 0; rowIndex < matrixSize; rowIndex++) {
      if (!fgets(inputLine, sizeof(inputLine), stdin)) {
         return 0;
      }
      while (isBlankLine(inputLine)) {
         if (!fgets(inputLine, sizeof(inputLine), stdin)) {
            return 0;
         }
      }
      int numberOfRuns = parseCounts(inputLine, runCounts, 200);
      int currentValue = 0;
      int columnIndex = 0;
      for (int runIndex = 0; runIndex < numberOfRuns; runIndex++) {
         for (int repeat = 0; repeat < runCounts[runIndex]; repeat++) {
            rowWiseMatrix[rowIndex][columnIndex] = currentValue;
            columnIndex++;
         }
         currentValue = 1 - currentValue;
      }
   }

   /* Decode second matrix (column-wise)*/
   /* Read and skip blank lines until we get the first column’s encoding line*/
   if (!fgets(inputLine, sizeof(inputLine), stdin)) {
      return 0;
   }
   while (isBlankLine(inputLine)) {
      if (!fgets(inputLine, sizeof(inputLine), stdin)) {
         return 0;
      }
   }

   /* Handle the first column. */
   int firstColumnRunCount = parseCounts(inputLine, runCounts, 200);
   int currentValueForColumn = 0;
   int currentRowForColumn = 0;
   for (int runIndex = 0; runIndex < firstColumnRunCount; runIndex++) {
      for (int repeat = 0; repeat < runCounts[runIndex]; repeat++) {
         columnWiseMatrix[currentRowForColumn][0] = currentValueForColumn;
         currentRowForColumn++;
      }
      currentValueForColumn = 1 - currentValueForColumn;
   }

   /* Handle the remaining columns. */
   for (int columnIndex = 1; columnIndex < matrixSize; columnIndex++) {
      if (!fgets(inputLine, sizeof(inputLine), stdin)) {
         return 0;
      }
      while (isBlankLine(inputLine)) {
         if (!fgets(inputLine, sizeof(inputLine), stdin)) {
            return 0;
         }
      }
      int numberOfRuns = parseCounts(inputLine, runCounts, 200);
      int currentValue = 0;
      int rowIndex = 0;
      for (int runIndex = 0; runIndex < numberOfRuns; runIndex++) {
         for (int repeat = 0; repeat < runCounts[runIndex]; repeat++) {
            columnWiseMatrix[rowIndex][columnIndex] = currentValue;
            rowIndex++;
         }
         currentValue = 1 - currentValue;
      }
   }

   /* Compare both matrices */
   int matricesAreEqual = 1;
   for (int rowIndex = 0; rowIndex < matrixSize; rowIndex++) {
      for (int columnIndex = 0; columnIndex < matrixSize; columnIndex++) {
         if (rowWiseMatrix[rowIndex][columnIndex] != columnWiseMatrix[rowIndex][columnIndex]) {
            matricesAreEqual = 0;
            break;
         }
      }
      if (!matricesAreEqual) {
         break;
      }
   }

   if (matricesAreEqual) {
      printf("EQUAL\n");
   } else {
      printf("DIFFERENT\n");
   }

   for (int rowIndex = 0; rowIndex < matrixSize; rowIndex++) {
      free(rowWiseMatrix[rowIndex]);
   }
   for (int rowIndex = 0; rowIndex < matrixSize; rowIndex++) {
      free(columnWiseMatrix[rowIndex]);
   }
   free(rowWiseMatrix);
   free(columnWiseMatrix);

   return 0;
}