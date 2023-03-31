#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include "dating.h"
#include "custom.h"

struct User {
  char *username;
  char *name;
  char *password;
  int ccLimit;
  float currentBalance;
  float debt;
  char *lastLogin;
};

typedef struct User User;

User newUser(char *username, char *name, char *password, int ccLimit,
             float currentBalance, float debt, char *lastLogin) {
  User user;
  user.username = username;
  user.name = name;
  user.password = password;
  user.ccLimit = ccLimit;
  user.currentBalance = currentBalance;
  user.debt = debt;
  user.lastLogin = lastLogin;
  return user;
}

float printWithdraw(float balance) {
  float amount;
  printf("How much do you want to withdraw? ");
  scanf("%f", &amount);
  if (balance < amount) {
    printf("The amount requested is more than current balance. As a result, "
           "only %.2f has been withdrawn\n",
           balance);
    return 0;
  }
  return balance - amount;
}

float printDeposit(float balance) {
  float amount;
  printf("How much money would you like to deposit? ");
  scanf("%f", &amount);
  return balance + amount;
}

int printApplyCC(float balance) {
  int ccLimit = floor((balance * DEBT_TO_BALANCE) / 100) * 100;
  return ccLimit;
}

int printUpgradeCC(float balance, int ccLimit) {
  int newLimit = floor((balance * DEBT_TO_BALANCE) / 100) * 100;
  if (newLimit > ccLimit) {
    printf("YOUR CREDIT LIMIT HAS INCREASED TO %d\n", newLimit);
    return newLimit;
  } else {
    printf("YOU ARE NOT ELIGIBLE FOR AN UPGRADE. DEPOSIT MORE MONEY TO GET A "
           "HIGHER CREDIT LIMIT.\n");
    return ccLimit;
  }
}

float printUseCC(int ccLimit, float debt, struct tm *dueDate,
                 struct tm currentTime) {
  if (debt >= ccLimit) {
    printf("You have currently maxed out your credit card and/or have undue "
           "payments. Please pay as soon as possible.\n");
    printf("Credit Card DENIED\n");
    return debt;
  }

  float amount;
  printf("How much money would you like to borrow with your credit card? ");
  scanf("%f", &amount);
  if (debt + amount >= ccLimit) {
    printf(
        "Bank X can only allow you to borrow %.2f. As such, your credit card "
        "has been DENIED\n",
        ccLimit - debt);
    return debt;
  } else {
    if (asctime(dueDate) == NULL) {
      *dueDate = addDay(currentTime, 30);
    }
    return debt + amount;
  }
}

float printPayDebt(float debt, struct tm *dueDate) {
  float amount;
  printf("How much do you want to pay? ");
  scanf("%f", &amount);
  if (debt < amount) {
    printf("The amount you paid is more than current paid. As a result, "
           "only %.2f has been returned to you as change.\n",
           amount - debt);
    dueDate = NULL;
    return 0;
  }
  if (debt - amount == 0) {
    dueDate = NULL;
  }
  return debt - amount;
}

void printHistory(char *username, struct tm *rawTime) {
  printLine();
  char line[MAX_LINE_LENGTH];
  char timeString[20];
  FILE *historyFile;
  char filepath[PATH_MAX] = HISTORY_PATH;

  strftime(timeString, 20, "%Y-%m-%d-%H-%M-%S", rawTime);

  strcat(filepath, timeString);
  strcat(filepath, "-");
  strcat(filepath, username);
  strcat(filepath, ".txt");
  historyFile = fopen(filepath, "r");

  printf("%-20s %-20s %-20s %-20s %-20s\n", "OPERATION", "AMOUNT",
         "ACCOUNT BALANCE", "OUTSTANDING DEBT", "DATE AND TIME");

  while (fgets(line, MAX_LINE_LENGTH, historyFile)) {
    char *token;
    token = strtok(line, ";");

    while (token != NULL) {
      printf("%-20s ", token);

      token = strtok(NULL, ";");
    }
    printf("\n");
  }

  fclose(historyFile);
}

void updateAndSaveData(User *ptr, int numOfUsers) {
  FILE *usersPtr;

  usersPtr = fopen(USERS_FILE, "w");
  if (usersPtr == NULL) {
    printf("Error!");
    exit(1);
  }

  for (int i = 0; i < numOfUsers; i++) {
    fprintf(usersPtr, "%s;%s;%s;%d;%.2f;%.2f;%s", (ptr + i)->username,
            (ptr + i)->name, (ptr + i)->password, (ptr + i)->ccLimit,
            (ptr + i)->currentBalance, (ptr + i)->debt, (ptr + i)->lastLogin);
  }

  fclose(usersPtr);
}

#endif // !DEBUG
