/* file     : kmeans1d.c */
/* author   : Harry (qilin2603379191@gmail.com) */
/* date     : 2025/10/20 */
/* version  : 1.1 */
/* Description:
 * Implement integer k-means clustering (1D version).
 */

#include <stdio.h>
#include <stdlib.h>

/* Function to return absolute value of an integer */
int absoluteValue(int number) {
   if (number < 0) {
      return -number;
   }
   return number;
}

int main(void) {
   int clusterCount;
   /* read the number of clusters */
   if (scanf("%d", &clusterCount) != 1) {
      return 0;
   }

   /* allocate arrays for centroids, updates, cluster sizes and sums */
   int *currentCentroids = (int *)malloc(clusterCount * sizeof(int));
   int *updatedCentroids = (int *)malloc(clusterCount * sizeof(int));
   int *clusterCounts = (int *)malloc(clusterCount * sizeof(int));
   int *clusterSums = (int *)malloc(clusterCount * sizeof(int));

   if (!currentCentroids || !updatedCentroids || !clusterCounts || !clusterSums) {
      return 0;
   }

   /* read initial centroids */
   for (int clusterIndex = 0; clusterIndex < clusterCount; clusterIndex++) {
      scanf("%d", &currentCentroids[clusterIndex]);
   }

   /* read data points (dynamic array with realloc if needed) */
   int *dataPoints = (int *)malloc(1100 * sizeof(int));
   int dataCapacity = 1100;
   int dataCount = 0;
   int inputValue;

   while (scanf("%d", &inputValue) == 1) {
      if (dataCount == dataCapacity) {
         dataCapacity *= 2;
         int *temporaryData = (int *)realloc(dataPoints, dataCapacity * sizeof(int));
         if (!temporaryData) {
            free(dataPoints);
            return 0;
         }
         dataPoints = temporaryData;
      }
      dataPoints[dataCount] = inputValue;
      dataCount++;
   }

   /* perform at most 1000 iterations */
   for (int iteration = 0; iteration < 1000; iteration++) {
      /* reset counts and sums for all clusters */
      for (int clusterIndex = 0; clusterIndex < clusterCount; clusterIndex++) {
         clusterCounts[clusterIndex] = 0;
      }
      for (int clusterIndex = 0; clusterIndex < clusterCount; clusterIndex++) {
         clusterSums[clusterIndex] = 0;
      }

      /* assign each point to nearest centroid */
      for (int pointIndex = 0; pointIndex < dataCount; pointIndex++) {
         int bestClusterIndex = 0;
         int bestDistance = absoluteValue(dataPoints[pointIndex] - currentCentroids[0]);

         for (int clusterIndex = 1; clusterIndex < clusterCount; clusterIndex++) {
            int currentDistance = absoluteValue(dataPoints[pointIndex] - currentCentroids[clusterIndex]);

            /* choose smaller distance, or break tie by smaller centroid value, then by smaller index */
            if (currentDistance < bestDistance) {
               bestDistance = currentDistance;
               bestClusterIndex = clusterIndex;
            } else if (currentDistance == bestDistance) {
               if (currentCentroids[clusterIndex] < currentCentroids[bestClusterIndex]) {
                  bestClusterIndex = clusterIndex;
               } else if (currentCentroids[clusterIndex] == currentCentroids[bestClusterIndex]) {
                  if (clusterIndex < bestClusterIndex) {
                     bestClusterIndex = clusterIndex;
                  }
               }
            }
         }

         /* add point to chosen cluster */
         clusterCounts[bestClusterIndex] += 1;
         clusterSums[bestClusterIndex] += dataPoints[pointIndex];
      }

      /* print current centroids and cluster sizes */
      for (int clusterIndex = 0; clusterIndex < clusterCount; clusterIndex++) {
         if (clusterIndex > 0) {
            printf(" ");
         }
         printf("%d(%d)", currentCentroids[clusterIndex], clusterCounts[clusterIndex]);
      }
      printf("\n");

      /* compute new centroids */
      for (int clusterIndex = 0; clusterIndex < clusterCount; clusterIndex++) {
         if (clusterCounts[clusterIndex] > 0) {
            updatedCentroids[clusterIndex] = clusterSums[clusterIndex] / clusterCounts[clusterIndex];
         } else {
            updatedCentroids[clusterIndex] = currentCentroids[clusterIndex];
         }
      }

      /* check if centroids unchanged */
      int centroidsUnchanged = 1;
      for (int clusterIndex = 0; clusterIndex < clusterCount; clusterIndex++) {
         if (updatedCentroids[clusterIndex] != currentCentroids[clusterIndex]) {
            centroidsUnchanged = 0;
            break;
         }
      }

      /* stop if no change */
      if (centroidsUnchanged) {
         break;
      }

      /* update centroids for next iteration */
      for (int clusterIndex = 0; clusterIndex < clusterCount; clusterIndex++) {
         currentCentroids[clusterIndex] = updatedCentroids[clusterIndex];
      }
   }

   /* free memory */
   free(dataPoints);
   free(currentCentroids);
   free(updatedCentroids);
   free(clusterCounts);
   free(clusterSums);

   return 0;
}