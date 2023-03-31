#ifndef CUSTOM_H
#define CUSTOM_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEPOSIT_APR 0.06
#define CREDIT_APR 0.28
#define MAX_LINE_LENGTH 1000
#define USERS_FILE "users.txt"
#define TIME_FILE "time.txt"
#define HISTORY_PATH "history-"
#define DEBT_TO_BALANCE 0.2

#define USERNAME_LENGTH 21
#define PASSWORD_LENGTH 21
#define NAME_LENGTH 28

enum operation { WITHDRAW, DEPOSIT, BORROW, DEBT_INT, CREDIT_INT, PAY_CC };

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

void fgetsIgnored(char *string, int size) {
  fgets(string, size, stdin);
  string[strcspn(string, "\n")] = '\0';
}

void printLine() {
  printf("_____________________________________________________________________"
         "_______________________________\n");
}

#endif // !CUsTOM_H
