#ifndef BANKOUT_H
#define BANKOUT_H

#include "banklogic.h"
#include "custom.h"
#include "dating.h"
#include "user.h"

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

#endif // !BANKOUT_H
