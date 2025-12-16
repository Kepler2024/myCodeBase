/* file: arithmetic.c */
/* author: KK (email: qilin2603379191@gmail.com)*/
/* date: 2025/9/13 */
/* version: 1.0 */
/* Description: lab1_problem5 */

#include <stdio.h>

int main(void){
    int num,a,b,c,m,n;
    scanf("%d",&num);
    a = num / 100;
    b = (num/10) % 10;
    c = num % 10;
    if (a>=b){
        m = a - b;
    }else if (a<b){
        m = b - a;
    }
    if (b>=c){
        n = b - c;
    }else if (b<c){
        n = c - b;
    }
    if (m==n){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
}
