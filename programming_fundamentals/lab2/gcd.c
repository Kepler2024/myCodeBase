/* file    : gcd.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/10/07 */
/* version : 1.0 */
/* Description:
 * gcd
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   int r,a,b;
   scanf("%d %d",&a,&b);
   while (b != 0) {
      int r = a%b;
      a = b;
      b = r;
   }
   printf("%d\n",a);
   return 0;
}