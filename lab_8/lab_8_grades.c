#include <stdio.h>
#include "grades.h"

int main() {
    int num = 3;
    float quizScores[num];
    float quizMaxScores[num];
    float reciteScores[num];
    float reciteMaxScores[num];
    float examScores[num];
    float examMaxScores[num];

    for (int i = 1; i <= num; i++) {
        printf("What's the student's quiz %d score? ", i);
        scanf("%f", &quizScores[i]);
        printf("What's the maximum score the student could've gotten in quiz %d? ", i);
        scanf("%f", &quizMaxScores[i]);
    }

    for (int i = 1; i <= num; i++) {
        printf("What's the student's recitation %d score? ", i);
        scanf("%f", &reciteScores[i]);
        printf("What's the maximum score the student could've gotten in recitation %d? ", i);
        scanf("%f", &reciteMaxScores[i]);
    }

    for (int i = 1; i <= num; i++) {
        printf("What's the student's long exam %d score? ", i);
        scanf("%f", &examScores[i]);
        printf("What's the maximum score the student could've gotten in long exam %d? ", i);
        scanf("%f", &examMaxScores[i]);
    }

    float quizTotal = total(quizScores, num);
    float reciteTotal = total(reciteScores, num);
    float examTotal = total(examScores, num);
    float quizMaxTotal = total(quizMaxScores, num);
    float reciteMaxTotal = total(reciteMaxScores, num);
    float examMaxTotal = total(examMaxScores, num);

    float qAvg = average(quizTotal, quizMaxTotal);
    float rAvg = average(reciteTotal, reciteMaxTotal);
    float eAvg = average(examTotal, examMaxTotal);

    float finalScore = getFinalScore(qAvg, rAvg, eAvg);
    char *finalRating = getFinalRating(finalScore);

    printf("Quiz Average: %.2f%%\n", qAvg);
    printf("Recitation Average: %.2f%%\n", rAvg);
    printf("Long Exam Average: %.2f%%\n", eAvg);
    printf("Final Score: %.2f%%\n", finalScore);
    printf("Final Rating: %s\n", finalRating);

    return 0;
}
