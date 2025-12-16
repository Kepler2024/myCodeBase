/* file    : powerful.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/10/08 */
/* version : 1.0 */
/* Description:
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int exp(int m,int n) {
   int a = 1;
   if (n==0) {
      return 1;
   } else {
      while (n != 0) {
         a *= m;
         n--;
      }
      return a;
   }
}

int main(int argc, char *argv[]) {
   int num,sum=0,a;
   scanf("%d",&num);
   for (int i=0;num!=0;i++) {
      a = num % 10;
      num = num / 10;
      sum += exp(a,i);
   }
   printf("%d\n",sum);
   return 0;
}
