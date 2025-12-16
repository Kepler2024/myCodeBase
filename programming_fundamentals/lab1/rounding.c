/* file: divisors.c */
/* author: KK (email: qilin2603379191@gmail.com)*/
/* date: 2025/9/16 */
/* version: 1.1 */
/* Description: tut2_2.3.2 */

#include <stdio.h>

int main(void){
    int num,a;
    scanf ("%d",&num);
    for (a = 1;(num>0) && (a<=num);a++)
        if (num % a == 0){
            printf("%d\n",a);
        }
return 0;
}
