/* file    : persistency.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/09/22 */
/* version : 2.1.1 */
/* Description:
 * this programs computes persistency of numbers
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   int number,product,times=0;
   scanf("%d",&number); // input number 
   while (number>=10) { 
      product = 1;
      while (number) {
         product *= number % 10; //take the last digit and multiply it
         number /= 10; //throw that digit away
         }//number eventually becomes 0 to end the loop
      number = product;//reset the number to continue the loop
      times++;//count times
   }
   printf ("%d\n",times);
   return 0;
}