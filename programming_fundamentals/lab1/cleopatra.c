/* file: cleopatra.c */
/* author: Harry (email: qilin2603379191@gmail.com)*/
/* date: 2025/9/13 */
/* version: 1.4 */
/* Description: lab1_problem2 */

#include <stdio.h>

int main(){
    int need,carton;
    scanf("%d", &need);
    need = need * 1000;
    if (need%650==0){
    carton = (need)/650;
    } else {
         carton = (need)/650+1;
    }
    printf("%d\n",carton);
    return 0;
}