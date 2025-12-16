/* file     : stable_spf_sort.c */
/* author   : Harry (qilin2603379191@gmail.com) */
/* date     : 2025/10/07 */
/* version  : 1.1 */
/* Description:
 * Read n (>2), then n composite integers (>=4).
 * 1) Compute SPF (smallest prime factor) for each number.
 * 2) Stably sort numbers by SPF (simulate stability by sorting with
 *    tie-breaker = original index).
 * 3) Sum elements at prime indices (0-based) of the sorted array.
 * 4) Print the sum.
 */

#include <stdio.h>
#include <stdlib.h>

static int *values;   /* numbers */
static int *spfs;     /* smallest prime factors */
static int *indices;  /* original positions */

/* Return the smallest prime factor of x (x >= 2). */
static int smallestPrimeFactor(int x) {
   if (x % 2 == 0) return 2;
   for (int d = 3; d <= x / d; d += 2) {
      if (x % d == 0) return d;
   }
   return x;   /* should not happen because input is composite */
}

/* Comparator for qsort: compare by spf, then by original index */
static int cmpBySpfThenIndex(const void *a, const void *b) {
   int i = *(const int *)a;
   int j = *(const int *)b;
   if (spfs[i] != spfs[j]) {
      return (spfs[i] < spfs[j]) ? -1 : 1;
   }
   if (indices[i] != indices[j]) {
      return (indices[i] < indices[j]) ? -1 : 1;
   }
   return 0;
}

/* Sieve primes up to limit. primes[i]=1 if prime else 0 */
static void sievePrimes(int limit, int *primes) {
   for (int i = 0; i <= limit; i++) primes[i] = 1;
   if (limit >= 0) primes[0] = 0;
   if (limit >= 1) primes[1] = 0;
   for (int p = 2; p <= limit / p; p++) {
      if (primes[p]) {
         for (int v = p * p; v <= limit; v += p) {
            primes[v] = 0;
         }
      }
   }
}

int main(void) {
   int n;
   if (scanf("%d", &n) != 1) return 0;

   values = (int *)malloc(n * sizeof(int));
   spfs = (int *)malloc(n * sizeof(int));
   indices = (int *)malloc(n * sizeof(int));
   int *order = (int *)malloc(n * sizeof(int)); /* store indices 0..n-1 */

   for (int i = 0; i < n; i++) {
      scanf("%d", &values[i]);
      spfs[i] = smallestPrimeFactor(values[i]);
      indices[i] = i;
      order[i] = i;
   }

   /* Sort order[] by SPF then original index */
   qsort(order, n, sizeof(int), cmpBySpfThenIndex);

   /* Sieve primes on indices */
   int *primeIndex = (int *)malloc(n * sizeof(int));
   sievePrimes(n - 1, primeIndex);

   long long total = 0;
   for (int pos = 0; pos < n; pos++) {
      if (primeIndex[pos]) {
         int i = order[pos];     /* original index of element at position pos */
         total += values[i];
      }
   }

   printf("%lld\n", total);

   free(values);
   free(spfs);
   free(indices);
   free(order);
   free(primeIndex);
   return 0;
}