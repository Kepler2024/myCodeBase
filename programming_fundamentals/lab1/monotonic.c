/* file: monotonic.c */
/* author: KK (email: qilin2603379191@gmail.com)*/
/* date: 2025/9/13 */
/* version: 2.0 */
/* Description: lab1_problem4 */

#include <stdio.h>

int main(void){
    int num,a,b,c;
    scanf("%d",&num);
    a = num / 100;
    b = (num/10) % 10;
    c = num % 10;
    if (a<b && b<c){
        printf("Increasing\n");
    }else if (a>b && b>c){
        printf("Decreasing\n");
    }else{
        printf("Neither\n");
    } 
}
