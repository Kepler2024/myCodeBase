/* file    : counting4.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/12/13 */
/* version : 4.0 */
/* Description:
 * lab3_1_fourth attempt
 */

#include <stdio.h>
#include <stdlib.h>


void input(int length, int number[]) {
   // Input function to read length numbers
   for (int i=0;i<length;i++) {
      scanf ("%d",&number[i]);
   }
}

void initialize(int length, int a[]) {
   // initialize the stage array to all 0 (unvisited)
   for (int i=0; i<length; i++) {
      a[i] = 0;
   }
}

int countingCycle(int length,int stage[],int number[] ) {

   int count = 0;

   for (int i=0;i<length;i++) {

      if (stage[i] != 0) {
         continue;
      }

      int index = i;

      while (stage[index] == 0) {
         stage[index] = 1;
         index = number[index];
      }

      if (stage[index] == 1) {
         stage[index] = 2;
         count++;
         for (int j=0;j<length;j++) {
            if (stage[j] == 1) {
               stage[j] = 2;
            }
         }
         continue;
      }
   }
   return count;
}

int main(int argc, char *argv[]) {
   
   int length;
      scanf("%d",&length);
   int number[length];
   int stage[length];

   initialize(length,stage);
   input(length,number);
   printf("%d\n",countingCycle(length,stage,number));
   
   return 0;
}