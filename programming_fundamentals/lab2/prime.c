/* file    : prime.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/10/04 */
/* version : 1.0 */
/* Description:
 * prime number lec2
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   int n;
   scanf("%d", &n);
   int a = 2;
   while (a < n) {
      if (n%a == 0) {
         break; // n is not a prime
      }
      a++;
   }  
   printf((n >= 2) && (a == n) ? "YES\n" : "NO\n");
   return 0;
}
