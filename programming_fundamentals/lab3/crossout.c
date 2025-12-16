/* file    : crossout.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/12/13 */
/* version : 1.0 */
/* Description:
 * 
 */

#include <stdio.h>
#include <stdlib.h>

void initialize(int length, int a[]) {
   // initialize the stage array to all 0 (unvisited)
   for (int i=0; i<length; i++) {
      a[i] = 0;
   }
}

void input(int length,int numbers[]) {

   for (int i=0; i<length; i++) {
      scanf("%d",&numbers[i]);
      if (numbers[i]==0) {
         break;
      }
   }
}

void print(int length, int a[]) {
   // print function to print the array
   for (int i=0;i<7;i++) {
      printf ("%d ",a[i]);
   }
   printf ("\n");
}

int isMultiple() {
   


}

int main(int argc, char *argv[]) {
   
   int length = 100000;
   int numbers[100000];

   initialize (length,numbers);
   input(length,numbers);



   return 0;
}