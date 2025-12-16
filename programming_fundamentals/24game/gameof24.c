/* file    : gameof24.c */
/* author  : XueJin Cui, JiaYi Yang*/
/* date    : 2025/10/23 */
/* version : 2.1 */
/* Description:
 * compute 24 game solutions
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input(float numbers[],char expressions[][128]) {
   // Input function to read numbers
   printf("Please enter numbers between 1 and 10:\n");
   float a;
   for (int i = 0; i < 4; i++) {
      scanf("%f", &a);
      if (a < 1 || a > 10) {
         printf("Invalid input. Please enter numbers between 1 and 10.\n");
         i--;
      } else {
         numbers[i] = a;
      }
   }

   // Initialize expressions as string representations of the numbers
   for (int i = 0; i < 4; i++) {
      snprintf(expressions[i], 128, "%.0f", numbers[i]);
   }
}

int isEqual(float a, float b) {
   // Check if two floats are equal within a small tolerance
   return (fabsf(a - b) < 1e-6);
}

int isPossible(int length, float numbers[], char expressions[][128], char output[]) {
   // Recursive function to check if 24 can be formed and print the expression

   char newExpressions[4][128];// to hold new expressions

   if (length == 1) {
      snprintf(output, 256, "%s", expressions[0]);
      return (isEqual(numbers[0], 24.0));
   } // if one number left, check if it is 24

   // Try all pairs of numbers
   for (int i = 0; i < length; i++) {
      for (int j = 0; j < length; j++) {
         if (i != j) {
            float newNumbers[4]; // new array to hold remaining numbers
            int index = 0;
            for (int k = 0; k < length; k++) {
               if (k != i && k != j) {
                  newNumbers[index] = numbers[k];
                  snprintf(newExpressions[index], 128, "%s", expressions[k]);
                  index++;
               }
            }

            // Try all operations, then bring the new number and expression into recursion

            // for addition and multiplication, only need to do one order

            // addition
            newNumbers[index] = numbers[i] + numbers[j];
            snprintf(newExpressions[index], 128, "(%s + %s)", expressions[i], expressions[j]);
            if (isPossible(length-1,newNumbers,newExpressions,output)) return 1;

            // multiplication
            newNumbers[index] = numbers[i] * numbers[j];
            snprintf(newExpressions[index], 128, "(%s * %s)", expressions[i], expressions[j]);
            if (isPossible(length-1,newNumbers,newExpressions,output)) return 1;

            //for subtraction and division, need to try both orders

            // subtraction
            newNumbers[index] = numbers[i] - numbers[j];
            snprintf(newExpressions[index], 128, "(%s - %s)", expressions[i], expressions[j]);
            if (isPossible(length-1,newNumbers,newExpressions,output)) return 1;
            newNumbers[index] = numbers[j] - numbers[i];
            snprintf(newExpressions[index], 128, "(%s - %s)", expressions[j], expressions[i]);
            if (isPossible(length-1,newNumbers,newExpressions,output)) return 1;

            // division
            if (!isEqual(numbers[j],0)) {
               newNumbers[index] = numbers[i] / numbers[j];
               snprintf(newExpressions[index], 128, "(%s / %s)", expressions[i], expressions[j]);
               if (isPossible(length-1,newNumbers,newExpressions,output)) return 1;
            }
            if (!isEqual(numbers[i],0)) {
               newNumbers[index] = numbers[j] / numbers[i];
               snprintf(newExpressions[index], 128, "(%s / %s)", expressions[j], expressions[i]);
               if (isPossible(length-1,newNumbers,newExpressions,output)) return 1;
            }
         }
      }
   }
   return 0;
}

int main(int argc, char *argv[]) {
   float numbers[4];
   char expressions[4][128];// to hold string expressions
   char output[256];// to hold final output expression
   input(numbers, expressions);
   if (isPossible(4, numbers, expressions, output)) {
      printf("Solution found: %s = 24\n", output);
   } else {
      printf("No solution exists.\n");
   }
   return 0;
}