#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
enum operation { WITHDRAW, DEPOSIT, BORROW, DEBT_INT, CREDIT_INT, PAY_CC };

struct tm getTime() {
  time_t currentTime = time(NULL);
  struct tm dateAndTime = *localtime(&currentTime);
  mktime(&dateAndTime);

  return dateAndTime;
}

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

void printLine() {
  printf("_____________________________________________________________________"
         "_______________________________\n");
}

void printWelcomeScreen(int *afterWelcome) {
  printLine();
  printf("Welcome to Bank X!\n");
  printf("Would you like to do one of the following:\n");
  printf("(1) REGISTER a new bank account with Bank X?\n");
  printf("(2) LOGIN to an existing bank account with Bank X?\n");
  printf("(3) Exit Bank X\n");
  printf("Select the number corresponding to your selection choice: ");
  scanf("%d", afterWelcome);
}

void printThankYouScreen() { printf("THANK YOU FOR CHOOSING Bank X\n"); }

void fgetsIgnored(char *string, int size) {
  fgets(string, size, stdin);
  string[strcspn(string, "\n")] = '\0';
}

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

void printRegisterScreen() {
  char name[NAME_LENGTH], password[PASSWORD_LENGTH], username[USERNAME_LENGTH];
  float initBalance;
  char line[MAX_LINE_LENGTH];

  printLine();
  printf("Welcome to Bank X Registration Page\n");
  printf("What is your name? ");
  getchar();
  fgetsIgnored(name, NAME_LENGTH);
  printf("What is your username (Think of one, maximum 14 characters)? ");
  fgetsIgnored(username, USERNAME_LENGTH);
  printf("What will be the password the your bank account? ");
  fgetsIgnored(password, PASSWORD_LENGTH);
  printf("What will be your initial deposit to the bank account (minimum of "
         "Php20,000)? ");
  scanf("%f", &initBalance);

  if (initBalance < 20000.0) {
    printf("YOUR REGISTER IS INVALID BECAUSE OF LACK OF INITIAL DEPOSIT.");
    return;
  }

  FILE *userFile;
  userFile = fopen(USERS_FILE, "a+");

  if (userFile == NULL) {
    printf("SOMETHING WENT WRONG!");
    exit(1);
  }
  while (fgets(line, MAX_LINE_LENGTH, userFile)) {
    char *lineUsername = getUsername(line);
    if (strcmp(username, lineUsername) == 0) {
      printf("USERNAME ALREADY EXISTS! YOU WILL BE REDIRECTED BACK TO THE "
             "LOGIN PAGE! PLEASE LOGIN INSTEAD OF REGISTERING. THANK YOU.\n");
      return;
    }
  }

  fprintf(userFile, "%s;%s;%s;%d;%.2f;%.2f;none\n", username, name, password, 0,
          initBalance, 0.0);
  fclose(userFile);
  printf("SUCCESSFULLY SAVED USER TO DATABASE! YOU MAY NOW LOGIN! YOU WILL BE "
         "REDIRECTED TO THE LOGIN PAGE!\n");
  printThankYouScreen();
}

User printLoginScreen(User *ptr, int *arrayLen) {
  char username[USERNAME_LENGTH], password[PASSWORD_LENGTH];
  char line[MAX_LINE_LENGTH];
  char ans;
  User loggedInUser;
  int login = 0;
  struct tm dateToday = getTime();

  do {
    printf("Login to your bank account:\n");
    printf("What is your username? ");
    getchar();
    fgetsIgnored(username, USERNAME_LENGTH);

    printf("What is your password? ");
    fgetsIgnored(password, PASSWORD_LENGTH);

    FILE *userFile;
    userFile = fopen(USERS_FILE, "r");

    if (userFile == NULL) {
      exit(1);
    }

    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, userFile)) {
      char *tempUsername = getUsername(line);
      char *tempPassword = getPassword(line);
      char *name = getName(line);
      char *ccLimit = getCCLimit(line);
      char *debt = getDebt(line);
      char *balance = getCurrentBalance(line);
      char *lastLogin = getLastLogin(line);

      (ptr + i)->username = tempUsername;
      (ptr + i)->password = tempPassword;
      (ptr + i)->name = name;
      (ptr + i)->ccLimit = atoi(ccLimit);
      (ptr + i)->debt = atof(debt);
      (ptr + i)->currentBalance = atof(balance);

      if (strcmp(lastLogin, "none") == 0) {
        (ptr + i)->lastLogin = asctime(&dateToday);
      } else {
        (ptr + i)->lastLogin = lastLogin;
      }

      if (strcmp(username, tempUsername) == 0 &&
          strcmp(password, tempPassword) == 0) {
        loggedInUser = newUser(tempUsername, name, tempPassword, atoi(ccLimit),
                               atof(balance), atof(debt), (ptr + i)->lastLogin);
        login = 1;
      }
      i++;
    }

    if (login == 1) {
      *arrayLen = i;
      fclose(userFile);
      return loggedInUser;
    }

    fclose(userFile);
    printf("USERNAME OR PASSWORD IS WRONG\n");
    printf("DO YOU WANT TO RETRY (y/n)? ");
    ans = getchar();
  } while (ans == 'Y' || ans == 'y');

  return newUser("", "", "", 0, 0, 0, "");
}

void printWrongInputScreen() {
  printLine();
  printf("SORRY YOU HAVE MADE AN INVALID INPUT\n");
}

void printBankChoices(int *ans, User *currentUser, struct tm *date) {
  printLine();

  printf("Welcome %s! We hope you're having a wonderful day!\n",
         currentUser->name);
  printf("Your username: %s \n", currentUser->username);
  printf("Your current balance: %.2f\n", currentUser->currentBalance);
  printf("Your current credit card limit: %d\n", currentUser->ccLimit);
  printf("Your current credit card debt: %.2f\n", currentUser->debt);
  printf("Current Date and Time: %s\n", asctime(date));
  printf("Last Login Date and Time: %s\n", currentUser->lastLogin);

  printf("What would you like to do?\n");
  printf("(1) Withdraw Money\n");
  printf("(2) Deposit Money\n");
  printf("(3) Apply for Credit Card\n");
  printf("(4) Apply for Credit Card Upgrade\n");
  printf("(5) Use Credit Card\n");
  printf("(6) Pay off Credit Card Debt\n");
  printf("(7) Print Bank Statement / History\n");
  printf("(8) Fast Forward Time\n");
  printf("(9) Exit Bank X\n");

  printf("Select the number corresponding to your choice: ");
  scanf("%d", ans);
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

int dayDiff(struct tm *new, struct tm *old) {
  int yearDiff = new->tm_year - old->tm_year;
  return 365 * yearDiff + (new->tm_yday - old->tm_yday);
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

void printFastForward(struct tm *date, float *balance, char *username,
                      float *debt, struct tm *rawTime, struct tm *dueDate) {
  int increment;
  printf("How many days do you want to fast forward? ");
  scanf("%d", &increment);
  printf("...Fast forwarding %d days...\n", increment);

  char line[MAX_LINE_LENGTH];
  char timeString[20];
  FILE *historyFile;
  char filepath[PATH_MAX] = HISTORY_PATH;
  struct tm latest = *rawTime;

  strftime(timeString, 20, "%Y-%m-%d-%H-%M-%S", rawTime);

  strcat(filepath, timeString);
  strcat(filepath, "-");
  strcat(filepath, username);
  strcat(filepath, ".txt");
  historyFile = fopen(filepath, "r");

  if (historyFile != NULL) {
    while (fgets(line, MAX_LINE_LENGTH, historyFile)) {
      char *strdate = getDate(line);
      char *operation = strtok(line, ";");
      if (strcmp(operation, "CREDIT_INT") == 0) {
        latest = stringToTime(strdate);
      }
    }
  }

  fclose(historyFile);

  if (asctime(&latest) == NULL) {
    *balance = creditInterest(*balance, increment, username, *debt, date,
                              &latest, rawTime);
  } else {
    *balance = creditInterest(*balance, increment, username, *debt, date,
                              &latest, rawTime);
  }
  if (asctime(dueDate) != NULL) {
    *debt = debtInterest(*debt, increment, username, *balance, date, rawTime,
                         dueDate);
  }
  *date = addDay(*date, increment);
}

void printBankScreen(User *currentUser, struct tm *date, struct tm *rawTime) {
  int ans;
  int retry = 1;
  struct tm dueDate;

  do {
    printBankChoices(&ans, currentUser, date);
    float temp;
    switch (ans) {
    case 1:
      temp = currentUser->currentBalance;
      currentUser->currentBalance = printWithdraw(currentUser->currentBalance);
      appendHistory(
          currentUser->username, WITHDRAW, temp - currentUser->currentBalance,
          currentUser->currentBalance, currentUser->debt, date, rawTime);
      break;
    case 2:
      temp = currentUser->currentBalance;
      currentUser->currentBalance = printDeposit(currentUser->currentBalance);
      appendHistory(
          currentUser->username, DEPOSIT, currentUser->currentBalance - temp,
          currentUser->currentBalance, currentUser->debt, date, rawTime);
      break;
    case 3:
      currentUser->ccLimit = printApplyCC(currentUser->currentBalance);
      break;
    case 4:
      currentUser->ccLimit =
          printUpgradeCC(currentUser->currentBalance, currentUser->ccLimit);
      break;
    case 5:
      temp = currentUser->debt;
      currentUser->debt =
          printUseCC(currentUser->ccLimit, currentUser->debt, &dueDate, *date);
      appendHistory(currentUser->username, BORROW, currentUser->debt - temp,
                    currentUser->currentBalance, currentUser->debt, date,
                    rawTime);
      break;
    case 6:
      temp = currentUser->debt;
      currentUser->debt = printPayDebt(currentUser->debt, &dueDate);
      appendHistory(currentUser->username, PAY_CC, temp - currentUser->debt,
                    currentUser->currentBalance, currentUser->debt, date,
                    rawTime);
      break;
    case 7:
      printHistory(currentUser->username, rawTime);
      break;
    case 8:
      printFastForward(date, &currentUser->currentBalance,
                       currentUser->username, &currentUser->debt, rawTime,
                       &dueDate);
      break;
    case 9:
      retry = 0;
      break;
    default:
      printWrongInputScreen();
      printBankChoices(&ans, currentUser, date);
    }
  } while (retry != 0);
}

int main() {
  int afterWelcome;
  int retry = 0;
  User currentUser;

  User users[1000];
  User *usersPtr;
  usersPtr = users;
  int numOfUsers;

  struct tm date = getTime();
  struct tm rawTime = getTime();

  printWelcomeScreen(&afterWelcome);
  do {
    switch (afterWelcome) {
    case 1:
      printRegisterScreen();
      retry = 1;
      afterWelcome = 2;
      break;
    case 2:
      currentUser = printLoginScreen(usersPtr, &numOfUsers);
      retry = 0;
      break;
    case 3:
      printThankYouScreen();
      exit(1);
      break;
    default:
      printWrongInputScreen();
      retry = 1;
      printWelcomeScreen(&afterWelcome);
    }
  } while (retry != 0);

  if (strcmp(currentUser.username, "") != 0) {
    printBankScreen(&currentUser, &date, &rawTime);
    for (int i = 0; i < numOfUsers; i++) {
      if (strcmp((usersPtr + i)->username, currentUser.username) == 0) {
        (usersPtr + i)->currentBalance = currentUser.currentBalance;
        (usersPtr + i)->debt = currentUser.debt;
        (usersPtr + i)->ccLimit = currentUser.ccLimit;
        (usersPtr + i)->lastLogin = asctime(&rawTime);
        break;
      }
    }
    updateAndSaveData(usersPtr, numOfUsers);
  }
  printThankYouScreen();

  return 0;
}
