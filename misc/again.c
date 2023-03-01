#include <stdio.h>

int price, total = 0, buy = 0, Agapanthus = 55, Anemone = 40, Asters = 35,
           Carnation = 35, Chrysanthemum = 25, Cornflower = 30, Dahlias = 40,
           Daisy = 30, Delphinium = 45, Forget_me_not = 50, Gardenia = 50,
           Hellebore = 35, Lily = 45, Peony = 30, Rose = 40, num;
int aremain = 20, bremain = 20, cremain = 20, dremain = 20, eremain = 20,
    fremain = 20, gremain = 20, hremain = 20, iremain = 20, jremain = 20,
    kremain = 20, lremain = 20, mremain = 20, nremain = 20, oremain = 20;
char order, ans;

void lines(void) {
  printf("\n-------------------------------------------------------------");
}

void flower(int *quantity, int *num) {
  if (*quantity < *num) {
    *num = *quantity;
    *quantity = 0;
  } else {
    *quantity -= *num;
  }
}

int main() {
  printf("Hi, welcome to Flower World.\n");
  do {
    printf("Please see the following list that shows what kind of flowers "
           "available here.\n");

    lines();
    printf("\n\t1 --- Agapanthus             --- PHP55/plant(remain %d plants)",
           aremain);
    printf("\n\t2 --- Anemone                --- PHP40/plant(remain %d plants)",
           bremain);
    printf("\n\t3 --- Asters                 --- PHP35/plant(remain %d plants)",
           cremain);
    printf("\n\t4 --- Carnation              --- PHP35/plant(remain %d plants)",
           dremain);
    printf("\n\t5 --- Chrysanthemum          --- PHP25/plant(remain %d plants)",
           eremain);
    printf("\n\t6 --- Cornflower             --- PHP30/plant(remain %d plants)",
           fremain);
    printf("\n\t7 --- Dahlias                --- PHP40/plant(remain %d plants)",
           gremain);
    printf("\n\t8 --- Daisy                  --- PHP30/plant(remain %d plants)",
           hremain);
    printf("\n\t9 --- Delphinium             --- PHP45/plant(remain %d plants)",
           iremain);
    printf("\n\t10 --- Forget me not         --- PHP50/plant(remain %d plants)",
           jremain);
    printf("\n\t11 --- Gardenia              --- PHP50/plant(remain %d plants)",
           kremain);
    printf("\n\t12 --- Hellebore             --- PHP35/plant(remain %d plants)",
           lremain);
    printf("\n\t13 --- Lily                  --- PHP30/plant(remain %d plants)",
           mremain);
    printf("\n\t14 --- Peony                 --- PHP30/plant(remain %d plants)",
           nremain);
    printf("\n\t15 --- Rose                  --- PHP40/plant(remain %d plants)",
           oremain);

    lines();

    printf("\nPlease input the number of the flower you want to buy:  \n");
    scanf("%d", &order);

    switch (order) {
    case 1:
      printf("\nThe flower you are going to buy is Agapanthus, PHP55 per "
             "plant, remain %d plants.",
             aremain);
      price = Agapanthus;
      break;
    case 2:
      printf("\nThe flower you are going to buy is Anemone, PHP40 per plant, "
             "remain %d plants.",
             bremain);
      price = Anemone;
      break;
    case 3:
      printf("\nThe flower you are going to buy is Asters, PHP35 per plant, "
             "remain %d plants.",
             cremain);
      price = Asters;
      break;
    case 4:
      printf("\nThe flower you are going to buy is Carnation, PHP35 per plant, "
             "remain %d plants.",
             dremain);
      price = Carnation;
      break;
    case 5:
      printf("\nThe flower you are going to buy is Chrysanthemum, PHP25 per "
             "plant, remain %d plants.",
             eremain);
      price = Chrysanthemum;
      break;
    case 6:
      printf("\nThe flower you are going to buy is Cornflower, PHP30 per "
             "plant, remain %d plants.",
             fremain);
      price = Cornflower;
      break;
    case 7:
      printf("\nThe flower you are going to buy is Dahlias, PHP40 per plant, "
             "remain %d plants.",
             gremain);
      price = Dahlias;
      break;
    case 8:
      printf("\nThe flower you are going to buy is Daisy, PHP30 per plant, "
             "remain %d plants.",
             hremain);
      price = Daisy;
      break;
    case 9:
      printf("\nThe flower you are going to buy is Delphinium, PHP45 per "
             "plant, remain %d plants.",
             iremain);
      price = Delphinium;
      break;
    case 10:
      printf("\nThe flower you are going to buy is Forget me not, PHP50 per "
             "plant, remain %d plants.",
             jremain);
      price = Forget_me_not;
      break;
    case 11:
      printf("\nThe flower you are going to buy is Gardenia, PHP50 per plant, "
             "remain %d plants.",
             kremain);
      price = Gardenia;
      break;
    case 12:
      printf("\nThe flower you are going to buy is Hellebore, PHP35 per plant, "
             "remain %d plants.",
             lremain);
      price = Hellebore;
      break;
    case 13:
      printf("\nThe flower you are going to buy is Lily, PHP30 per plant, "
             "remain %d plants.",
             mremain);
      price = Lily;
      break;
    case 14:
      printf("\nThe flower you are going to buy is Peony, PHP30 per plant, "
             "remain %d plants.",
             nremain);
      price = Peony;
      break;
    case 15:
      printf("\nThe flower you are going to buy is Rose, PHP40 per plant, "
             "remain %d plants.",
             oremain);
      price = Rose;
      break;
    default:
      printf("\nSorry, it seems that you input a wrong number.");
    }
    lines();

    printf("\nPlease input the number of plant(s) you want: ");
    scanf("%d", &num);

    switch (order) {
    case 1:
      flower(&aremain, &num);
      break;
    case 2:
      flower(&bremain, &num);
      break;
    case 3:
      flower(&cremain, &num);
      break;
    case 4:
      flower(&dremain, &num);
      break;
    case 5:
      flower(&eremain, &num);
      break;
    case 6:
      flower(&fremain, &num);
      break;
    case 7:
      flower(&gremain, &num);
      break;
    case 8:
      flower(&hremain, &num);
      break;
    case 9:
      flower(&iremain, &num);
      break;
    case 10:
      flower(&jremain, &num);
      break;
    case 11:
      flower(&kremain, &num);
      break;
    case 12:
      flower(&lremain, &num);
      break;
    case 13:
      flower(&mremain, &num);
      break;
    case 14:
      flower(&nremain, &num);
      break;
    case 15:
      flower(&oremain, &num);
      break;
    default:
      printf("\nSorry, it seems that you input a wrong number.");
    }

    printf("Do you still like to buy other kinds of flowers before you "
           "bill?(please input 1 for yes and 2 for no): \n");
    scanf("%d", &ans);

    total = total + price * num;

  } while (ans == 1);

  printf("\nYour total billing is: %d.", total);

  return 0;
}
