/* file    : animal.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/10/08 */
/* version : 1.0 */
/* Description:
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int n) {
   if (((n%4==0)&&(n%100 != 0))||(n%400==0)) {
      return 1;
   } else {
      return 0;
   }
}

int isFriday(int day) {
   return (day%7==0 ? 1:0);
}

int passingDay(int year) {
   int day=0;
   while (year > 2024) {
      day += (isLeapYear(year) ? 366 : 365);
      year --;
   }
   return day;
}

int main(int argc, char *argv[]) {
   int n,year=2024;
   scanf("%d",&n);
   while (n>0) {
      while (1) {
         year++;
         if (isFriday(passingDay(year))) {
            break;
         }
      }
      n--;
   }
   printf("%d\n",year);
   return 0;
}
