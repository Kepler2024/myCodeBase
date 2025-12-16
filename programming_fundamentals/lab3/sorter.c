/* file    : sorter.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/12/13 */
/* version : 1.0 */
/* Description:
 * 60%
 * doesnt work on 1000-length input since stack overflow
 * highlight:
 * Handles three lines of input at once
 * Use getchar,ungetc to check for termination character '#'
 * Use (%d,%d) format to process complex input mixed with symbols
 * revserse function to reverse subarrays
 * isAscending function to check if the array is sorted
 */

#include <stdio.h>
#include <stdlib.h>

void initialize(int length, int a[]) {
   // initialize the range array to all length
   // so that we know where the end is
   for (int i=0; i<200000; i++) {
      a[i] = length;
   }
}

void input(int length,int number[],int range[]) {
   // input function to read the numbers and ranges
   for (int i = 0; i<length; i++) {
      scanf("%d",&number[i]);
   } // input the numbers

   int left = 0;
   int right = 1;

   scanf("\n");// consume the newline character in the input
   while (1) {
      scanf(" ");// consume any spaces before the range input
      
      char input = getchar();
      if (input == '#') {
         break;
      }// read the first character to check for termination

      ungetc(input,stdin);// put the character back for normal reading
      scanf("(%d,%d)",&range[left],&range[right]);
      // use "(%d,%d)" format to read the range input
      left += 2;
      right += 2;
   }
}

void reverse(int left, int right, int number[]) {
   // reverse the subarray from left to right
   while (left <= right) {
      int copy = number[left];
      number[left] = number[right];
      number[right] = copy;
      left++;
      right--;
   } 
}

int isAscending(int length,int number[]) {
   // check if the array is sorted in ascending order
   for (int i=0,j=1; j<length; i++,j++) {
      if (number[i] > number[j]) {
         return 0;
      }
   }
   return 1;
}

int main(int argc, char *argv[]) {
   
   int length;
   scanf("%d",&length);
   int number[length];
   int range[200000];
   initialize(length,range);
   input(length,number,range);
   

   int left = 0;
   int right = 1;
   do {
      reverse(range[left],range[right],number);
      left += 2;
      right += 2;
   } while(range[left] != length);
   // reverse each subarray according to the ranges

   if (isAscending(length,number)) {
      printf("YES\n");
   } else {
      printf("NO\n");
   }

   return 0;
}