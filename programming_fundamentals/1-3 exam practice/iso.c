/* file    : iso.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/10/10 */
/* version : 1.0 */
/* Description:
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void inputChar(int length,char a[]) {
   int i=0;
   char n;
   do {
      scanf("%c",&n);
      if((isalpha(n))||(n=='.')||(n==' ')) {
      a[i] = n;
      i++;
   }
   } while ((n!='.')&&(i<length));
   
   int j=0;
   while (j<length) {
      a[j] = tolower(a[j]);
      j++;
   }
}

void printArr(int length,char a[],int start) {
   for (int i=start;i<length;i++) {
      printf("%c",a[i]);
   }
}

int isIso(int histogram[]) {
   for (int i=0;i<26;i++) {
      if (histogram[i] > 1){
      return 0;
      }
   }
   return 1;
}

void initialize(int histogram[]) {
   for (int i=0;i<26;i++) {
      histogram[i] = 0;
   }
}

void printIso(int length,char a[]) {
   int histogram[26];
   initialize(histogram);
   int start=0;
   int first=1;
   for (int j=0;j<length;j++) {
      if (a[j]==' ') {
         if (isIso(histogram)) {
            if (!first) {printf(" ");}
            printArr(j,a,start);
            first = 0;
            start = j+1;
            initialize(histogram);
            continue;
         } else {
            start = j+1;
            initialize(histogram);
            continue;
         }
      }
      if (a[j]=='.') {
         if (isIso(histogram)) {
            if (!first) {printf(" ");}
            printArr(j,a,start);
            printf("\n");
            break;
         } else {
            printf("\n");
            break;
         }
      }
      histogram[a[j]-'a']++;
   }

}

int main(int argc, char *argv[]) {
   char a[300]={0};
   inputChar(300,a);
   printIso(300,a);
   return 0;
}
