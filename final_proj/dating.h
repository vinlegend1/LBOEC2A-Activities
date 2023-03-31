#ifndef DATING_H
#define DATING_H

#include "custom.h"
#include <time.h>

int dayDiff(struct tm *newDay, struct tm *old) {
  int yearDiff = newDay->tm_year - old->tm_year;
  return 365 * yearDiff + (newDay->tm_yday - old->tm_yday);
}

struct tm getTime() {
  time_t currentTime = time(NULL);
  struct tm dateAndTime = *localtime(&currentTime);
  mktime(&dateAndTime);

  return dateAndTime;
}

struct tm stringToTime(char *string) {
  struct tm datetime = {0};
  time_t result = 0;
  char *weekday = substr(string, 0, 3);
  int day, hour, minute, second, year;
  char *month = substr(string, 4, 7);

  day = atoi(substr(string, 8, 10));
  hour = atoi(substr(string, 11, 13));
  minute = atoi(substr(string, 14, 16));
  second = atoi(substr(string, 17, 19));
  year = atoi(substr(string, 20, 24)) - 1900;

  if (strcmp(month, "Jan") == 0)
    datetime.tm_mon = 0;
  else if (strcmp(month, "Feb") == 0)
    datetime.tm_mon = 1;
  else if (strcmp(month, "Mar") == 0)
    datetime.tm_mon = 2;
  else if (strcmp(month, "Apr") == 0)
    datetime.tm_mon = 3;
  else if (strcmp(month, "May") == 0)
    datetime.tm_mon = 4;
  else if (strcmp(month, "Jun") == 0)
    datetime.tm_mon = 5;
  else if (strcmp(month, "Jul") == 0)
    datetime.tm_mon = 6;
  else if (strcmp(month, "Aug") == 0)
    datetime.tm_mon = 7;
  else if (strcmp(month, "Sep") == 0)
    datetime.tm_mon = 8;
  else if (strcmp(month, "Oct") == 0)
    datetime.tm_mon = 9;
  else if (strcmp(month, "Nov") == 0)
    datetime.tm_mon = 10;
  else if (strcmp(month, "Dec") == 0)
    datetime.tm_mon = 11;

  datetime.tm_mday = day;
  datetime.tm_hour = hour;
  datetime.tm_min = minute;
  datetime.tm_sec = second;
  datetime.tm_year = year;
  result = mktime(&datetime);

  return datetime;
}

struct tm addDay(struct tm t, int increment) {
  t.tm_mday += increment;
  mktime(&t);
  return t;
}

char *getDate(char *string) {
  int startIndex = 0;
  int endIndex = 0;
  int ind = 0;

  for (int i = 0; string[i] != 0; i++) {
    if (ind < 3 && string[i] == ';') {
      ind++;
    } else if (ind == 3 && string[i] == ';') {
      startIndex = i + 1;
      ind++;
    }
    endIndex++;
  }
  if (endIndex != 0 || startIndex != 0) {
    return substr(string, startIndex, endIndex);
  } else {
    return "";
  }
}

#endif // !DATING_H
