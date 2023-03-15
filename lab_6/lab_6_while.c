#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int RESUMEWIDTH = 130;
int LINEWIDTH = 49;
int FIRSTLINESTART = 17;

#define NAME "Vincent Hong"
#define ADDRESS "168 Residences Tower 2 Unit 32-A 918 Soler St."
#define CITY "Binondo, Manila"
#define POSTAL_CODE "1006"
#define PHONE "09166951249"
#define JOB_OBJECTIVE_1                                                        \
  "Learn and develop my skills relating to mechanical engineering and "        \
  "interpersonal"
#define JOB_OBJECTIVE_2 "Solve the world's biggest problems like climate change"
#define JOB_OBJECTIVE_3 ""
#define JOB_OBJECTIVE_4 ""
#define SKILL1 "Solidworks"
#define SKILL2 "Autocad"
#define SKILL3 "C/C++"
#define SKILL4 "Python"
#define SKILL5 "Java"
#define SKILL6 "Javascript/Typescript"
#define SKILL7 ""
#define SKILL8 ""
#define SKILL9 ""
#define SKILL10 ""
#define SKILL11 ""
#define SKILL12 ""

#define JOB_TITLE_1 "Software Developer"
#define FROM_1 "2018"
#define TO_1 "2022"
#define COMPANY1 "Google Inc."
#define COMPANY_ADDRESS1 "Mountain View"

#define DUTIES1_1 "A/B testing"
#define DUTIES2_1 "Quality Assurance"
#define DUTIES3_1 "backend development"
#define DUTIES4_1 ""
#define DUTIES5_1 ""
#define DUTIES6_1 ""

#define JOB_TITLE_2 "High School Teacher"
#define FROM_2 "2016"
#define TO_2 "2018"
#define COMPANY2 "Uno High School"
#define COMPANY_ADDRESS2 "Tondo, Manila"

#define DUTIES1_2 ""
#define DUTIES2_2 ""
#define DUTIES3_2 ""
#define DUTIES4_2 ""
#define DUTIES5_2 ""
#define DUTIES6_2 ""

#define EDUCATION_1                                                            \
  "De La Salle University BS Mechanical Engineering w/ Specialization in "     \
  "Mechatronics Engineering"
#define ED_DATE_1 "2022-2026"
#define EDUCATION_2 "De La Salle University BS/MS Computer Science"
#define ED_DATE_2 "2020-2023"
#define EDUCATION_3 ""
#define ED_DATE_3 ""
#define EDUCATION_4 ""
#define ED_DATE_4 ""

#define VOLUNTEER_1 "Khan Academy"
#define V_DUTIES_1_1 "supervising staff members and daily activities"
#define V_DUTIES_2_1 "managing engineers and developers"
#define V_DUTIES_3_1 "teaching math and science"

#define VOLUNTEER_2 ""
#define V_DUTIES_1_2 ""
#define V_DUTIES_2_2 ""
#define V_DUTIES_3_2 ""

#define REF_NAME_1 "Enuk Abas"
#define REF_POS_1 "CEO of Netscape"
#define REF_PHONE_1 "09182732384"
#define REF_NAME_2 "Guido Fernandez"
#define REF_POS_2 "CEO of Apple"
#define REF_PHONE_2 "09283742831"
#define REF_NAME_3 "Bert Manikis"
#define REF_POS_3 "CTO of Stripe"
#define REF_PHONE_3 "09374829183"

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

int main() {
  printOne("Name: ", "left", NAME, 1);
  printTwoCol("Address: ", "left", "City: ", "_", "_", ADDRESS, CITY);
  printTwoCol("Postal Code: ", "left", "Phone: ", "_", "_", POSTAL_CODE, PHONE);

  printf("\n");

  printFullWidth("Job Objective: ", JOB_OBJECTIVE_1);
  printFullWidth("", JOB_OBJECTIVE_2);
  printFullWidth("", JOB_OBJECTIVE_3);
  printFullWidth("", JOB_OBJECTIVE_4);
  printFullWidthDivided("Skill List: ", SKILL1, SKILL2, SKILL3, SKILL4);
  printFullWidthDivided("", SKILL5, SKILL6, SKILL7, SKILL8);
  printFullWidthDivided("", SKILL9, SKILL10, SKILL11, SKILL12);

  printf("\n");

  printf("Work Experience: \n");
  printTwoCol("    Job Title: ", "right", "Job Title: ", "_", "_", JOB_TITLE_1,
              JOB_TITLE_2);
  printTwoHalves("    From: ", "To: ", "From: ", "To: ", FROM_1, TO_1, FROM_2,
                 TO_2);
  printTwoCol("    Company: ", "right", "Company: ", "_", "_", COMPANY1,
              COMPANY2);
  printTwoCol("    Address: ", "right", "Address: ", "_", "_", COMPANY_ADDRESS1,
              COMPANY_ADDRESS2);
  printTwoHalves("    Duties: ", "", "Duties: ", "", DUTIES1_1, DUTIES2_1,
                 DUTIES1_2, DUTIES2_2);
  printTwoHalves("", "", "", "", DUTIES3_1, DUTIES4_1, DUTIES3_2, DUTIES4_2);
  printTwoHalves("", "", "", "", DUTIES5_1, DUTIES6_1, DUTIES5_2, DUTIES6_2);

  printf("\n");

  printThreeHeadings("Education: ", "Date",
                     "Type of Course/Degree and Where Taken");
  printShortLongLines("", ED_DATE_1, EDUCATION_1);
  printShortLongLines("", ED_DATE_2, EDUCATION_2);
  printShortLongLines("", ED_DATE_3, EDUCATION_3);
  printShortLongLines("", ED_DATE_4, EDUCATION_4);

  printf("\n");

  printTwoHeadings("Volunteer Work: ", "References: ");

  printOneAndHalf("    Where: ", "Name: ", "Position: ", VOLUNTEER_1,
                  REF_NAME_1, REF_POS_1);
  printTwoCol("    Duties: ", "right", "Phone: ", "_", "_", V_DUTIES_1_1,
              REF_PHONE_1);
  printOne("", "right", V_DUTIES_2_1, 1);
  printOneAndHalf("", "Name: ", "Position: ", V_DUTIES_3_1, REF_NAME_2,
                  REF_POS_2);
  printTwoCol("", "right", "Phone: ", " ", "_", "", REF_PHONE_2);

  printOne("    Where: ", "right", VOLUNTEER_2, 1);
  printOneAndHalf("    Duties: ", "Name: ", "Position: ", V_DUTIES_1_2,
                  REF_NAME_3, REF_POS_3);
  printTwoCol("", "right", "Phone: ", "_", "_", V_DUTIES_2_2, REF_PHONE_3);
  printOne("", "right", V_DUTIES_3_2, 1);

  return 0;
}

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
  int i = 0;
  while (i < col) {
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
    i++;
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
  int i = 0;
  while (i < num) {
    printf(" ");
    i++;
  }
}
