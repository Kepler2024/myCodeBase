/* file    : inverse.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/09/22 */
/* version : 2.0.0 */
/* Description:
 * this program takes two positive integers x and n and output the smallest
 * number such that (x*y)%n == 1.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   int integerX,integerN;
   scanf("%d %d",&integerX,&integerN); //input numbers
   int found = 0;
   //set a sign to indicate whether y is found,1 means y found and 0 means unfound
    integerX %= integerN; // avoid overflow
    for (int y = 1; y < integerN; y++) { // loop to find the smallest integer y
        if ((long long)(integerX * y) % integerN == 1) {
            printf("%d\n", y);//output y immediately after finding it
            found = 1;
            break;// end the loop after finding y
        } 
    }
    if (!found) {
        printf("0\n"); // output 0 if y is not found
    }
   return 0;
}