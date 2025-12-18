/* file    : q1.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/12/18 */
/* version : 1.0 */
/* Description:
 * 100% at once!!
 * highlight:
 * SafeMalloc function to allocate memory safely
 * Use getchar and isalpha to check alphabetic order
 * Accept the first letter only and use space checker doing so and think it out
 * by my own
 * Very short main
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void *safeMalloc(size_t length) {
   void *array = malloc(length);
   if (array == NULL) {
      printf("Error: malloc failed.\n");
      exit(EXIT_FAILURE);
   }
   return array;
}

int isAlphabetic(char *firstLetter) {
   int input = getchar();
   int index = 0;
   if (isalpha((unsigned char)input)) {
      firstLetter[index++] = tolower((unsigned char)input);
   }
   while (((input = getchar()) != EOF)&&(input!='\n')) {
      if (input == ' ') {
         input = getchar();
         if (isalpha((unsigned char)input)) {
            firstLetter[index] = tolower((unsigned char)input);
            if (firstLetter[index]<=firstLetter[index-1]) {
               return 0;
            }
            index++;
         }
      }
   }
   return 1;  
}

int main(int argc, char *argv[]) {
   
   char *firstLetter = safeMalloc(1000*sizeof(char));
   printf(isAlphabetic(firstLetter) ? "YES\n":"NO\n");
   free(firstLetter);
   
   return 0;
}