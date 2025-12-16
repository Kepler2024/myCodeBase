/* file    : sum.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/10/09 */
/* version : 1.0 */
/* Description:
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int trans(int num) {
   int m,sum=0,n=0;
   while (num) {
      m = num % 10;
      num = num / 10;
      sum += n*m;
      n = m;
   }
   return sum;
}

int main(int argc, char *argv[]) {
   int num,times=0;
   scanf("%d",&num);
   while (num>=10) {
      num = trans(num);
      times++;
   }
   printf("%d %d\n",num,times);
   return 0;
}
