/* file: parking3.c */
/* author: Harry (email: qilin2603379191@gmail.com)*/
/* date: 2025/9/19 */
/* version: 3.1.2 */
/* Description: 
   This program computes the expiration time of parking tickets.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   int hour, minute, purchasedTime;
   scanf("%d %d %d",&hour,&minute,&purchasedTime); // input
   if ((hour >= 21 || hour < 9) && (purchasedTime > 0)) { 
      hour = 8; 
      minute = 59; 
   }  // if time starts on free session, directly skip to 8:59
   while (purchasedTime) {
      if ((hour >= 9) && (hour < 21)) {
         purchasedTime--;
         minute++; // consume the purchased time minute by minute
         if (minute == 60) { 
            minute = 0;
            hour++;
         }
         if (hour == 24) {
            hour = 0;
         } // time calculation
      } else {
         hour = 8; 
         minute = 59; // skip to 8:59 if reaching free session
         purchasedTime--;                      
         minute++; // consume the purchased time as the same way above 
         if (minute == 60) { 
            minute = 0; 
            hour++; 
         }  
         if (hour == 24) { 
            hour = 0; 
         } // time calculation as the same way above
      }
   }
   if (hour >= 21 || hour < 9) {
      hour = 9;
      minute = 0; // final check in case the eventual time lands on free session
   }
   printf("%02d:%02d\n", hour, minute); // output
   return 0;
}