#ifndef GRADES_H
#define GRADES_H

float total(float *scores, int length) {
  float sum = 0;
  for (int i = 1; i <= length; i++) {
    sum += *(scores + i);
  }
  return sum;
}

float getFinalScore(float qAvg, float rAvg, float lAvg) {
  return 0.6 * lAvg + 0.2 * qAvg + 0.2 * rAvg;
}

char *getFinalRating(float finalScore) {
  if (finalScore >= 70) {
    return "PASSED";
  } else {
    return "FAILED";
  }
}

float average(float scoreTotal, float maxTotal) {
  float result = scoreTotal / maxTotal;
  return result * 100;
}
#endif // !GRADES_H
