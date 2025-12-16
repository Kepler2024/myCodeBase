/* file     : octopussy.c */
/* author   : Harry (qilin2603379191@gmail.com) */
/* date     : 2025/10/15 */
/* version  : 1.1 */
/* Description:
 * Compute, for each cell (i,j), the Octopussy-sum:
 *   row i + col j + diagonal (\) through (i,j) + diagonal (/) through (i,j),
 * counting the center only once. Output the position with the maximal sum
 * (tie-break by smallest i, then smallest j) and the sum itself.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int n, m;
   if (scanf("%d %d", &n, &m) != 2) {
      return 0;
   }
   /* allocate matrix */
   int **a = (int **)malloc(n * sizeof(int *));
   for (int i = 0; i < n; i++) {
      a[i] = (int *)malloc(m * sizeof(int));
   }

   /* precompute row/col/diag sums while reading */
   long long *rowSum = (long long *)calloc(n, sizeof(long long));
   long long *colSum = (long long *)calloc(m, sizeof(long long));

   /* For \ diagonal, key = i - j in [-(m-1) .. (n-1)] -> shift by (m-1) */
   int diagLen = n + m - 1;
   long long *diag1 = (long long *)calloc(diagLen, sizeof(long long)); /* \ */
   long long *diag2 = (long long *)calloc(diagLen, sizeof(long long)); /* / */

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         int v;
         scanf("%d", &v);
         a[i][j] = v;

         rowSum[i] += v;
         colSum[j] += v;

         int d1 = (i - j) + (m - 1);   /* map to [0 .. diagLen-1] */
         int d2 = (i + j);             /* already in [0 .. diagLen-1] */
         diag1[d1] += v;
         diag2[d2] += v;
      }
   }

   int bestI = 0, bestJ = 0;
   long long bestSum = -1;

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         int d1 = (i - j) + (m - 1);
         int d2 = (i + j);

         /* counted center 4 times -> subtract 3 * a[i][j] */
         long long s = rowSum[i] + colSum[j] + diag1[d1] + diag2[d2]
                       - 3LL * (long long)a[i][j];

         if (s > bestSum || (s == bestSum && (i < bestI || (i == bestI && j < bestJ)))) {
            bestSum = s;
            bestI = i;
            bestJ = j;
         }
      }
   }

   printf("(%d,%d) %lld\n", bestI, bestJ, bestSum);

   for (int i = 0; i < n; i++) free(a[i]);
   free(a);
   free(rowSum);
   free(colSum);
   free(diag1);
   free(diag2);
   return 0;
}