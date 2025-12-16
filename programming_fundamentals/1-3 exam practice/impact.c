/* file    : impact.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/10/10 */
/* version : 1.0 */
/* Description:
 * 70%
 */

#include <stdio.h>
#include <stdlib.h>

int count(int length, int arr[],int n) {
   int i=0,cnt=0;
   while (i < length) {
      if (arr[i] == n) {
         cnt++;
      } 
      i++;
   }
   return cnt;
}

long long impact(int length, int arr[], int n) {
   int impact;
   impact = n * count(length,arr,n);
   return impact;
}

void printNum(int length, int arr[]) {
   int i=0,j=0;
   while (j<length) {
      if (impact(length,arr,arr[i])>impact(length,arr,arr[j])) {
         j++;
      }
      if (impact(length,arr,arr[i])<impact(length,arr,arr[j])) {
         i=j;
         j++;
      }
      if (impact(length,arr,arr[i])==impact(length,arr,arr[j])) {
         i=(arr[i]<arr[j]?i:j);
         j++;
      }
   }
   printf("%d\n",arr[i]);
   
}

void inputNum(int length,int a[]) {
   int n,i=0;
   do {
      scanf("%d",&n);
      a[i] = n;
      i++;
   } while ((n!=0)&&(i<length));
   a[i+1]=0;
}

void printArr(int length,int a[]) {
   for (int i=0;i<length;i++) {
      printf(" %d",a[i]);
   }
   printf("\n");
}

int main(int argc, char *argv[]) {
   
   int a[5000] = {0};
   inputNum(5000,a);
   printNum(5000,a);

   return 0;
}
