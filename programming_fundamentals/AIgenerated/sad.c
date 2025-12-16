/* file     : saddle_points.c */
/* author   : Harry (qilin2603379191@gmail.com) */
/* date     : 2025/10/15 */
/* version  : 1.1 */
/* Description:
 * Count saddle points in an n×m matrix of non-negative integers.
 * A cell (r,c) is a saddle point if:
 *   (H-max  && V-min)  OR  (H-min && V-max),
 * where H-? compares only left/right neighbors that exist,
 * and V-? compares only up/down neighbors that exist.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int rows;
   int cols;
   int **a;       /* a[rows][cols] */
} Matrix;

Matrix makeMatrix(int rows, int cols) {
   Matrix mat;
   mat.rows = rows;
   mat.cols = cols;
   mat.a = (int **)malloc(rows * sizeof(int *));
   for (int r = 0; r < rows; r++) {
      mat.a[r] = (int *)malloc(cols * sizeof(int));
   }
   return mat;
}

void freeMatrix(Matrix *mat) {
   for (int r = 0; r < mat->rows; r++) {
      free(mat->a[r]);
   }
   free(mat->a);
}

/* Check horizontal local max/min using only existing neighbors. */
void horizontalExtrema(const Matrix *mat, int r, int c,
                       int *isHMax, int *isHMin) {
   int val = mat->a[r][c];
   int hMax = 1, hMin = 1;

   /* left neighbor */
   if (c - 1 >= 0) {
      if (val <= mat->a[r][c - 1]) hMax = 0;
      if (val >= mat->a[r][c - 1]) hMin = 0;
   }
   /* right neighbor */
   if (c + 1 < mat->cols) {
      if (val <= mat->a[r][c + 1]) hMax = 0;
      if (val >= mat->a[r][c + 1]) hMin = 0;
   }

   *isHMax = hMax;
   *isHMin = hMin;
}

/* Check vertical local max/min using only existing neighbors. */
void verticalExtrema(const Matrix *mat, int r, int c,
                     int *isVMax, int *isVMin) {
   int val = mat->a[r][c];
   int vMax = 1, vMin = 1;

   /* up neighbor */
   if (r - 1 >= 0) {
      if (val <= mat->a[r - 1][c]) vMax = 0;
      if (val >= mat->a[r - 1][c]) vMin = 0;
   }
   /* down neighbor */
   if (r + 1 < mat->rows) {
      if (val <= mat->a[r + 1][c]) vMax = 0;
      if (val >= mat->a[r + 1][c]) vMin = 0;
   }

   *isVMax = vMax;
   *isVMin = vMin;
}

int main(void) {
   int n, m;
   if (scanf("%d %d", &n, &m) != 2) {
      return 0;
   }

   Matrix mat = makeMatrix(n, m);
   for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
         scanf("%d", &mat.a[r][c]);
      }
   }

   int count = 0;
   for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
         int isHMax, isHMin, isVMax, isVMin;
         horizontalExtrema(&mat, r, c, &isHMax, &isHMin);
         verticalExtrema(&mat, r, c, &isVMax, &isVMin);

         if ((isHMax && isVMin) || (isHMin && isVMax)) {
            count++;
         }
      }
   }

   printf("%d\n", count);

   freeMatrix(&mat);
   return 0;
}