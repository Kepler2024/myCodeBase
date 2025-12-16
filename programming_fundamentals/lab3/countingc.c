/* file    : countingc.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/12/11 */
/* version : 2.0 */
/* Description:
 * lab3_1_thrid attempt 100%!!!
 */

#include <stdio.h>
#include <stdlib.h>

void input(int length, int number[]) {
   // Input function to read length numbers
   for (int i=0;i<length;i++) {
      scanf ("%d",&number[i]);
   }
}

//we have three states:
//0: unvisited
//1: being visiting
//2: visited

void initialize(int length, int a[]) {
   // initialize the stage array to all 0 (unvisited)
   for (int i=0; i<length; i++) {
      a[i] = 0;
   }
}

int allVisited(int length, int stage[]) {
   // check if all elements are marked as visited (2)
   for (int i=0; i<length; i++) {
      if (stage[i] == 0) {
         return 0;
      }
   }
   return 1;
}

void print(int length, inta[]) {
   // print function to print the array
   for (int i=0;i<length;i++) {
      printf ("%d ",a[i]);
   }
   printf ("\n");
}

int countingCycle(int length,int stage[],int number[]) {
   int count = 0;
   int start = 0;

   while ((!allVisited(length,stage))&&(start < length)) {

      if (stage[start] != 0) {
         start++;
         continue;
      } // skip if already visited or being visiting

      int index = start;

      while (1) {

         if (stage[index] == 0) {
            stage[index] = 1;
            index = number[index];
            continue;
         } // mark as being visiting if unvisited (0)

         if (stage[index] == 1) {
            // if meeting being visiting (1), cycle detected
            stage[index] = 2;
            count++;
         } 

         if (stage[index] == 2) {
            for (int i=0;i<length;i++) {
               if (stage[i] == 1) {
                  stage[i] = 2;
               }
            } // mark all being visiting (1) as visited (2)
            break;
         }  
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