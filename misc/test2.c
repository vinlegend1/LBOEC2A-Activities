#include <time.h>
#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
   const char T[] = "2017.11.23 22:00";
   
   time_t result = 0;
   
   int year = 0, month = 0, day = 0, hour = 0, min = 0;
   
   if (sscanf(T, "%4d.%2d.%2d %2d:%2d", &year, &month, &day, &hour, &min) == 5) {
       struct tm breakdown = {0};
       breakdown.tm_year = year - 1900; /* years since 1900 */
       breakdown.tm_mon = month - 1;
       breakdown.tm_mday = day;
       breakdown.tm_hour = hour;
       breakdown.tm_min = min;
     
       if ((result = mktime(&breakdown)) == (time_t)-1) {
          fprintf(stderr, "Could not convert time input to time_t\n");
          return EXIT_FAILURE;
       }
        
       puts(ctime(&result));
       return EXIT_SUCCESS;
   }
   else {
      fprintf(stderr, "The input was not a valid time format\n");
      return EXIT_FAILURE;
   }
}
 
