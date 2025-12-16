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

void input(int length,int number[]) {
   // input function to read the numbers and ranges
   for (int i = 0; i<length; i++) {
      scanf("%d",&number[i]);
   } // input the numbers
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
   input(length,number);

   int left = 0;
   int right = 0;
   scanf("\n");// consume the newline character in the input
   while (1) {
      scanf(" ");// consume any spaces before the range input
      
      char input = getchar();
      if (input == '#') {
         break;
      }// read the first character to check for termination

      ungetc(input,stdin);// put the character back for normal reading
      scanf("(%d,%d)",&left,&right);
      // use "(%d,%d)" format to read the range input
      reverse(left,right,number);
   }

   if (isAscending(length,number)) {
      printf("YES\n");
   } else {
      printf("NO\n");
   }

   return 0;
}