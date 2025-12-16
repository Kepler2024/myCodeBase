/* file    : running2.c */
/* author  : Harry (qilin2603379191@gmail.com) */
/* date    : 2025/09/22 */
/* version : 1.0 */
/* Description:
 * This program computes some data when two objects running in a circle.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   int distance, speedA, speedB, positionA=0, positionB=0;
   int loopsA, loopsB, distanceOfFastest,time=0;
   scanf("%d %d %d",&distance,&speedA,&speedB); // input data
   positionA = (positionA + speedA) % distance;
   positionB = (positionB + speedB) % distance;  
      //calculate the positions one time to start the loop
   for (;!(positionA == 0 && positionB == 0);time++) {
      positionA = (positionA + speedA) % distance;
      positionB = (positionB + speedB) % distance;  
   }// simulate the movement of two objects
   time++; // add the time back from the beginning
   loopsA = (speedA * time) / distance;
   loopsB = (speedB * time) / distance; // calculate the numbers of the loops
   if (speedA <= speedB) {
      distanceOfFastest = speedB * time;
   } else {
      distanceOfFastest = speedA * time;
   } // decide which one is faster and calculate the distance
   printf ("%d %d %d\n",distanceOfFastest,loopsA,loopsB); //ouput data
   return 0;
}