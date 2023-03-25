#include <stdio.h>
#include "calculations.h"

int main() {
  float q1, q2, q3;
  float q1Max, q2Max, q3Max;

  float r1, r2, r3;
  float r1Max, r2Max, r3Max;

  float l1, l2, l3;
  float l1Max, l2Max, l3Max;
  char ans;

  printf("Welcome to Grade Calculator!\n");
  do {
    printf("What is your quiz 1 score? ");
    scanf("%f", &q1);
    printf("What is the maximum possible score for quiz 1? ");
    scanf("%f", &q1Max);
    printf("What is your quiz 2 score? ");
    scanf("%f", &q2);
    printf("What is the maximum possible score for quiz 2? ");
    scanf("%f", &q2Max);
    printf("What is your quiz 3 score? ");
    scanf("%f", &q3);
    printf("What is the maximum possible score for quiz 3? ");
    scanf("%f", &q3Max);

    printf("What is your recitation 1 score? ");
    scanf("%f", &r1);
    printf("What is the maximum possible score for recitation 1? ");
    scanf("%f", &r1Max);
    printf("What is your recitation 2 score? ");
    scanf("%f", &r2);
    printf("What is the maximum possible score for recitation 2? ");
    scanf("%f", &r2Max);
    printf("What is your recitation 3 score? ");
    scanf("%f", &r3);
    printf("What is the maximum possible score for recitation 3? ");
    scanf("%f", &r3Max);

    printf("What is your long exam 1 score? ");
    scanf("%f", &l1);
    printf("What is the maximum possible score for long exam 1? ");
    scanf("%f", &l1Max);
    printf("What is your long exam 2 score? ");
    scanf("%f", &l2);
    printf("What is the maximum possible score for long exam 2? ");
    scanf("%f", &l2Max);
    printf("What is your long exam 3 score? ");
    scanf("%f", &l3);
    printf("What is the maximum possible score for long exam 3? ");
    scanf("%f", &l3Max);

    float qTotal = total(q1, q2, q3);
    float qMaxTotal = total(q1Max, q2Max, q3Max);
    float rTotal = total(r1, r2, r3);
    float rMaxTotal = total(r1Max, r2Max, r3Max);
    float lTotal = total(l1, l2, l3);
    float lMaxTotal = total(l1Max, l2Max, l3Max);

    float qAvg = average(qTotal, qMaxTotal);
    float rAvg = average(rTotal, rMaxTotal);
    float lAvg = average(lTotal, lMaxTotal);

    float finalScore = getFinalScore(qAvg, rAvg, lAvg);

    printf("Calculated values: \n");
    printf("Quiz 1 Quiz 2 Quiz 3 Quiz Total Quiz Avg ");
    printf("Recitation 1 Recitation 2 Recitation 3 Recitation Total Recitation "
           "Avg ");
    printf(
        "Long Exam 1 Long Exam 2 Long Exam 3 Long Exam Total Long Exam Avg ");
    printf("Final Rating Passed/Failed\n");

    printf("%-6.2f %-6.2f %-6.2f %-10.2f %-7.2f%% ", q1, q2, q3, qTotal, qAvg);
    printf("%-12.2f %-12.2f %-12.2f %-16.2f %-13.2f%% ", r1, r2, r3, rTotal,
           rAvg);
    printf("%-11.2f %-11.2f %-11.2f %-15.2f %-12.2f%% ", l1, l2, l3, lTotal,
           lAvg);
    printf("%-11.2f%% ", finalScore);
    finalRating(finalScore);
    printf("Quiz 1 Max Quiz 2 Max Quiz 3 Max         ");
    printf("Recitation 1 Max Recitation 2 Max Recitation 3 Max                 "
           "    ");
    printf(
        "Long Exam 1 Max Long Exam 2 Max Long Exam 3 Max                   \n");
    printf("%-10.2f %-10.2f %-10.2f         ", q1Max, q2Max, q3Max);
    printf("%-16.2f %-16.2f %-16.2f                     ", r1Max, r2Max, r3Max);
    printf("%-15.2f %-15.2f %-15.2f                   \n", l1Max, l2Max, l3Max);

    printf("Do you want to recalculate your grade (Y/n)? ");
    getchar();
    ans = getchar();
  } while (ans == 'y' || ans == 'Y');

  return 0;
}

