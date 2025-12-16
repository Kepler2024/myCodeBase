/* file: colinear.c */
/* author: KK (email: qilin2603379191@gmail.com)*/
/* date: 2025/9/13 */
/* version: 1.2 */
/* Description: lab1_problem3 */

#include <stdio.h>
#include <math.h>

int main(void){
    int x1,y1,x2,y2,x3,y3;
    float k,b;
    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
    if (x1 == x2 && x1 == x3){
        printf ("YES\n");
    }else if (x1 == x2 && x1 != x3){
            printf ("NO\n");
    }else{
        k = (float)(y2 - y1)/(x2 - x1);
        b = y1 - k * x1;
        if (fabsf(k * x3 + b - y3) < 1e-6){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
