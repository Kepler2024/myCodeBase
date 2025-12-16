/* file    : double.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/12/13 */
/* version : 1.0 */
/* Description:
 * lab3_2
 * double a big integer
 * 100%
 * highlight: 
 * simulate the multiplication process digit by digit
 * transfer char to int by subtracting '0'
 * input function reads large number using getchar()
 * shortcomings:
 * "\n" is read and thus length is actually 1 more than expected
 * maybe do not use do-while loop for input
 */

#include <stdio.h>
#include <stdlib.h>

void print(int carry,int length, int number[]) {
   // print function to print the final result
   if (carry != 0) {
      printf("%d",carry);
   }// print carry if exists

   for (int i=0; i<length-1; i++) {
      printf("%d",number[i]);
   } // print the rest digits 
   
   printf("\n");
}

void multiply(int length, int number[]) {

   int carry = 0; // carry for each digit multiplication
   int midNumber = 0; // temporary variable to hold multiplication result
   for (int i = length-2; i>=0; i--) {
      midNumber = number[i] * 2 + carry;
      carry = midNumber / 10;
      number[i] = midNumber % 10;
   } // multiply each digit from the end to the start

   print(carry,length,number);// print the final result
}

int main(int argc, char *argv[]) {

   int length = 0;
   int number[1000];

   //input
   int digit;// temporary variable to hold each input digit
   do {
      digit = getchar();// read each digit as character
      number[length] = digit - '0'; // convert character to integer
      length++;
   } while (digit != '\n');
   

   multiply(length,number);

   return 0;
}