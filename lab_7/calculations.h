#ifndef CALCULATIONS_H
#define CALCULATIONS_H
#include <stdio.h>

float total(float num1, float num2, float num3) { return num1 + num2 + num3; }

float getFinalScore(float qAvg, float rAvg, float lAvg) {
  return 0.6 * lAvg + 0.2 * qAvg + 0.2 * rAvg;
}

void finalRating(float finalScore) {
  if (finalScore >= 70) {
    printf("PASSED\n");
  } else {
    printf("FAILED\n");
  }
}

float average(float scoreTotal, float maxTotal) {
  float result = scoreTotal / maxTotal;
  return result * 100;
}
#endif // !CALCULATIONS_H
