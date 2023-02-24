#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int RESUMEWIDTH = 116;
int LINEWIDTH = 38;
int FIRSTLINESTART = 17;

void printSpaces(int num, char *input);
void printLine(int doesBreak, int lineWidth, char *input);
void printOne(char *text, char *alignment, int doesBreak, char *input);
void printTwoCol(char *text1, char *alignment, char *text2, char *fill1,
                 char *fill2, char *input);
void printFullWidth(char *text, char *input);
void printFullWidthDivided(char *text, int col, char *input);
void printTwoHalves(char *text1, char *text2, char *text3, char *text4,
                    char *input);
void printOneAndHalf(char *text1, char *text2, char *text3, char *input);
void printHalfCols(char *text1, char *text2, int width, int initSpacing,
                   int doesBreak, char *input);
void printTwoHeadings(char *text1, char *text2, char *input);
void printThreeHeadings(char *text1, char *text2, char *text3, char *input);
void printShortLongLines(char *text, char *input);

int main() {
  char *name;
  scanf("%s", name);
  printOne("Name: ", "left", 1, name);
  printTwoCol("Address: ", "left", "City: ", "_", "_");
  printTwoCol("Postal Code: ", "left", "Phone: ", "_", "_");

  printf("\n");

  printFullWidth("Job Objective: ");
  printFullWidth("");
  printFullWidth("");
  printFullWidth("");
  printFullWidthDivided("Skill List: ", 4);
  printFullWidthDivided("", 4);
  printFullWidthDivided("", 4);

  printf("\n");

  printf("Work Experience: \n");
  printTwoCol("    Job Title: ", "right", "Job Title: ", "_", "_");
  printTwoHalves("    From: ", "To: ", "From: ", "To: ");
  printTwoCol("    Company: ", "right", "Company: ", "_", "_");
  printTwoCol("    Address: ", "right", "Address: ", "_", "_");
  printTwoHalves("    Duties: ", "", "Duties: ", "");
  printTwoHalves("", "", "", "");
  printTwoHalves("", "", "", "");

  printf("\n");

  printThreeHeadings("Education: ", "Date",
                     "Type of Course/Degree and Where Taken");
  printShortLongLines("");
  printShortLongLines("");
  printShortLongLines("");
  printShortLongLines("");

  printf("\n");

  printTwoHeadings("Volunteer Work: ", "References: ");

  printOneAndHalf("    Where: ", "Name: ", "Position: ");
  printTwoCol("    Duties: ", "right", "Phone: ", "_", "_");
  printOne("", "right", 1);
  printOneAndHalf("", "Name: ", "Position: ");
  printTwoCol("", "right", "Phone: ", " ", "_");

  printOne("    Where: ", "right", 1);
  printOneAndHalf("    Duties: ", "Name: ", "Position: ");
  printTwoCol("", "right", "Phone: ", "_", "_");
  printOne("", "right", 1);

  return 0;
}

void printText(char *text, int doesBreak) {
  printf("%s", input);
  if (doesBreak == 1) {
    printf("\n");
  }
}

void printOne(char *text, char *alignment, int doesBreak, char *input) {
  if (strcmp(alignment, "right") == 0) {
    printSpaces(FIRSTLINESTART - strlen(text));
  }
  printf("%s", text);
  if (strcmp(alignment, "left") == 0) {
    printSpaces(FIRSTLINESTART - strlen(text));
  }
}

void printTwoCol(char *text1, char *alignment, char *text2, char *fill1,
                 char *fill2, char *input1, char *input2) {
  if (strcmp(alignment, "right") == 0) {
    printSpaces(FIRSTLINESTART - strlen(text1));
  }
  printf("%s", text1);
  if (strcmp(alignment, "left") == 0) {
    printSpaces(FIRSTLINESTART - strlen(text1));
  }
  if (strcmp(fill1, " ") == 0) {
    printSpaces(LINEWIDTH);
  } else {
    printText(input1, 0);
  }

  int spacing = RESUMEWIDTH - strlen(input1) - strlen(input2) - FIRSTLINESTART -
                strlen(text2);

  printSpaces(spacing);

  printf("%s", text2);
  if (strcmp(fill2, " ") == 0) {
    printSpaces(LINEWIDTH);
    printf("\n");
  } else {
    printText(input1, 1);
  }
}

void slice(const char *str, char *result, int start, int end) {
  strncpy(result, str + start, end - start);
}

void printFullWidth(char *text, char *input) {
  printSpaces(FIRSTLINESTART - strlen(text));
  printf("%s", text);
  printText(input, 1);
}

void printFullWidthDivided(char *label, int col, char *input, char *text1,
                           char *text2, char *text3, char *text4) {
  printSpaces(FIRSTLINESTART - strlen(text));
  printf("%s", label);
  int spacing = 5;
  printLine(0, lineWidth);
  printText(text1, 0);
  printSpaces(spacing);
  printText(text2, 0);
  printSpaces(spacing);
  printText(text3, 0);
  printSpaces(spacing);
  printText(text4, 0);
  printSpaces(spacing);

  printf("\n");
}

void printTwoHalves(char *text1, char *text2, char *text3, char *text4,
                    char *input) {
  printHalfCols(text1, text2, RESUMEWIDTH / 2, 1, 0);
  printHalfCols(text1, text2, RESUMEWIDTH / 2, 2, 1);
}

void printTwoHeadings(char *text1, char *text2, char *input) {
  printSpaces(FIRSTLINESTART - strlen(text1));
  printf("%s", text1);
  printSpaces(LINEWIDTH);
  int spacing = RESUMEWIDTH - 2 * LINEWIDTH - FIRSTLINESTART - strlen(text2);

  printSpaces(spacing);

  printf("%s", text2);
  printSpaces(LINEWIDTH);
  printf("\n");
}

void printThreeHeadings(char *text1, char *text2, char *text3, char *input) {
  int smallWidth = (int)RESUMEWIDTH / 8;
  int p1 = (int)smallWidth / 2 - strlen(text2) / 2;
  int remaining = RESUMEWIDTH - (strlen(text1) + smallWidth);
  int p2 = (int)remaining / 2 - strlen(text3) / 2;

  printSpaces(FIRSTLINESTART - strlen(text1));

  printf("%s", text1);
  printSpaces(p1);
  printf("%s", text2);
  printSpaces(p1);
  printSpaces(p2);
  printf("%s", text3);

  printf("\n");
}

void printShortLongLines(char *text, char *input) {
  int spacing = 5;
  int smallWidth = (int)RESUMEWIDTH / 8;
  int remaining = RESUMEWIDTH - (FIRSTLINESTART + smallWidth + spacing);
  printSpaces(FIRSTLINESTART - strlen(text));
  printLine(0, smallWidth);
  printSpaces(spacing);
  printLine(1, remaining);
}

void printOneAndHalf(char *text1, char *text2, char *text3, char *input) {
  printOne(text1, "right", 0);
  printHalfCols(text2, text3, RESUMEWIDTH / 2, 2, 1);
}

void printHalfCols(char *text1, char *text2, int width, int place,
                   int doesBreak, char *input) {
  int lineWidth = (int)width / 4;
  int spacing = LINEWIDTH - lineWidth * 2 - strlen(text2);
  int initSpacing =
      width * place - (2 * LINEWIDTH + strlen(text1) + FIRSTLINESTART);

  printSpaces(initSpacing);

  if (place == 1) {
    printSpaces(FIRSTLINESTART - strlen(text1));
  }
  printf("%s", text1);
  printLine(0, lineWidth);

  printSpaces(spacing);

  printf("%s", text2);
  printLine(0, lineWidth);

  if (doesBreak == 1) {
    printf("\n");
  }
}

void printLine(int doesBreak, int lineWidth) {
  for (int i = 0; i < lineWidth; i++) {
    printf("_");
  }
  if (doesBreak == 1) {
    printf("\n");
  }
}

void printSpaces(int num) {
  for (int i = 0; i < num; i++) {
    printf(" ");
  }
}
