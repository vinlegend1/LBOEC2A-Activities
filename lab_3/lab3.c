#include <stdio.h>

int main() {
    char answer;
    do {
        float q1, q2, q3, r1, r2, r3, l1, l2, l3;
        float q1_max, q2_max, q3_max, r1_max, r2_max, r3_max, l1_max, l2_max, l3_max;
        char name[20];

        printf("What's the student's name? ");
        scanf("%s", name);

        printf("What's the student's quiz 1 score? ");
        scanf("%f", &q1);

        printf("What's the student's quiz 1 maximum score? ");
        scanf("%f", &q1_max);

        printf("What's the student's quiz 2 score? ");
        scanf("%f", &q2);

        printf("What's the student's quiz 2 maximum score? ");
        scanf("%f", &q2_max);

        printf("What's the student's quiz 3 score? ");
        scanf("%f", &q3);

        printf("What's the student's quiz 3 maximum score? ");
        scanf("%f", &q3_max);

        printf("What's the student's recitation 1 score? ");
        scanf("%f", &r1);

        printf("What's the student's recitation 1 maximum score? ");
        scanf("%f", &r1_max);

        printf("What's the student's recitation 2 score? ");
        scanf("%f", &r2);

        printf("What's the student's recitation 2 maximum score? ");
        scanf("%f", &r2_max);

        printf("What's the student's recitation 3 score? ");
        scanf("%f", &r3);

        printf("What's the student's recitation 3 maximum score? ");
        scanf("%f", &r3_max);

        printf("What's the student's long exam 1 score? ");
        scanf("%f", &l1);

        printf("What's the student's long exam 1 maximum score? ");
        scanf("%f", &l1_max);

        printf("What's the student's long exam 2 score? ");
        scanf("%f", &l2);

        printf("What's the student's long exam 2 maximum score? ");
        scanf("%f", &l2_max);

        printf("What's the student's long exam 3 score? ");
        scanf("%f", &l3);

        printf("What's the student's long exam 3 maximum score? ");
        scanf("%f", &l3_max);

        float qTotal = q1 + q2 + q3;
        float rTotal = r1 + r2 + r3;
        float lTotal = l1 + l2 + l3;

        float qMaxTotal = q1_max + q2_max + q3_max;
        float rMaxTotal = r1_max + r2_max + r3_max;
        float lMaxTotal = l1_max + l2_max + l3_max;

        float qPercent = 100 * (qTotal) / qMaxTotal;
        float rPercent = 100 * (rTotal) / rMaxTotal;
        float lPercent = 100 * (lTotal) / lMaxTotal;

        float finalGrade = 0.6 * lPercent + 0.2 * qPercent + 0.2 * rPercent;

        printf("%-20s %-6s %-6s %-6s %-10s %-8s ", "Name", "Quiz 1", "Quiz 2", "Quiz 3", "Quiz Total", "Quiz Avg");
        printf("%-12s %-12s %-12s %-16s %-14s ", "Recitation 1", "Recitation 2", "Recitation 3", "Recitation Total", "Recitation Avg");
        printf("%-11s %-11s %-11s %-15s %-13s ", "Long Exam 1", "Long Exam 2", "Long Exam 3", "Long Exam Total", "Long Exam Avg");
        printf("%-11s\n", "Final Grade");
        printf("%-20s %-6.1f %-6.1f %-6.1f %-10.1f %-8.1f ", name, q1, q2, q3, qTotal, qPercent);
        printf("%-12.1f %-12.1f %-12.1f %-16.1f %-14.1f ", r1, r2, r3, rTotal, rPercent);
        printf("%-11.1f %-11.1f %-11.1f %-15.1f %-13.1f ", l1, l2, l3, lTotal, lPercent);
        printf("%-11.1f\n", finalGrade);
        printf("Do you want to add another student (y/n)? ");
        scanf("%s", &answer);
    } while (answer == 'y' || answer == 'Y');

    return 0;
}
