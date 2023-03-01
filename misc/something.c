#include <stdio.h>

void something(int *var, int *quantity);

int main() {
  int noodle = 10;
  int quantity = 1;
  printf("before\n");
  printf("%d\n", noodle);
  printf("%d\n", quantity);
  something(&noodle, &quantity);
  printf("after\n");
  printf("%d\n", noodle);
  printf("%d", quantity);
  return 0;
}

void something(int *var, int *quantity) {
    *var += *quantity;
    *quantity = 0;
}
