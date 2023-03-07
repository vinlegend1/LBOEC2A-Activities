#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *substr(const char *src, int m, int n) {
  int len = n - m;

  char *dest = (char *)malloc(sizeof(char) * (len + 1));

  for (int i = m; i < n && (*(src + i) != '\0'); i++) {
    *dest = *(src + i);
    dest++;
  }

  *dest = '\0';

  return dest - len;
}

int main() {
  struct tm t = stringToTime("Wed Apr 05 16:58:28 2023");
  if (asctime(&t) == NULL) {
    printf("NULL");
  } else {
    printf("Not Null");
  }
  return 0;
}
