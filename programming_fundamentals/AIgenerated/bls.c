/* file     : block_sums_array.c */
/* author   : Harry (qilin2603379191@gmail.com) */
/* date     : 2025/10/15 */
/* version  : 1.0 */
/* Description:
 * Count the number of axis-aligned non-empty submatrices whose sum equals s.
 * Technique: fix top/bottom rows, compress columns to 1D, then count
 * subarrays equal to s using prefix sums and an array-based frequency table
 * with timestamping (lazy clearing). 
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int s;
   int n;
   int m;
   if (scanf("%d %d %d", &s, &n, &m) != 3) {
      return 0;
   }

   int **a = (int **)malloc(n * sizeof(int *));
   for (int i = 0; i < n; i++) {
      a[i] = (int *)malloc(m * sizeof(int));
      for (int j = 0; j < m; j++) {
         scanf("%d", &a[i][j]);
      }
   }

   /* Upper bound of absolute prefix sum:
      Each cell in [-9,9], and any 1D prefix spans at most n*m cells across
      all compressions, so |prefix| <= 9 * n * m. */
   int maxRange = 9 * n * m + 5;
   int size = 2 * maxRange + 1;
   int *freq = (int *)malloc(size * sizeof(int));
   int *seen = (int *)malloc(size * sizeof(int));
   for (int i = 0; i < size; i++) {
      freq[i] = 0;
      seen[i] = 0;
   }
   int stamp = 1;

   int *colSum = (int *)malloc(m * sizeof(int));
   for (int j = 0; j < m; j++) {
      colSum[j] = 0;
   }

   long long answer = 0;

   for (int top = 0; top < n; top++) {
      for (int j = 0; j < m; j++) {
         colSum[j] = 0;
      }

      for (int bottom = top; bottom < n; bottom++) {
         for (int j = 0; j < m; j++) {
            colSum[j] += a[bottom][j];
         }

         /* Start a new 1D count session. */
         stamp++;
         if (stamp == 0) {
            /* reset seen[] if stamp overflows */
            for (int i = 0; i < size; i++) {
               seen[i] = 0;
               freq[i] = 0;
            }
            stamp = 1;
         }

         int offset = maxRange;
         int idx0 = 0 + offset;
         if (seen[idx0] != stamp) {
            seen[idx0] = stamp;
            freq[idx0] = 0;
         }
         freq[idx0] = 1;

         int prefix = 0;
         for (int j = 0; j < m; j++) {
            prefix += colSum[j];

            int need = prefix - s + offset;
            if (need >= 0 && need < size) {
               if (seen[need] != stamp) {
                  seen[need] = stamp;
                  freq[need] = 0;
               }
               answer += (long long)freq[need];
            }

            int cur = prefix + offset;
            if (seen[cur] != stamp) {
               seen[cur] = stamp;
               freq[cur] = 0;
            }
            freq[cur]++;
         }
      }
   }

   printf("%lld\n", answer);

   for (int i = 0; i < n; i++) {
      free(a[i]);
   }
   free(a);
   free(freq);
   free(seen);
   free(colSum);
   return 0;
}