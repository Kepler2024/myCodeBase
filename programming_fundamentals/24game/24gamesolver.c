#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input(float numbers[],char expr[][100]) {
   float a;
   printf("Input 4 numbers between 1 and 10 (inclusive):\n");
   for (int i=0;i<4;i++) {
      scanf ("%f",&a);
      if ((a>=1) && (a<=10)) { 
         numbers[i] = a;
      } else {
         printf("Invalid input.\n");
         i--;
      }
   }

   for (int j=0;j<4;j++) {
      snprintf(expr[j],100,"%.0f",numbers[j]);
   }
}

int isEqual(float a,float b) {
   return (fabsf(a-b)<1e-6);
}

int isPossible(
   int length, float numbers[4],
   char expressions[4][100], char result[100]) {

      float newNumbers[4]; 
      char newExpressions[4][100];

      if (length == 1) {
         if (isEqual(numbers[0],24)) {
            snprintf(result,100,"%s",expressions[0]);
            return 1;
         } else {
            return 0;
         }
      }

      for (int i=0;i<length;i++) {
         for (int j=i+1;j<length;j++) {

            int index = 0;
            for (int k=0;k<length;k++) {
               if ((k!=i)&&(k!=j)) {
                  newNumbers[index] = numbers[k];
                  snprintf(newExpressions[index],100,"%s",expressions[k]);
                  index++;
               } 
            } 

            newNumbers[index] = numbers[i] + numbers[j]; 
            snprintf (
               newExpressions[index],100,
               "(%s + %s)",expressions[i],expressions[j]);

            if (isPossible(length-1,newNumbers,newExpressions,result)) {
               return 1;
            }

            newNumbers[index] = numbers[i] * numbers[j];
            snprintf (
               newExpressions[index],100,
               "(%s * %s)",expressions[i],expressions[j]);
            
            if (isPossible(length-1,newNumbers,newExpressions,result)) {
               return 1;
            }
            
            newNumbers[index] = numbers[i] - numbers[j];
            snprintf (
               newExpressions[index],100,
               "(%s - %s)",expressions[i],expressions[j]);

            if (isPossible(length-1,newNumbers,newExpressions,result)) {
               return 1;
            }

            newNumbers[index] = numbers[j] - numbers[i];
            snprintf (
               newExpressions[index],100,
               "(%s - %s)",expressions[j],expressions[i]);

            if (isPossible(length-1,newNumbers,newExpressions,result)) {
               return 1;
            }

            if (!isEqual(numbers[i],0)) {
               newNumbers[index] = numbers[j] / numbers[i];
               snprintf (
                  newExpressions[index],100,
                  "(%s / %s)",expressions[j],expressions[i]);
               
               if (isPossible(length-1,newNumbers,newExpressions,result)) {
                  return 1;
               }
            }

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
   float numbers[4];
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
