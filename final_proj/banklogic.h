#ifndef BANKLOGIC_H
#define BANKLOGIC_H

#include <math.h>
#include <limits.h>
#include "custom.h"
#include "dating.h"

char *getUsername(char *string) {
  int endIndex = 0;
  for (int i = 0; string[i] != 0; i++) {
    if (string[i] == ';') {
      endIndex = i;
      break;
    }
  }
  if (endIndex != 0) {
    return substr(string, 0, endIndex);
  } else {
    return "";
  }
}

char *getName(char *string) {
  int startIndex = 0;
  int endIndex = 0;
  int ind = 0;
  for (int i = 0; string[i] != 0; i++) {
    if (ind == 0 && string[i] == ';') {
      startIndex = i + 1;
      ind++;
    } else if (ind == 1 && string[i] == ';') {
      endIndex = i;
      break;
    }
  }
  if (endIndex != 0 || startIndex != 0) {
    return substr(string, startIndex, endIndex);
  } else {
    return "";
  }
}

char *getCCLimit(char *string) {
  int startIndex = 0;
  int endIndex = 0;
  int ind = 0;

  for (int i = 0; string[i] != 0; i++) {
    if (ind < 2 && string[i] == ';') {
      ind++;
    } else if (ind == 2 && string[i] == ';') {
      startIndex = i + 1;
      ind++;
    } else if (ind == 3 && string[i] == ';') {
      endIndex = i;
      break;
    }
  }
  if (endIndex != 0 || startIndex != 0) {
    return substr(string, startIndex, endIndex);
  } else {
    return "";
  }
}

char *getCurrentBalance(char *string) {
  int startIndex = 0;
  int endIndex = 0;
  int ind = 0;

  for (int i = 0; string[i] != 0; i++) {
    if (ind < 3 && string[i] == ';') {
      ind++;
    } else if (ind == 3 && string[i] == ';') {
      startIndex = i + 1;
      ind++;
    } else if (ind == 4 && string[i] == ';') {
      endIndex = i;
      break;
    }
  }
  if (endIndex != 0 || startIndex != 0) {
    return substr(string, startIndex, endIndex);
  } else {
    return "";
  }
}

char *getDebt(char *string) {
  int startIndex = 0;
  int endIndex = 0;
  int ind = 0;

  for (int i = 0; string[i] != 0; i++) {
    if (ind < 4 && string[i] == ';') {
      ind++;
    } else if (ind == 4 && string[i] == ';') {
      startIndex = i + 1;
      ind++;
    } else if (ind == 5 && string[i] == ';') {
      endIndex = i;
      break;
    }
  }
  if (endIndex != 0 || startIndex != 0) {
    return substr(string, startIndex, endIndex);
  } else {
    return "";
  }
}

char *getLastLogin(char *string) {
  int startIndex = 0;
  int endIndex = 0;
  int ind = 0;

  for (int i = 0; string[i] != 0; i++) {
    if (ind < 5 && string[i] == ';') {
      ind++;
    } else if (ind == 5 && string[i] == ';') {
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

char *getPassword(char *string) {
  int startIndex = 0;
  int endIndex = 0;
  int ind = 0;
  for (int i = 0; string[i] != 0; i++) {
    if (ind == 0 && string[i] == ';') {
      ind++;
    } else if (ind == 1 && string[i] == ';') {
      startIndex = i + 1;
      ind++;
    } else if (ind == 2 && string[i] == ';') {
      endIndex = i;
      break;
    }
  }
  if (endIndex != 0 || startIndex != 0) {
    return substr(string, startIndex, endIndex);
  } else {
    return "";
  }
}

void appendHistory(char *username, enum operation op, float amount,
                   float newBalance, float newDebt, struct tm *currentTime,
                   struct tm *rawTime) {
  char timeString[20];
  char filepath[PATH_MAX] = HISTORY_PATH;

  strftime(timeString, 20, "%Y-%m-%d-%H-%M-%S", rawTime);

  strcat(filepath, timeString);
  strcat(filepath, "-");
  strcat(filepath, username);
  strcat(filepath, ".txt");

  FILE *fptr = fopen(filepath, "a");
  if (fptr == NULL) {
    printf("SOMETHING WENT WRONG!");
    exit(1);
  }

  switch (op) {
  case WITHDRAW:
    fprintf(fptr, "%s;%.2f;%.2f;%.2f;%s", "WITHDRAW", amount, newBalance,
            newDebt, asctime(currentTime));
    break;
  case DEPOSIT:
    fprintf(fptr, "%s;%.2f;%.2f;%.2f;%s", "DEPOSIT", amount, newBalance,
            newDebt, asctime(currentTime));
    break;
  case BORROW:
    fprintf(fptr, "%s;%.2f;%.2f;%.2f;%s", "BORROW", amount, newBalance, newDebt,
            asctime(currentTime));
    break;
  case PAY_CC:
    fprintf(fptr, "%s;%.2f;%.2f;%.2f;%s", "PAY_CC", amount, newBalance, newDebt,
            asctime(currentTime));
    break;
  case DEBT_INT:
    fprintf(fptr, "%s;%.2f;%.2f;%.2f;%s", "DEBT_INT", amount, newBalance,
            newDebt, asctime(currentTime));
    break;
  case CREDIT_INT:
    fprintf(fptr, "%s;%.2f;%.2f;%.2f;%s", "CREDIT_INT", amount, newBalance,
            newDebt, asctime(currentTime));
    break;
  default:
    printf("SOMETHING WENT WRONG!\n");
  }

  fclose(fptr);
}


float creditInterest(float balance, int increment, char *username,
                     float newDebt, struct tm *currentTime, struct tm *latest,
                     struct tm *rawTime) {
  // latest, currentDate, rawTime.
  // increment... number of days we should add
  // prevRemainder = currentTime - latest
  // months = increment + prevRemainder / 30
  // if increment + prevRemainder >= 30:
  // for int i = 1; i <= months; i++:
  // if (prevRemainder > 0)
  // addHistory(amount, currentDate + 30 - prevRemainder)
  // prevRemainder = 0;
  // else:
  // addHistory(amount, currentDate + 30)
  //
  // add date(increment)

  int remainder = increment % 30;
  int prevRemainder = dayDiff(currentTime, latest);
  int months = floor((increment + prevRemainder) / 30);
  float compoundSum = balance;
  float amount;
  struct tm dateWLeftover = *currentTime;

  if (increment + prevRemainder >= 30) {
    for (int i = 1; i <= months; i++) {
      amount = compoundSum * DEPOSIT_APR / 12;
      compoundSum += amount;
      if (prevRemainder > 0) {
        dateWLeftover = addDay(dateWLeftover, 30 - prevRemainder);
        appendHistory(username, CREDIT_INT, amount, compoundSum, newDebt,
                      &dateWLeftover, rawTime);
        prevRemainder = 0;
      } else {
        dateWLeftover = addDay(dateWLeftover, 30);
        appendHistory(username, CREDIT_INT, amount, compoundSum, newDebt,
                      &dateWLeftover, rawTime);
      }
    }
  }

  return compoundSum;
}

float debtInterest(float debt, int days, char *username, float currentBalance,
                   struct tm *currentTime, struct tm *rawTime,
                   struct tm *paymentDue) {
  int diff = dayDiff(currentTime, paymentDue);
  float compoundSum = debt;
  float amount;
  struct tm dateWLeftover = *currentTime;
  int increment = days;
  if (diff + days > 0 && debt > 0) {
    if (diff < 0) {
      dateWLeftover = addDay(dateWLeftover, -diff);
      increment += diff;
    }
    for (int i = 0; i < increment; i++) {
      amount = compoundSum * CREDIT_APR / 365;
      compoundSum += amount;
      dateWLeftover = addDay(dateWLeftover, 1);
      appendHistory(username, DEBT_INT, amount, currentBalance, compoundSum,
                    &dateWLeftover, rawTime);
    }
  }

  return compoundSum;
}

#endif // !BANKLOGIC_H
