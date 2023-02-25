#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printResumeTemplate(
    char *name, char *address, char *city, char *postalCode, char *phone,
    char *jobObjective1, char *jobObjective2, char *jobObjective3,
    char *jobObjective4, char *skill1, char *skill2, char *skill3, char *skill4,
    char *skill5, char *skill6, char *skill7, char *skill8, char *skill9,
    char *skill10, char *skill11, char *skill12, char *jobTitle1, char *from1,
    char *to1, char *company1, char *companyAddress1, char *firstDuty1,
    char *firstDuty2, char *firstDuty3, char *firstDuty4, char *firstDuty5,
    char *firstDuty6, char *jobTitle2, char *from2, char *to2, char *company2,
    char *companyAddress2, char *secondDuty1, char *secondDuty2,
    char *secondDuty3, char *secondDuty4, char *secondDuty5, char *secondDuty6,
    char *education1, char *educationDate1, char *education2,
    char *educationDate2, char *education3, char *educationDate3,
    char *volunteerWork1Where, char *volunteerWork1Duty1,
    char *volunteerWork1Duty2, char *volunteerWork1Duty3,
    char *volunteerWork2Where, char *volunteerWork2Duty1,
    char *volunteerWork2Duty2, char *volunteerWork2Duty3, char *reference1Name,
    char *reference1Pos, char *reference1Phone, char *reference2Name,
    char *reference2Pos, char *reference2Phone, char *reference3Name,
    char *reference3Pos, char *reference3Phone, char *ref1Name, char *ref1Pos,
    char *ref1Phone, char *ref2Name, char *ref2Pos, char *ref2Phone,
    char *ref3Name, char *ref3Pos, char *ref3Phone, char hasWork,
    char hasSecondJob, char didVolunteer, char didVolunteer2);
bool isNone(char *text);
bool isYes(char letter);
void ifSkill(char *skill, int place);
void printSkills(char *skill1, char *skill2, char *skill3, char *skill4,
                 char *skill5, char *skill6, char *skill7, char *skill8,
                 char *skill9, char *skill10, char *skill11, char *skill12);
void printInputSkills(char *skill1, char *skill2, char *skill3, char *skill4,
                      char *skill5, char *skill6, char *skill7, char *skill8,
                      char *skill9, char *skill10, char *skill11,
                      char *skill12);

int main() {
  char name[90];
  char address[49];
  char phone[13];
  char city[49];
  char postalCode[7];

  char jobObjective1[112];
  char jobObjective2[112];
  char jobObjective3[112];
  char jobObjective4[112];

  char skill1[22];
  char skill2[22];
  char skill3[22];
  char skill4[22];
  char skill5[22];
  char skill6[22];
  char skill7[22];
  char skill8[22];
  char skill9[22];
  char skill10[22];
  char skill11[22];
  char skill12[22];

  char hasWork;
  char hasSecondJob;
  char didVolunteer;
  char didVolunteer2;

  char jobTitle1[49];
  char from1[15];
  char to1[15];
  char company1[49];
  char companyAddress1[49];
  char firstDuty1[16];
  char firstDuty2[16];
  char firstDuty3[16];
  char firstDuty4[16];
  char firstDuty5[16];
  char firstDuty6[16];

  char jobTitle2[49];
  char from2[15];
  char to2[15];
  char company2[49];
  char companyAddress2[49];
  char secondDuty1[16];
  char secondDuty2[16];
  char secondDuty3[16];
  char secondDuty4[16];
  char secondDuty5[16];
  char secondDuty6[16];

  char education1[92];
  char educationDate1[16];
  char education2[92];
  char educationDate2[16];
  char education3[92];
  char educationDate3[16];

  char volunteerWork1Where[49];
  char volunteerWork1Duty1[49];
  char volunteerWork1Duty2[49];
  char volunteerWork1Duty3[49];

  char volunteerWork2Where[49];
  char volunteerWork2Duty1[49];
  char volunteerWork2Duty2[49];
  char volunteerWork2Duty3[49];

  char reference1Name[16];
  char reference1Pos[16];
  char reference1Phone[49];

  char reference2Name[16];
  char reference2Pos[16];
  char reference2Phone[49];

  char reference3Name[16];
  char reference3Pos[16];
  char reference3Phone[49];

  char ref1Name[16];
  char ref1Pos[16];
  char ref1Phone[49];
  char ref2Name[16];
  char ref2Pos[16];
  char ref2Phone[49];
  char ref3Name[16];
  char ref3Pos[16];
  char ref3Phone[49];

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

  printf("What is your first job objective? ");
  scanf("%[^\n]%*c", jobObjective1);

  printf("What is your second job objective (if any, type \"none\" if none)? ");
  scanf("%[^\n]%*c", jobObjective2);

  if (strcmp(jobObjective2, "none") != 0) {
    printf(
        "What is your third job objective (if any, type \"none\" if none)? ");
    scanf("%[^\n]%*c", jobObjective3);
    if (strcmp(jobObjective3, "none") != 0) {
      printf("What is your fourth job objective (if any, type \"none\" if "
             "none)? ");
      scanf("%[^\n]%*c", jobObjective4);
    }
  }

  printf("Enumerate Skills (semi-colon separated, 12 max):\n");
  printInputSkills(skill1, skill2, skill3, skill4, skill5, skill6, skill7,
                   skill8, skill9, skill10, skill11, skill12);

  printf("Do you have any work experience (y/n)? ");
  scanf("%c", &hasWork);

  if (isYes(hasWork)) {
    printf("What is your first job title? ");
    scanf(" %[^\n]%*c", jobTitle1);
    printf("What is the name of the company you worked at? ");
    scanf("%[^\n]%*c", company1);
    printf("What is their address (provide city)? ");
    scanf("%[^\n]%*c", companyAddress1);

    printf("Start date of your tenure in that company ");
    scanf("%[^\n]%*c", from1);
    printf("End date of your tenure in that company ");
    scanf("%[^\n]%*c", to1);

    printf("Enumerate duties (6 max, keep it short at "
           "16 characters max for each duty):\n");
    printf("Duty 1: ");
    scanf("%[^\n]%*c", firstDuty1);
    printf("Duty 2 (type none if none): ");
    scanf("%[^\n]%*c", firstDuty2);
    printf("Duty 3 (type none if none): ");
    scanf("%[^\n]%*c", firstDuty3);
    printf("Duty 4 (type none if none): ");
    scanf("%[^\n]%*c", firstDuty4);
    printf("Duty 5 (type none if none): ");
    scanf("%[^\n]%*c", firstDuty5);
    printf("Duty 6 (type none if none): ");
    scanf("%[^\n]%*c", firstDuty6);

    printf("Have you worked for another company (y/n)? ");
    scanf("%c", &hasSecondJob);

    if (isYes(hasSecondJob)) {
      printf("What is your second job title? ");
      scanf(" %[^\n]%*c", jobTitle2);
      printf("What is the name of the company you worked at? ");
      scanf("%[^\n]%*c", company2);
      printf("What is their address (provide city)? ");
      scanf("%[^\n]%*c", companyAddress2);

      printf("Start date of your tenure in that company ");
      scanf("%[^\n]%*c", from2);
      printf("End date of your tenure in that company ");
      scanf("%[^\n]%*c", to2);
      printf("Enumerate duties (semi-colon separated, 6 max, keep it short "
             "at 16 characters max for each duty): ");
      printf("Enumerate duties (6 max, keep it short at "
             "16 characters max for each duty):\n");
      printf("Duty 1: ");
      scanf("%[^\n]%*c", secondDuty1);
      printf("Duty 2 (type none if none): ");
      scanf("%[^\n]%*c", secondDuty2);
      printf("Duty 3 (type none if none): ");
      scanf("%[^\n]%*c", secondDuty3);
      printf("Duty 4 (type none if none): ");
      scanf("%[^\n]%*c", secondDuty4);
      printf("Duty 5 (type none if none): ");
      scanf("%[^\n]%*c", secondDuty5);
      printf("Duty 6 (type none if none): ");
      scanf("%[^\n]%*c", secondDuty6);
    }
  }

  printf("List an Institution for Education and Course:");
  scanf(" %[^\n]%*c", education1);
  printf("State year attended and ended (or will end)");
  scanf("%[^\n]%*c", educationDate1);

  printf("List Another Institution for Education and Course (type none if "
         "none): ");
  scanf("%[^\n]%*c", education2);

  if (!isNone(education2)) {
    printf("State year attended and ended (or will end)");
    scanf("%[^\n]%*c", educationDate2);
    printf("List Another Institution for Education and Course (type none if "
           "none): ");
    scanf("%[^\n]%*c", education3);
    if (!isNone(education3)) {
      printf("State year attended and ended (or will end)");
      scanf("%[^\n]%*c", educationDate3);
    }
  }

  printf("Had any volunteer work (y/n)? ");
  scanf("%c", &didVolunteer);

  if (isYes(didVolunteer)) {
    printf("Where did you volunteer at (What is the name of the "
           "organization)? ");
    scanf(" %[^\n]%*c", volunteerWork1Where);
    printf("Enumerate your Duties:\n");
    printf("Duty 1:\n");
    scanf("%[^\n]%*c", volunteerWork1Duty1);
    printf("Duty 2:\n");
    scanf("%[^\n]%*c", volunteerWork1Duty2);
    printf("Duty 3:\n");
    scanf("%[^\n]%*c", volunteerWork1Duty3);

    printf("Would you like to add another volunteer work entry (y/n)?");
    scanf("%c", &didVolunteer2);

    if (isYes(didVolunteer2)) {
      printf("Where did you volunteer at (What is the name of the "
             "organization)? ");
      scanf(" %[^\n]%*c", volunteerWork2Where);
      printf("Enumerate your Duties:\n");
      printf("Duty 1:\n");
      scanf("%[^\n]%*c", volunteerWork2Duty1);
      printf("Duty 2:\n");
      scanf("%[^\n]%*c", volunteerWork2Duty2);
      printf("Duty 3:\n");
      scanf("%[^\n]%*c", volunteerWork2Duty3);
    }
  }

  printf("Details of First Reference:\n");
  printf("Name: ");
  scanf(" %[^\n]%*c", ref1Name);
  printf("Position of %s: ", ref1Name);
  scanf("%[^\n]%*c", ref1Pos);
  printf("Phone Number of %s: ", ref1Name);
  scanf("%[^\n]%*c", ref1Phone);

  printf("Details of Second Reference:\n");
  printf("Name: ");
  scanf("%[^\n]%*c", ref2Name);
  printf("Position of %s: ", ref2Name);
  scanf("%[^\n]%*c", ref2Pos);
  printf("Phone Number of %s: ", ref2Name);
  scanf("%[^\n]%*c", ref2Phone);

  printf("Details of Second Reference:\n");
  printf("Name: ");
  scanf("%[^\n]%*c", ref3Name);
  printf("Position of %s: ", ref3Name);
  scanf("%[^\n]%*c", ref3Pos);
  printf("Phone Number of %s: ", ref3Name);
  scanf("%[^\n]%*c", ref3Phone);

  printResumeTemplate(
      name, address, city, postalCode, phone, jobObjective1, jobObjective2,
      jobObjective3, jobObjective4, skill1, skill2, skill3, skill4, skill5,
      skill6, skill7, skill8, skill9, skill10, skill11, skill12, jobTitle1,
      from1, to1, company1, companyAddress1, firstDuty1, firstDuty2, firstDuty3,
      firstDuty4, firstDuty5, firstDuty6, jobTitle2, from2, to2, company2,
      companyAddress2, secondDuty1, secondDuty2, secondDuty3, secondDuty4,
      secondDuty5, secondDuty6, education1, educationDate1, education2,
      educationDate2, education3, educationDate3, volunteerWork1Where,
      volunteerWork1Duty1, volunteerWork1Duty2, volunteerWork1Duty3,
      volunteerWork2Where, volunteerWork2Duty1, volunteerWork2Duty2,
      volunteerWork2Duty3, reference1Name, reference1Pos, reference1Phone,
      reference2Name, reference2Pos, reference2Phone, reference3Name,
      reference3Pos, reference3Phone, ref1Name, ref1Pos, ref1Phone, ref2Name,
      ref2Pos, ref2Phone, ref3Name, ref3Pos, ref3Phone, hasWork, hasSecondJob,
      didVolunteer, didVolunteer2);

  return 0;
}

void printInputSkills(char *skill1, char *skill2, char *skill3, char *skill4,
                      char *skill5, char *skill6, char *skill7, char *skill8,
                      char *skill9, char *skill10, char *skill11,
                      char *skill12) {

  printf("Skill 1: ");
  scanf("%[^\n]%*c", skill1);
  if (!isNone(skill1)) {
    printf("Skill 2 (type none if none): ");
    scanf("%[^\n]%*c", skill2);
    if (!isNone(skill2)) {
      printf("Skill 3 (type none if none): ");
      scanf("%[^\n]%*c", skill3);
      if (!isNone(skill3)) {
        printf("Skill 4 (type none if none): ");
        scanf("%[^\n]%*c", skill4);
        if (!isNone(skill4)) {
          printf("Skill 5 (type none if none): ");
          scanf("%[^\n]%*c", skill5);
          if (!isNone(skill5)) {
            printf("Skill 6 (type none if none): ");
            scanf("%[^\n]%*c", skill6);
            if (!isNone(skill6)) {
              printf("Skill 7 (type none if none): ");
              scanf("%[^\n]%*c", skill7);
              if (!isNone(skill7)) {
                printf("Skill 8 (type none if none): ");
                scanf("%[^\n]%*c", skill8);
                if (!isNone(skill8)) {
                  printf("Skill 9 (type none if none): ");
                  scanf("%[^\n]%*c", skill9);
                  if (!isNone(skill9)) {
                    printf("Skill 10 (type none if none): ");
                    scanf("%[^\n]%*c", skill10);
                    if (!isNone(skill10)) {
                      printf("Skill 11 (type none if none): ");
                      scanf("%[^\n]%*c", skill11);
                      if (!isNone(skill11)) {
                        printf("Skill 12 (type none if none): ");
                        scanf("%[^\n]%*c", skill12);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

void ifSkill(char *skill, int place) {
  if (place % 4 == 0) {
    printf("     %-29s\n", skill);
  } else if (place == 1) {
    printf("%-23s", skill);
  } else if (place % 4 == 1) {
    printf("                 %-23s", skill);
  } else {
    printf("     %-23s", skill);
  }
}

bool isNone(char *text) {
  return strcmp(text, "none") == 0 || strcmp(text, "") == 0;
}

bool isYes(char letter) { return letter == 'y' || letter == 'Y'; }

void printSkills(char *skill1, char *skill2, char *skill3, char *skill4,
                 char *skill5, char *skill6, char *skill7, char *skill8,
                 char *skill9, char *skill10, char *skill11, char *skill12) {
  ifSkill(skill1, 1);
  if (!isNone(skill2)) {
    ifSkill(skill2, 2);
    if (!isNone(skill3)) {
      ifSkill(skill3, 3);
      if (!isNone(skill4)) {
        ifSkill(skill4, 4);
        if (!isNone(skill5)) {
          ifSkill(skill5, 5);
          if (!isNone(skill6)) {
            ifSkill(skill6, 6);
            if (!isNone(skill7)) {
              ifSkill(skill7, 7);
              if (!isNone(skill8)) {
                ifSkill(skill8, 8);
                if (!isNone(skill9)) {
                  ifSkill(skill9, 9);
                  if (!isNone(skill10)) {
                    ifSkill(skill10, 10);
                    if (!isNone(skill11)) {
                      ifSkill(skill11, 11);
                      if (!isNone(skill12)) {
                        ifSkill(skill12, 12);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

void printResumeTemplate(
    char *name, char *address, char *city, char *postalCode, char *phone,
    char *jobObjective1, char *jobObjective2, char *jobObjective3,
    char *jobObjective4, char *skill1, char *skill2, char *skill3, char *skill4,
    char *skill5, char *skill6, char *skill7, char *skill8, char *skill9,
    char *skill10, char *skill11, char *skill12, char *jobTitle1, char *from1,
    char *to1, char *company1, char *companyAddress1, char *firstDuty1,
    char *firstDuty2, char *firstDuty3, char *firstDuty4, char *firstDuty5,
    char *firstDuty6, char *jobTitle2, char *from2, char *to2, char *company2,
    char *companyAddress2, char *secondDuty1, char *secondDuty2,
    char *secondDuty3, char *secondDuty4, char *secondDuty5, char *secondDuty6,
    char *education1, char *educationDate1, char *education2,
    char *educationDate2, char *education3, char *educationDate3,
    char *volunteerWork1Where, char *volunteerWork1Duty1,
    char *volunteerWork1Duty2, char *volunteerWork1Duty3,
    char *volunteerWork2Where, char *volunteerWork2Duty1,
    char *volunteerWork2Duty2, char *volunteerWork2Duty3, char *reference1Name,
    char *reference1Pos, char *reference1Phone, char *reference2Name,
    char *reference2Pos, char *reference2Phone, char *reference3Name,
    char *reference3Pos, char *reference3Phone, char *ref1Name, char *ref1Pos,
    char *ref1Phone, char *ref2Name, char *ref2Pos, char *ref2Phone,
    char *ref3Name, char *ref3Pos, char *ref3Phone, char hasWork,
    char hasSecondJob, char didVolunteer, char didVolunteer2) {
  printf("Name:            %s\n", name);
  printf("Address:         %-49s         City: %-49s\n", address, city);
  printf("Postal Code:     %-49s   "
         "     Phone: %-49s\n",
         postalCode, phone);

  printf("\n");
  printf("  Job Objective: %-113s\n", jobObjective1);
  printf("                 %-113s\n", jobObjective2);
  printf("                 %-113s\n", jobObjective3);
  printf("                 %-113s\n", jobObjective4);

  printf("\n");

  printf("     Skill List: ");
  printSkills(skill1, skill2, skill3, skill4, skill5, skill6, skill7, skill8,
              skill9, skill10, skill11, skill12);

  printf("\n");

  if (isYes(hasWork)) {
    printf("Work Experience:\n");
    if (isYes(hasSecondJob)) {
      printf("      Job Title: %-49s   "
             " Job Title: %-49s\n",
             jobTitle1, jobTitle2);
      printf("           From: %-16s             To: "
             "%-16s   "
             "      From: %-16s             To: %-16s\n",
             from1, to1, from2, to2);
      printf("        Company: "
             "%-49s   "
             "   Company: %-49s\n",
             company1, company2);
      printf("        Address: "
             "%-49s   "
             "   Address: %-49s\n",
             companyAddress1, companyAddress2);
      printf("         Duties: %-16s                 "
             "%-16s   "
             "    Duties: %-16s                 %-16s\n",
             firstDuty1, firstDuty2, secondDuty1, secondDuty2);
      printf("                 %-16s                 "
             "%-16s   "
             "            %-16s                 %-16s\n",
             firstDuty3, firstDuty4, secondDuty3, secondDuty4);
      printf("                 %-16s                 "
             "%-16s   "
             "            %-16s                 %-16s\n",
             firstDuty5, firstDuty6, secondDuty5, secondDuty6);

    } else {
      printf("      Job Title: %-49s\n", jobTitle1);
      printf("           From: %-16s             To: %-16s\n", from1, to1);
      printf("        Company: "
             "%-49s\n",
             company1);
      printf("        Address: "
             "%-49s\n",
             companyAddress1);
      printf("         Duties: %-20s         "
             "%-20s\n",
             firstDuty1, firstDuty2);
      printf("                 %-20s         "
             "%-20s\n",
             firstDuty3, firstDuty4);
      printf("                 %-20s         "
             "%-20s\n",
             firstDuty5, firstDuty6);
    }
    printf("\n");
  }

  printf("      Education:       Date                                       "
         "Type of Course/Degree and Where Taken\n");
  printf("                 %16s     "
         "%92s\n",
         educationDate1, education1);
  printf("                 %16s     "
         "%92s\n",
         educationDate2, education2);
  printf("                 %16s     "
         "%92s\n",
         educationDate3, education3);

  printf("\n");

  if (isYes(didVolunteer)) {
    printf(" Volunteer Work:                                                 "
           "    "
           "References:\n");
    printf("          Where: %-49s    "
           "  "
           "   Name: %-16s       Position: %-16s\n",
           volunteerWork1Where, ref1Name, ref1Pos);
    printf("         Duties: %-49s   "
           "     Phone: %-49s\n",
           volunteerWork1Duty1, ref1Phone);
    printf("                 %-49s\n", volunteerWork1Duty2);
    printf("                 %-49s    "
           "  "
           "   Name: %-16s       Position: %-16s        \n",
           volunteerWork1Duty3, ref2Name, ref2Pos);
    printf("                                                                 "
           "    "
           "     Phone: %-49s\n",
           ref2Phone);
    if (isYes(didVolunteer2)) {
      printf("          Where: %-49s\n", volunteerWork2Where);
      printf("         Duties: %-49s   "
             "      Name: %-16s       Position: %-16s\n",
             volunteerWork2Duty1, ref3Name, ref3Pos);
      printf("                 %-49s   "
             "     Phone: %-49s\n",
             volunteerWork2Duty2, ref3Phone);
      printf("                 %-49s\n", volunteerWork2Duty3);
    } else {
      printf("\n");
      printf("                                                                 "
             "          Name: %-16s       Position: %-16s\n",
             ref3Name, ref3Pos);
      printf("                                                                 "
             "         Phone: %-49s\n",
             ref3Phone);
    }
  }
}
