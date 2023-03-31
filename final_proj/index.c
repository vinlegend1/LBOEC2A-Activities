#include "bankout.h"

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
