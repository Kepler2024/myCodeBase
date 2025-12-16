/* file    : countingcycle.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/10/27 */
/* version : 1.0 */
/* Description:
 * lab3_1
 * shit version
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

int repeating(int length, int start,int a[],int n) {
   for (int i=start; i<length; i++) {
      if (n == a[i]) {
         return 1;
      }
   }
   return 0;
}

void initialize(int length, int a[]) {
   for (int i=0; i<1000000; i++) {
      a[i] = length;
   }
}

int countingCycle(int length, int number[], int path[]) {
   int count = 0;
   int indexOfPath = 0;
   int position = 0;
   int start=0;
   while (position<length) {
      if (repeating(1000000,start,path,position)) {
         count++;
         position=0;
         for (int i = 0;i<length;i++) {
            if (position == path[i]) {
               position++;
            }
         }
         start = indexOfPath;
         continue;
      }
      path[indexOfPath] = position;
      position = number[position];
      indexOfPath++;
   } 
   return count;
}

int main(int argc, char *argv[]) {
   
   int length;
      scanf("%d",&length);
   int number[length];
   int path[1000000];
   initialize(length,path);
   input(length,number);
   printf("%d\n",countingCycle(length,number,path));

   return 0;
}