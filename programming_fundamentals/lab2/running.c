/* file: running.c */
/* author: Harry (email: qilin2603379191@gmail.com)*/
/* date: 2025/9/22 */
/* version: 3.0.0 */
/* Description: 
   lab2_problem2 
   This program calculates how many times two objects pass each other when
   running in circles.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   int distance, speedA, speedB, time;
   int times, distanceA, distanceB,speedACopy;
   scanf("%d %d %d %d", &distance, &speedA, &speedB, &time); // input data
   speedACopy = speedA; //copy a speedA to save the original data for furthur using
   if (speedA >= speedB) {
      speedA = speedA - speedB;
      distanceA = speedA * time;
      times = distanceA / distance;
   } // We change the frame of reference to calculate the times A overtakes B
   if (speedB > speedACopy) {
      speedB = speedB - speedACopy;
      distanceB = speedB * time;
      times = distanceB / distance;
   } // Method is same as above when B is quicker than A
   printf("%d\n", times); // output times
   return 0;
}
