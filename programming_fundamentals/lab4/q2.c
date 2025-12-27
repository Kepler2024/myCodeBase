/* file    : q2.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/12/18 */
/* version : 1.0 */
/* Description:
 * 100%
 * highlight:
 * very smart use of modular to generate key
 * very smar use of modular to avoid overflow
 * very simple but effective encrypt function
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
}// safely allocate memory avoiding lack of memory

void inputWord(char word[]) {
   scanf("\n");
   scanf("%s",word);
}// input function to read the word

void *getKey(char base[], int wordLength,int baseLength) {
   scanf("\n");
   scanf("%s",base);
   char *key = safeMalloc((wordLength+1)*sizeof(char));

   int index = 0;
   while (index < wordLength) {
      key[index] = base[index % baseLength]; // use modular to generate key
      index++;
   }
   key[wordLength] = '\0';
   return key; 
}

void encrypt(char key[],char word[],int wordLength) {
   int index = 0;
   while (index < wordLength) {
      word[index] = 'A'+((word[index]-'A' + (key[index]-'A'))%26);
      // avoid overflow using modular 26
      index++;
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
   int baseLength;
   scanf("%d",&baseLength);

   char *word = safeMalloc((wordLength+1)*sizeof(char));
   char *base = safeMalloc((baseLength+1)*sizeof(char));
   inputWord(word);
   char *key = getKey(base,wordLength,baseLength);

   print(wordLength,word);
   encrypt(key,word,wordLength);
   print(wordLength,word); 

   free(word);
   free(base);
   free(key);
   return 0;
}