/* file    : countingcycle.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/10/27 */
/* version : 1.0 */
/* Description:
 * lab3_1 first attempt 30%
 */

#include <stdio.h>
#include <stdlib.h>

void input(int length, int number[]) {
   // Input function to read length numbers
   for (int i=0;i<length;i++) {
      scanf ("%d",&number[i]);
   }
}

void print(int length, int a[]) {
   // print function to print the array
   for (int i=0;i<length;i++) {
      printf ("%d ",a[i]);
   }
   printf ("\n");
}

int repeating(int length,int a[],int n) {
   for (int i=0; i<length; i++) {
      if (n == a[i]) {
         return 1;
      }
   }
   return 0;
}

void initialize(int length, int a[]) {
   for (int i=0; i<length; i++) {
      a[i] = length;
   }
}

int countingCycle(int length, int number[], int path[]) {
   int count = 0;
   int indexOfPath = 0;
   int position = 0;
   while (position<length) {
      path[indexOfPath] = position;
      if (repeating(10000000,path,position)) {
         count++;
         position=0;
         for (int i = 0;i<length;i++) {
            if (position == path[i]) {
               position++;
            }
         }
         initialize(10000000,path);
         indexOfPath = 0;
         continue;
      }
      position = number[position];
      indexOfPath++;
   } 
   return count;
}

int main(int argc, char *argv[]) {

   int length;
      scanf("%d",&length);
   int number[length];
   int path[10000000];
   
   initialize(length,path);
   input(length,number);
   printf("%d\n",countingCycle(length,number,path));
   return 0;
}