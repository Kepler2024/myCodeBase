/* file: intergerlogarithm.c */
/* author: KK (email: qilin2603379191@gmail.com)*/
/* date: 2025/9/16 */
/* version: 2.0 */
/* Description: tut2_2.3.4 */

#include <stdio.h>

int main(void){
    int n,b,m,bb;
    scanf ("%d %d",&n,&b);
    bb = b;
    for (m=0;b<=n;b=b*bb,m++);
    printf("%d\n",m);
    return 0;
}