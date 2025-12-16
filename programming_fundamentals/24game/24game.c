#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input(double numbers[],char expr[][100]) {

   // Input function to read 4 numbers
   double a;
   printf("Input 4 numbers between 1 and 10 (inclusive):\n");
   for (int i=0;i<4;i++) {
      scanf ("%lf",&a);
      // check validity
      if ((a>=1) && (a<=10)) { 
         numbers[i] = a;
      } else {
         printf("Invalid input.\n");
         i--;
      }
   }

   // Initialize expressions as strings of the numbers
   for (int j=0;j<4;j++) {
      snprintf(expr[j],100,"%.0f",numbers[j]);
   }
}

int isEqual(double a,double b) {
   // Check if two doubles are equal
   return (fabs(a-b)<1e-9);
}

int isPossible(
   int length, double numbers[4],
   char expressions[4][100], char result[100]) {

      double newNumbers[4]; // Temporary array for new numbers
      char newExpressions[4][100]; // Temporary array for new expressions

      // Base case: if only one number left, check if it equals 24
      if (length == 1) {
         if (isEqual(numbers[0],24)) {
            snprintf(result,100,"%s",expressions[0]); //set result
            return 1;
         } else {
            return 0;
         }
      }

      // Use double loops to consider all pairs of numbers
      for (int i=0;i<length;i++) {
         for (int j=i+1;j<length;j++) {

            int index = 0;
            // Fill newNumbers and newExpressions with remaining numbers
            for (int k=0;k<length;k++) {
               if ((k!=i)&&(k!=j)) {
                  newNumbers[index] = numbers[k];
                  snprintf(newExpressions[index],100,"%s",expressions[k]);
                  index++;
               } 
            } 

            //Then try all operations between numbers[i] and numbers[j]

            //For addition and multiplication, we only need to do one order
            //addition:
            newNumbers[index] = numbers[i] + numbers[j]; // store sum
            snprintf (
               newExpressions[index],100,
               "(%s + %s)",expressions[i],expressions[j]);
               // store expression

            //Check if this leads to a solution, if so return 1 and skip rest
            if (isPossible(length-1,newNumbers,newExpressions,result)) {
               return 1;
            }
            
            // The other operation following the same pattern:
            //multiplication:
            newNumbers[index] = numbers[i] * numbers[j];
            snprintf (
               newExpressions[index],100,
               "(%s * %s)",expressions[i],expressions[j]);
            
            if (isPossible(length-1,newNumbers,newExpressions,result)) {
               return 1;
            }
            
            //For subtraction and division, we need to consider both orders
            //subtraction (order i - j):
            newNumbers[index] = numbers[i] - numbers[j];
            snprintf (
               newExpressions[index],100,
               "(%s - %s)",expressions[i],expressions[j]);

            if (isPossible(length-1,newNumbers,newExpressions,result)) {
               return 1;
            }

            //subtraction (order j - i):
            newNumbers[index] = numbers[j] - numbers[i];
            snprintf (
               newExpressions[index],100,
               "(%s - %s)",expressions[j],expressions[i]);

            if (isPossible(length-1,newNumbers,newExpressions,result)) {
               return 1;
            }

            //For division, we also need to ensure the denominator is not zero
            //division (order j / i):
            if (!isEqual(numbers[i],0)) {
               newNumbers[index] = numbers[j] / numbers[i];
               snprintf (
                  newExpressions[index],100,
                  "(%s / %s)",expressions[j],expressions[i]);
               
               if (isPossible(length-1,newNumbers,newExpressions,result)) {
                  return 1;
               }
            }

            //division (order i / j):
            if (!isEqual(numbers[j],0)) {
               newNumbers[index] = numbers[i] / numbers[j];
               snprintf (
                  newExpressions[index],100,
                  "(%s / %s)",expressions[i],expressions[j]);

               if (isPossible(length-1,newNumbers,newExpressions,result)) {
                  return 1;
               }
            }
         }
      }

      return 0;
}

int main(int argc, char *argv[]) {
   double numbers[4];
   char expressions[4][100];
   char result[100];
   input(numbers,expressions);
   if (isPossible(4,numbers,expressions,result)) {
      printf("Solution found: %s = 24\n",result);
   } else {
      printf ("No solution found.\n");
   }
   return 0;
}