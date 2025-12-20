/* file    : q2.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/12/18 */
/* version : 1.0 */
/* Description:
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *safeMalloc(size_t length) {
   void *array = malloc(length);
   if (array == NULL) {
      printf("Error :malloc failed.\n");
      exit(EXIT_FAILURE);
   }
   return array;
}

void inputWord(char word[]) {
   scanf("\n");
   scanf("%s",word);
}

void inputKey(char key[], int keyLength,int length) {
   scanf("\n");
   scanf("%s",key);

   char *keyCopy = safeMalloc(length*sizeof(char));
   strcpy(keyCopy,key);
   while (strlen(key)<keyLength) {
      strcat(key,keyCopy);
   }
}

void print(int length, char a[]) {
   // print function to print the array
   for (int i=0;i<length;i++) {
      printf ("%c",a[i]);
   }
   printf ("\n");
}

int main(int argc, char *argv[]) {

   int wordLength;
   scanf("%d",&wordLength);
   int length;
   scanf("%d",&length);
   int keyLength = ((wordLength/length)+1)*length+1; 

   char *word = safeMalloc((wordLength+1)*sizeof(char));
   char *key = safeMalloc((keyLength+1)*sizeof(char));
   inputWord(word);
   inputKey(key,keyLength,length);

   print(12,word);
   print(12,key);

   return 0;
}