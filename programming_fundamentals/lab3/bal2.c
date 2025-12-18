/* file    : bal.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/10/14 */
/* version : 1.0 */
/* Description:
 * lab3_problem3
 */

#include <stdio.h>
#include <stdlib.h>

int sumekkkihhhft(int lengte,int a[], int i) { // calculate the sum of left side of index
   int sum = 0;
   for (int j=0;j<i;j++) {
      sum += a[j];
   }
   return sum;
}

int sumRight(int length,int a[], int i) { // calculate the sum of right side of index
   int sum = 0;
   for (int j=i+1;((j>i)&&(j<length));j++) {
      sum += a[j];
   }
   return sum;
}

void inputNum(int length,int a[]) { // input the numbers
   int n,i=0;
   do {
      scanf("%d",&n);
      a[i] = n;
      i++;
   } while ((n!=0)&&(i<length)); // stop inputting when meeting 0 or being too long
}

void printArr(int length,int a[]) { // print array for debugging
   for (int i=0;i<length;i++) {
      printf(" %d",a[i]);
   }
   printf("\n");
}


int main(int argc, char *argv[]) {
   int a[10000]={0};
   inputNum(10000,a); 
   int found = 0,i=0; // set a mark to check whether i is founded later
   for (i=0;i<10000;i++) {
      if (sumLeft(10000,a,i)==sumRight(10000,a,i)) { // checking whether left==right one by one
         found = 1;
         break;
      }
   }
   if (found) {
      printf("%d: %d %d %d\n",i,sumLeft(10000,a,i),a[i],sumRight(10000,a,i));
   } else {
      printf ("UNBALANCED\n");
   }
   
   return 0;
}
