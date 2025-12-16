/* file: parking.c */
/* author: KK (email: qilin2603379191@gmail.com)*/
/* date: 2025/9/18 */
/* version: 1.1 */
/* Description: lab2_problem1 */

#include <stdio.h>
int main(void){
    int HH,MM,D,hour,min,H,M,R;
    scanf("%d %d %d",&HH,&MM,&D);
    hour = D / 60;
    min = D % 60;
    H = HH + hour ;
    M = MM + min ;
    if (H > 24){
        H = H - 24;
    }
    if ((H >= 21) || (H <= 8 && M <=59)){
        if (H >= 21){
            R = H - 21;
            H = 8 + R;
        }else if (H <= 8){
            H = 8 + H;
        }
    if (H>=8 && HH <21){
        H = H + 11;
    }else if ((H>=8) && (HH >21 && HH <24)){
        H = H + (24-HH);
    }else if ((H>=8)&& (HH>0&&HH<=8)){
        H = H + HH;
    }else if ((H>=8)&& (HH>8)){
        H = H;
    }
    printf ("%d:%02d\n", H, M);

    return 0;
    }


   
    


}