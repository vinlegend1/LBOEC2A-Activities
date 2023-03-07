#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int RESUMEWIDTH = 130;
int LINEWIDTH = 49;
int FIRSTLINESTART = 17;

void printSpaces(int num);
void printLine(int doesBreak, int lineWidth);
void printOne(char *text, char *alignment, int doesBreak);
void printTwoCol(char *text1, char *alignment, char *text2, char *fill1,
                 char *fill2);
void printFullWidth(char *text);
void printFullWidthDivided(char *text, int col);
void printTwoHalves(char *text1, char *text2, char *text3, char *text4);
void printOneAndHalf(char *text1, char *text2, char *text3);
void printHalfCols(char *text1, char *text2, int width, int initSpacing,
                   int doesBreak);
void printTwoHeadings(char *text1, char *text2);
void printThreeHeadings(char *text1, char *text2, char *text3);
void printShortLongLines(char *text);

int main() {
  printOne("Name: ", "left", 1);
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

void printOne(char *text, char *alignment, int doesBreak) {
  if (strcmp(alignment, "right") == 0) {
    printSpaces(FIRSTLINESTART - strlen(text));
  }
  printf("%s", text);
  if (strcmp(alignment, "left") == 0) {
    printSpaces(FIRSTLINESTART - strlen(text));
  }
  printLine(doesBreak, LINEWIDTH);
}

void printTwoCol(char *text1, char *alignment, char *text2, char *fill1,
                 char *fill2) {
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
    printLine(0, LINEWIDTH);
  }

  int spacing = RESUMEWIDTH - 2 * LINEWIDTH - FIRSTLINESTART - strlen(text2);

  printSpaces(spacing);

  printf("%s", text2);
  if (strcmp(fill2, " ") == 0) {
    printSpaces(LINEWIDTH);
    printf("\n");
  } else {
    printLine(1, LINEWIDTH);
  }
}

void printFullWidth(char *text) {
  printSpaces(FIRSTLINESTART - strlen(text));
  printf("%s", text);
  printLine(1, RESUMEWIDTH - FIRSTLINESTART);
}

void printFullWidthDivided(char *text, int col) {
  printSpaces(FIRSTLINESTART - strlen(text));
  printf("%s", text);
  int spacing = 5;
  int lineWidth = (int)(RESUMEWIDTH - FIRSTLINESTART) / col - spacing;
  for (int i = 0; i < col; i++) {
    if (i == col - 1) {
      lineWidth += spacing + (RESUMEWIDTH - FIRSTLINESTART) -
                   (lineWidth * 4 + spacing * 4);
    }
    printLine(0, lineWidth);
    printSpaces(spacing);
  }

  printf("\n");
}

void printTwoHalves(char *text1, char *text2, char *text3, char *text4) {
  printHalfCols(text1, text2, RESUMEWIDTH / 2, 1, 0);
  printHalfCols(text3, text4, RESUMEWIDTH / 2, 2, 1);
}

void printTwoHeadings(char *text1, char *text2) {
  printSpaces(FIRSTLINESTART - strlen(text1));
  printf("%s", text1);
  printSpaces(LINEWIDTH);
  int spacing = RESUMEWIDTH - 2 * LINEWIDTH - FIRSTLINESTART - strlen(text2);

  printSpaces(spacing);

  printf("%s", text2);
  printSpaces(LINEWIDTH);
  printf("\n");
}

void printThreeHeadings(char *text1, char *text2, char *text3) {
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

void printShortLongLines(char *text) {
  int spacing = 5;
  int smallWidth = (int)RESUMEWIDTH / 8;
  int remaining = RESUMEWIDTH - (FIRSTLINESTART + smallWidth + spacing);
  printSpaces(FIRSTLINESTART - strlen(text));
  printLine(0, smallWidth);
  printSpaces(spacing);
  printLine(1, remaining);
}

void printOneAndHalf(char *text1, char *text2, char *text3) {
  printOne(text1, "right", 0);
  printHalfCols(text2, text3, RESUMEWIDTH / 2, 2, 1);
}

void printHalfCols(char *text1, char *text2, int width, int place,
                   int doesBreak) {
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
