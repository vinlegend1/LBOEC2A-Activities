#ifndef RESUME_H
#define RESUME_H
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define RESUMEWIDTH 130
#define LINEWIDTH 49
#define FIRSTLINESTART 17

void printOne(char *text, char *alignment, char *input, int doesBreak);
void printTwoCol(char *text1, char *alignment, char *text2, char *fill1,
                 char *fill2, char *input1, char *input2);
void printFullWidth(char *text, char *input);
void printFullWidthDivided(char *text, char *input1, char *input2, char *input3,
                           char *input4);
void printTwoHalves(char *text1, char *text2, char *text3, char *text4,
                    char *input1, char *input2, char *input3, char *input4);
void printTwoHeadings(char *text1, char *text2);
void printThreeHeadings(char *text1, char *text2, char *text3);
void printShortLongLines(char *text, char *input1, char *input2);
void printOneAndHalf(char *text1, char *text2, char *text3, char *input1,
                     char *input2, char *input3);
void printHalfCols(char *text1, char *text2, char *input1, char *input2,
                   int width, int place, int doesBreak);
void printLine(char *input, int doesBreak, int lineWidth);
void printSpaces(int num);
bool isNone(char *text);
bool isYes(char letter);

bool isNone(char *text) {
  return strcmp(text, "none") == 0 || strcmp(text, "") == 0;
}

bool isYes(char letter) { return letter == 'y' || letter == 'Y'; }

void printOne(char *text, char *alignment, char *input, int doesBreak) {
  if (strlen(input) > 0) {
    if (strcmp(alignment, "right") == 0) {
      printSpaces(FIRSTLINESTART - strlen(text));
    }
    printf("%s", text);
    if (strcmp(alignment, "left") == 0) {
      printSpaces(FIRSTLINESTART - strlen(text));
    }
    printLine(input, doesBreak, LINEWIDTH);
  } else {
    printSpaces(FIRSTLINESTART);
    printSpaces(LINEWIDTH);
    if (doesBreak)
      printf("\n");
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
    printLine(input1, 0, LINEWIDTH);
  }

  int spacing = RESUMEWIDTH - 2 * LINEWIDTH - FIRSTLINESTART - strlen(text2);

  printSpaces(spacing);

  if (strlen(input2) > 0) {
    printf("%s", text2);
    if (strcmp(fill2, " ") == 0) {
      printSpaces(LINEWIDTH);
      printf("\n");
    } else {
      printLine(input2, 1, LINEWIDTH);
    }
  } else {
    printSpaces(strlen(text2));
    printf("\n");
  }
}

void printFullWidth(char *text, char *input) {
  printSpaces(FIRSTLINESTART - strlen(text));
  printf("%s", text);
  printLine(input, 1, RESUMEWIDTH - FIRSTLINESTART);
}

void printFullWidthDivided(char *text, char *input1, char *input2, char *input3,
                           char *input4) {
  int col = 4;
  printSpaces(FIRSTLINESTART - strlen(text));
  printf("%s", text);
  int spacing = 5;
  int lineWidth = (int)(RESUMEWIDTH - FIRSTLINESTART) / col - spacing;
  for (int i = 0; i < col; i++) {
    if (i == col - 1) {
      lineWidth += spacing + (RESUMEWIDTH - FIRSTLINESTART) -
                   (lineWidth * 4 + spacing * 4);
    }
    if (i == 0) {
      printLine(input1, 0, lineWidth);
    } else if (i == 1) {
      printLine(input2, 0, lineWidth);
    } else if (i == 2) {
      printLine(input3, 0, lineWidth);
    } else if (i == 3) {
      printLine(input4, 0, lineWidth);
    }
    printSpaces(spacing);
  }

  printf("\n");
}

void printTwoHalves(char *text1, char *text2, char *text3, char *text4,
                    char *input1, char *input2, char *input3, char *input4) {
  printHalfCols(text1, text2, input1, input2, RESUMEWIDTH / 2, 1, 0);
  printHalfCols(text3, text4, input3, input4, RESUMEWIDTH / 2, 2, 1);
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

void printShortLongLines(char *text, char *input1, char *input2) {
  int spacing = 5;
  int smallWidth = (int)RESUMEWIDTH / 8;
  int remaining = RESUMEWIDTH - (FIRSTLINESTART + smallWidth + spacing);
  printSpaces(FIRSTLINESTART - strlen(text));
  printSpaces(spacing / 2 + 1);
  printLine(input1, 0, smallWidth);
  printSpaces(spacing / 2);
  printLine(input2, 1, remaining);
}

void printOneAndHalf(char *text1, char *text2, char *text3, char *input1,
                     char *input2, char *input3) {
  printOne(text1, "right", input1, 0);
  printHalfCols(text2, text3, input2, input3, RESUMEWIDTH / 2, 2, 1);
}

void printHalfCols(char *text1, char *text2, char *input1, char *input2,
                   int width, int place, int doesBreak) {
  int lineWidth = (int)width / 4;
  int spacing = LINEWIDTH - lineWidth * 2 - strlen(text2);
  int initSpacing =
      width * place - (2 * LINEWIDTH + strlen(text1) + FIRSTLINESTART);

  printSpaces(initSpacing);

  if (strlen(input1) > 0) {
    if (place == 1) {
      printSpaces(FIRSTLINESTART - strlen(text1));
    }
    printf("%s", text1);
    printLine(input1, 0, lineWidth);
  } else {
    if (place == 1) {
      printSpaces(FIRSTLINESTART);
    }
    printSpaces(lineWidth);
  }

  printSpaces(spacing);

  if (strlen(input2) > 0) {
    printf("%s", text2);
    printLine(input2, 0, lineWidth);

  } else {
    printSpaces(strlen(text2));
    printLine(input2, 0, lineWidth);
  }

  if (doesBreak == 1) {
    printf("\n");
  }
}

void printLine(char *input, int doesBreak, int lineWidth) {
  printf("%s", input);
  printSpaces(lineWidth - strlen(input));
  if (doesBreak == 1) {
    printf("\n");
  }
}

void printSpaces(int num) {
  for (int i = 0; i < num; i++) {
    printf(" ");
  }
}

#endif // !RESUME_H
