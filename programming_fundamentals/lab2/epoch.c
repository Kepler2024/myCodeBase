/* file    : epoch.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/10/07 */
/* version : 1.0 */
/* Description:
 * 
 */

#include <stdio.h>
#include <stdlib.h>

void printTheDay(int n) {
   n = n / 86400;
   n = n % 7 ;
   switch(n) {
      case 6: printf("Wednesday\n");
      break;
      case 5: printf("Tuesday\n");
      break;
      case 4: printf("Monday\n");
      break;
      case 3: printf("Sunday\n");
      break;
      case 2: printf("Saturday\n");
      break;
      case 1: printf("Friday\n");
      break;
      default: printf("Thursday\n");
   }
} 

int main(int argc, char *argv[]) {
   int n;
   scanf("%d",&n);
   printTheDay(n);
   return 0;
}
