#include "resume.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char name[90];
  char address[49];
  char phone[13];
  char city[49];
  char postalCode[7];

  int numJO = 4;
  char jobObjectives[numJO][112];

  int numSkills = 12;
  char skills[numSkills][22];

  int numJobs = 2;
  int numDuties = 6;
  char jobTitles[numJobs][49];
  char froms[numJobs][15];
  char tos[numJobs][15];
  char companies[numJobs][49];
  char companyAddresses[numJobs][49];
  char companyDuties[numJobs][numDuties][16];

  int numEdu = 4;
  char educations[numEdu][92];
  char educationDates[numEdu][16];

  int numVol = 2;
  char volunteerWhere[numVol][49];
  char volunteerDuties[numVol][3][49];

  int numRef = 3;
  char referenceNames[numRef][16];
  char referencePoss[numRef][16];
  char referencePhones[numRef][49];

  printf("What is your name? ");
  scanf("%[^\n]%*c", name);

  printf("What is your home address (excluding city)? ");
  scanf("%[^\n]%*c", address);

  printf("What city do you live in? ");
  scanf("%[^\n]%*c", city);

  printf("What is the postal code of the city you live in? ");
  scanf("%[^\n]%*c", postalCode);

  printf("What is your phone number? ");
  scanf("%[^\n]%*c", phone);

  int limitJO = 0;
  for (int i = 0; i < numJO; i++) {
    char obj[112];
    printf("What is your job objective #%d (if none, type \"none\"): ", i + 1);
    scanf("%[^\n]%*c", obj);
    if (isNone(obj)) {
      limitJO = i;
      break;
    }
    strncpy(jobObjectives[i], obj, 112);
  }

  int limitSkill = 0;
  for (int i = 0; i < numSkills; i++) {
    char obj[22];
    printf("What is #%d skill (if none, type \"none\"): ", i + 1);
    scanf("%[^\n]%*c", obj);
    if (isNone(obj)) {
      limitSkill = i;
      break;
    }
    strncpy(skills[i], obj, 22);
  }

  int limitJobs = 0;
  int limitJobDuties = 0;
  for (int i = 0; i < numJobs; i++) {
    char *from[15];
    char *to[15];
    char *comp[49];
    char *compAd[49];
    char *title[49];

    printf("What is #%d job title (if none, type \"none\"): ", i + 1);
    scanf("%[^\n]%*c", title);

    if (isNone(title)) {
      limitJobs = i;
      break;
    }
    printf("What is the company's name? ");
    scanf("%[^\n]%*c", comp);
    printf("What is the company's address? ");
    scanf("%[^\n]%*c", compAd);
    printf("When did you start working at this company? ");
    scanf("%[^\n]%*c", from);
    printf("When did you stop working at this company? ");
    scanf("%[^\n]%*c", to);

    for (int j = 0; j < numDuties; j++) {
      char duty[16];

      printf(
          "What is your #%d duty at this company? (if none, type \"none\")? ",
          j + 1);
      scanf("%[^\n]%*c", duty);

      if (isNone(duty)) {
        limitJobDuties = j;
        break;
      }
      strncpy(companyDuties[i][j], duty, 16);
    }
    strncpy(companies[i], comp, 49);
    strncpy(companyAddresses[i], compAd, 49);
    strncpy(froms[i], from, 15);
    strncpy(tos[i], to, 15);
    strncpy(jobTitles[i], to, 49);
  }

  int limitEdu = 0;
  for (int i = 0; i < numEdu; i++) {
    char name[92];
    char date[16];
    printf("State #%d educational institution and course/degree taken (type "
           "none if none): ",
           i + 1);
    scanf("%[^\n]%*c", name);
    if (isNone(name)) {
      limitEdu = i;
      break;
    }
    printf("State Start and End Year for stated degree: ");
    scanf("%[^\n]%*c", date);
    strncpy(educations[i], name, 92);
    strncpy(educationDates[i], date, 16);
  }

  int limitVol = 0;
  for (int i = 0; i < numVol; i++) {
    char where[49];

    printf("Where did you #%d volunteer (if none, type \"none\"): ", i + 1);
    scanf("%[^\n]%*c", where);

    if (isNone(where)) {
      limitJobs = i;
      break;
    }

    for (int j = 0; j < 3; j++) {
      char duty[49];

      printf("What is your #%d duty at this organization? (if none, type "
             "\"none\")",
             i + 1);
      scanf("%[^\n]%*c", duty);

      if (isNone(duty)) {
        limitJobDuties = j;
        break;
      }
      strncpy(volunteerDuties[i][j], duty, 49);
    }
    strncpy(volunteerWhere[i], where, 49);
  }

  int limitRef = 0;
  for (int i = 0; i < numRef; i++) {
    char name[16];
    char pos[16];
    char phone[49];
    printf("Name of #%d Reference: ", i + 1);
    scanf("%[^\n]%*c", name);
    printf("Position of #%d Reference: ", i + 1);
    scanf("%[^\n]%*c", pos);
    printf("Phone Number of #%d Reference: ", i + 1);
    scanf("%[^\n]%*c", phone);
    if (isNone(name)) {
      limitEdu = i;
      break;
    }
    strncpy(referenceNames[i], name, 16);
    strncpy(referencePoss[i], pos, 16);
    strncpy(referencePhones[i], phone, 49);
  }

  printOne("Name: ", "left", name, 1);
  printTwoCol("Address: ", "left", "City: ", "_", "_", address, city);
  printTwoCol("Postal Code: ", "left", "Phone: ", "_", "_", postalCode, phone);

  printf("\n");

  for (int i = 0; i < limitJO; i++) {
    if (i == 0) {
      printFullWidth("Job Objective: ", jobObjectives[i]);
    } else {
      printFullWidth("", jobObjectives[i]);
    }
  }

  for (int i = 0; i < limitSkill; i += 4) {
    int remaining = limitSkill - i;
    if (i == 0) {
      if (remaining == 1) {
        printFullWidthDivided("Skill List: ", skills[i], "", "", "");
      } else if (remaining == 2) {
        printFullWidthDivided("Skill List: ", skills[i], skills[i + 1], "", "");
      } else if (remaining == 3) {
        printFullWidthDivided("Skill List: ", skills[i], skills[i + 1],
                              skills[i + 2], "");
      } else {
        printFullWidthDivided("Skill List: ", skills[i], skills[i + 1],
                              skills[i + 2], skills[i + 3]);
      }
    } else {
      if (remaining == 1) {
        printFullWidthDivided("", skills[i], "", "", "");
      } else if (remaining == 2) {
        printFullWidthDivided("", skills[i], skills[i + 1], "", "");
      } else if (remaining == 3) {
        printFullWidthDivided("", skills[i], skills[i + 1], skills[i + 2], "");
      } else {
        printFullWidthDivided("", skills[i], skills[i + 1], skills[i + 2],
                              skills[i + 3]);
      }
    }
  }

  printf("\n");

  printf("Work Experience: \n");
  if (limitJobs == 2) {
    printTwoCol("    Job Title: ", "right", "Job Title: ", "_", "_",
                jobTitles[0], jobTitles[1]);
    printTwoHalves("    From: ", "To: ", "From: ", "To: ", froms[0], tos[0],
                   froms[1], tos[1]);
    printTwoCol("    Company: ", "right", "Company: ", "_", "_", companies[0],
                companies[1]);
    printTwoCol("    Address: ", "right", "Address: ", "_", "_",
                companyAddresses[0], companyAddresses[1]);
  } else if (limitJobs == 1) {
    printTwoCol("    Job Title: ", "right", "Job Title: ", "_", "_",
                jobTitles[0], "");
    printTwoHalves("    From: ", "To: ", "", "", froms[0], tos[0], "", "");
    printTwoCol("    Company: ", "right", "", "_", "_", companies[0], "");
    printTwoCol("    Address: ", "right", "", "_", "_", companyAddresses[0],
                "");
  }

  for (int i = 0; i < limitJobDuties; i += 2) {
    int remaining = limitJobDuties - i;
    if (i == 0) {
      if (remaining == 1) {
        if (limitJobs == 2) {
          printTwoHalves("    Duties: ", "", "Duties: ", "",
                         companyDuties[0][i], "", companyDuties[1][i], "");

        } else if (limitJobs == 1) {
          printTwoHalves("    Duties: ", "", "", "", companyDuties[0][i], "",
                         "", "");
        }
      } else {
        if (limitJobs == 2) {
          printTwoHalves("    Duties: ", "", "Duties: ", "",
                         companyDuties[0][i], companyDuties[0][i + 1],
                         companyDuties[1][i], companyDuties[1][i + 1]);

        } else if (limitJobs == 1) {
          printTwoHalves("    Duties: ", "", "", "", companyDuties[0][i],
                         companyDuties[0][i + 1], "", "");
        }
      }
    } else {
      if (remaining == 1) {
        if (limitJobs == 2) {
          printTwoHalves("    Duties: ", "", "Duties: ", "",
                         companyDuties[0][i], "", companyDuties[1][i], "");

        } else if (limitJobs == 1) {
          printTwoHalves("    Duties: ", "", "", "", companyDuties[0][i], "",
                         "", "");
        }
      } else {
        if (limitJobs == 2) {
          printTwoHalves("    Duties: ", "", "Duties: ", "",
                         companyDuties[0][i], companyDuties[0][i + 1],
                         companyDuties[1][i], companyDuties[1][i + 1]);

        } else if (limitJobs == 1) {
          printTwoHalves("    Duties: ", "", "", "", companyDuties[0][i],
                         companyDuties[0][i + 1], "", "");
        }
      }
    }
  }

  printf("\n");

  printThreeHeadings("Education: ", "Date",
                     "Type of Course/Degree and Where Taken");
  for (int i = 0; i < limitEdu; i++) {
    printShortLongLines("", educationDates[i], educationDates[i]);
  }

  printf("\n");

  printTwoHeadings("Volunteer Work: ", "References: ");

  printOneAndHalf("    Where: ", "Name: ", "Position: ", volunteerWhere[0],
                  referenceNames[0], referencePoss[0]);
  printTwoCol("    Duties: ", "right", "Phone: ", "_", "_",
              volunteerDuties[0][0], referencePhones[0]);
  printOne("", "right", volunteerDuties[0][1], 1);
  printOneAndHalf("", "Name: ", "Position: ", volunteerDuties[0][2],
                  referenceNames[1], referencePoss[1]);
  printTwoCol("", "right", "Phone: ", " ", "_", "", referencePhones[1]);

  printOne("    Where: ", "right", volunteerWhere[1], 1);
  printOneAndHalf("    Duties: ", "Name: ", "Position: ", volunteerDuties[1][0],
                  referenceNames[2], referencePoss[2]);
  printTwoCol("", "right", "Phone: ", "_", "_", volunteerDuties[1][1],
              referencePhones[2]);
  printOne("", "right", volunteerDuties[1][2], 1);

  return 0;
}
