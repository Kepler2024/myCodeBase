/* file    : cro.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/10/15 */
/* version : 1.0 */
/* Description:
 * 
 */

#include <stdio.h>
#include <stdlib.h>

void inputNum(int length,int a[]) { // input the numbers
   int n,i=0;
   do {
      scanf("%d",&n);
      a[i] = n;
      i++;
   } while ((n!=0)&&(i<length)); // stop inputting when meeting 0 or being too long
}

void printArr(int length,int a[]) { 
   int first = 1;
   printf("[");
   for (int i=0;i<length;i++) {
      if ((first)&&(a[i]!=0)) {
         printf("%d",a[i]);
         first = 0;
      } else if ((!first)&&(a[i]!=0)){
         printf(",%d",a[i]);
      }
   }
   printf("]\n");
}

int isMultiple(int a,int b) {
   if (b%a==0) {
      return 1;
   } else {
      return 0;
   }
}

void filter(int length,int a[]) {
   int j,k,i=0;
   int over = 0;
   int found=0;
   while (!over) {
      for (j=i+1;(j<length);j++) {
         if (isMultiple(a[i],a[j])) {
            a[j] = 0;
         }
      } // change all multiple to 0
      for (k=i+1,found=0;(k<length);k++) {
         if (a[k]!=0) {
            i = k;
            found = 1;
            break;
         } 
      } // finding next target
      if (!found) {
         over = 1;
      }
   }


}

int main(int argc, char *argv[]) {
   int a[100000] = {0};
   inputNum (100000,a);
   filter(100000,a);
   printArr(100000,a);
   return 0;
}