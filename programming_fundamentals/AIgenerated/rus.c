/* file     : running_sums_array.c */
/* author   : Harry (qilin2603379191@gmail.com) */
/* date     : 2025/10/15 */
/* version  : 1.0 */
/* Description:
 * Count the number of non-empty contiguous subarrays whose sum equals s.
 * Each element is in [-9..9]. 
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int s;
   int n;
   if (scanf("%d %d", &s, &n) != 2) {
      return 0;
   }

   int *arr = (int *)malloc(n * sizeof(int));
   for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   /* Prefix sum range: [-9n, 9n] → size = 18n + 1, offset = 9n */
   int maxAbs = 9 * n;
   int size = 18 * n + 1;
   int offset = maxAbs;

   int *freq = (int *)calloc(size, sizeof(int));
   if (!freq) {
      free(arr);
      return 0;
   }

   long long count = 0;
   int prefix = 0;

   /* Empty prefix (sum = 0) appears once before processing any element. */
   freq[0 + offset] = 1;

   for (int i = 0; i < n; i++) {
      prefix += arr[i];

      int needIdx = prefix - s + offset;
      if (needIdx >= 0 && needIdx < size) {
         count += (long long)freq[needIdx];
      }

      int curIdx = prefix + offset;
      if (curIdx >= 0 && curIdx < size) {
         freq[curIdx] += 1;
      }
   }

   printf("%lld\n", count);

   free(freq);
   free(arr);
   return 0;
}