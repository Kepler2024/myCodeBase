/* file     : submatrix_transpose.c */
/* author   : Harry (qilin2603379191@gmail.com) */
/* date     : 2025/10/01 */
/* version  : 1.0 */
/* Description:
 * Read an n × n integer matrix. Then perform k in-place transpositions of
 * square submatrices. Each submatrix is given by top-left corner (i, j)
 * and side length s. After all transpositions, read r1, c1, r2, c2 and
 * output the sum of all elements in the rectangular region defined by
 * rows r1..r2 and cols c1..c2 (inclusive).
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   int n;
   if (scanf("%d", &n) != 1) {
      return 0;
   }

   /* allocate n×n matrix */
   int **matrix = (int **)malloc(n * sizeof(int *));
   for (int i = 0; i < n; i++) {
      matrix[i] = (int *)malloc(n * sizeof(int));
   }

   /* read matrix */
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }

   /* read number of submatrix transpositions */
   int k;
   scanf("%d", &k);

   for (int op = 0; op < k; op++) {
      int topRow, leftCol, size;
      scanf("%d %d %d", &topRow, &leftCol, &size);

      /* transpose the s×s submatrix at (topRow, leftCol) */
      for (int r = 0; r < size; r++) {
         for (int c = r + 1; c < size; c++) {
            int tmp = matrix[topRow + r][leftCol + c];
            matrix[topRow + r][leftCol + c] = matrix[topRow + c][leftCol + r];
            matrix[topRow + c][leftCol + r] = tmp;
         }
      }
   }

   /* read region bounds */
   int r1, c1, r2, c2;
   scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

   long long sum = 0;
   for (int i = r1; i <= r2; i++) {
      for (int j = c1; j <= c2; j++) {
         sum += matrix[i][j];
      }
   }

   printf("%lld\n", sum);

   for (int i = 0; i < n; i++) {
      free(matrix[i]);
   }
   free(matrix);

   return 0;
}