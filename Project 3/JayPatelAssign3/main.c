#include <stdio.h>
#include <string.h>
#include "Assign3.h"

//Structure for holding data
typedef struct {
    char races[50];
    char regions[50];
    char towns[70];
    int famSize;
    int testedMem;
    int posMember;
    int *ageOfPer;
    struct HouseholdData *next;
} HouseholdData;


int main() {

    HouseholdData *prev = NULL;
    HouseholdData *head = NULL;
    HouseholdData *temp = NULL;

    for (int i = 0; i < 100; i++) {

        int races[1], regions[1], towns[1], famMem[3];
        int ageOfPer[famMem[0]];
        generateRandomYetSortedIntegers(races, 1, 4, 0, 0);
        generateRandomYetSortedIntegers(regions, 1, 2, 0, 0);
        generateRandomYetSortedIntegers(towns, 1, 1, 0, 0);
        generateRandomYetSortedIntegers(famMem, 3, 12, 0, 0);
        generateRandomYetSortedIntegers(ageOfPer, famMem[0], 60, 2, 0);

        if (head == NULL) {
            head = (HouseholdData *) malloc(sizeof(HouseholdData));

            if (races[0] == 0) {
                strcpy(head->races, "Indigenous");
            } else if (races[0] == 1) {
                strcpy(head->races, "Caucasian");
            } else if (races[0] == 2) {
                strcpy(head->races, "African-American");
            } else if (races[0] == 3) {
                strcpy(head->races, "Asian");
            } else {
                strcpy(head->races, "Others");
            }

            if (regions[0] == 0) {
                strcpy(head->regions, "Durham");
                if (towns[0] == 0) {
                    strcpy(head->towns, "Whitby");
                } else {
                    strcpy(head->towns, "Oshawa");
                }
            } else if (regions[0] == 1) {
                strcpy(head->regions, "Peel");
                if (towns[0] == 0) {
                    strcpy(head->towns, "Brampton");
                } else {
                    strcpy(head->towns, "Mississauga");
                }
            } else if (regions[0] == 2) {
                strcpy(head->regions, "York");
                if (towns[0] == 0) {
                    strcpy(head->towns, "Maple");
                } else {
                    strcpy(head->towns, "Vaughan");
                }
                head->ageOfPer = (int *) malloc(sizeof(int) * famMem[0]);
                for (int i = 0; i < famMem[0]; i++) {
                    head->ageOfPer[i] = ageOfPer[i];
                }
            }

            head->famSize = famMem[2];
            head->testedMem = famMem[1];
            head->posMember = famMem[0];
            head->next = NULL;
            //prev = (HouseholdData*)malloc(sizeof(HouseholdData));
            prev = head;
        } else {
            temp = (HouseholdData *) malloc(sizeof(HouseholdData));
            temp->ageOfPer = (int *) malloc(sizeof(int) * famMem[0]);
            for (int i = 0; i < famMem[0]; i++) {
                temp->ageOfPer[i] = ageOfPer[i];
            }
            if (races[0] == 0) {
                strcpy(temp->races, "Indigenous");
            } else if (races[0] == 1) {
                strcpy(temp->races, "Caucasian");
            } else if (races[0] == 2) {
                strcpy(temp->races, "African-American");
            } else if (races[0] == 3) {
                strcpy(temp->races, "Asian");
            } else {
                strcpy(temp->races, "Others");
            }
            if (regions[0] == 0) {
                strcpy(temp->regions, "Durham");
                if (towns[0] == 0) {
                    strcpy(temp->towns, "Whitby");
                } else {
                    strcpy(temp->towns, "Oshawa");
                }
            } else if (regions[0] == 1) {
                strcpy(temp->regions, "Peel");
                if (towns[0] == 0) {
                    strcpy(temp->towns, "Brampton");
                } else {
                    strcpy(temp->towns, "Mississauga");
                }
            } else if (regions[0] == 2) {
                strcpy(temp->regions, "York");
                if (towns[0] == 0) {
                    strcpy(temp->towns, "Maple");
                } else {
                    strcpy(temp->towns, "Vaughan");
                }
            }

            temp->famSize = famMem[2];
            temp->testedMem = famMem[1];
            temp->posMember = famMem[0];

            temp->next = NULL;
            prev->next = (struct HouseholdData *) temp;
            prev = temp;
        }

    }
    puts("100 records written successfully as the text file: ..//data//clients.txt");
    printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
    int i = 1;
    HouseholdData *temp2 = (HouseholdData *) malloc(sizeof(HouseholdData));
    temp2 = head;
    while (head != NULL) {
        printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", i, head->famSize, head->testedMem, head->posMember,
               head->races, head->regions, head->towns);
        head = (HouseholdData *) head->next;
        i++;
    }
    head = temp2;
    puts("\n-------------------This program analyzes and stores information related to Covid-19 cases-------------------");
    puts("-------------------------and its impact on various races, regions and towns of GTA--------------------------");
    //  to come back
    mainMenu:

    puts("MENU:\n"
         "Enter yur choice to\n"
         "1.  Display households of a region\n"
         "2.  Display households of a town\n"
         "3.  Display households of a race\n"
         "4.  Display households of a region with a given minimum number of people tested positive for COVID-19\n"
         "5.  Display the regions town-wise ranking of number of people tested positive for COVID-19\n"
         "6.  Add a record\n"
         "7.  Delete all records of a region, town and race triplet \n"
         "8.  Display updated data\n"
         "9.  Store data to a file\n"
         "10. Display data from file\n"
         "0.  To exit the program\n");

    int usrEntry = 0;

    usrEntry = dataValidation(10);
    //HouseholdData* prev2 = (HouseholdData*)malloc(sizeof(HouseholdData));
    FILE * fptr;
    char filename[]="..//clients.txt";
    switch (usrEntry) {
        case 1:
            puts("Enter an integer for region: Durham(0), Peel(1), York(2)");
            int usrEn = 0;
            scanf("%d", &usrEn);

            temp2 = head;
            if (usrEn == 0) {
                char tempRegion[100];
                puts("Records with region: Durham");
                printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
                strcpy(tempRegion, "Durham");
                int dat = 0, count = 0;
                while (dat < 100) {
                    if (strcmp(temp2->regions, tempRegion) == 0) {
                        printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", ++count, temp2->famSize,
                               temp2->testedMem, temp2->posMember, temp2->races, temp2->regions, temp2->towns);
                    }
                    temp2 = (HouseholdData *) temp2->next;
                    dat++;
                }
                goto mainMenu;
            } else if (usrEn == 1) {
                char tempRegion[100];
                puts("Records with region: Peel");
                printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
                strcpy(tempRegion, "Peel");
                int dat = 0, count = 0;
                while (dat < 100) {
                    if (strcmp(temp2->regions, tempRegion) == 0) {
                        printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", ++count, temp2->famSize,
                               temp2->testedMem, temp2->posMember, temp2->races, temp2->regions, temp2->towns);
                    }
                    temp2 = (HouseholdData *) temp2->next;
                    dat++;
                }
                goto mainMenu;
            } else if (usrEn == 2) {
                char tempRegion[100];
                puts("Records with region: York");
                printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
                strcpy(tempRegion, "York");
                int dat = 0, count = 0;
                while (dat < 100) {
                    if (strcmp(temp2->regions, tempRegion) == 0) {
                        printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", ++count, temp2->famSize,
                               temp2->testedMem, temp2->posMember, temp2->races, temp2->regions, temp2->towns);
                    }
                    temp2 = (HouseholdData *) temp2->next;
                    dat++;
                }
                goto mainMenu;
            } else {
                puts("invalid entry!!");
                goto mainMenu;
            }

        case 2:
            puts("Enter an integer for town: : Whitby(0), Oshawa(1), Brampton(2), "
                 "Mississauga(3), Maple(4), Vaughan(5)");
            int us2 = 0;
            scanf("%d", &us2);
            temp2 = head;
            if (us2 == 0) {
                char tempTowns[100];
                puts("Records with town: Whitby");
                printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
                strcpy(tempTowns, "Whitby");
                int dat = 0, count = 0;
                while (dat < 100) {
                    if (strcmp(temp2->towns, tempTowns) == 0) {
                        printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", ++count, temp2->famSize,
                               temp2->testedMem, temp2->posMember, temp2->races, temp2->regions, temp2->towns);
                    }
                    temp2 = (HouseholdData *) temp2->next;
                    dat++;
                }
                goto mainMenu;
            } else if (us2 == 1) {
                char tempTowns[100];
                puts("Records with town: Oshawa");
                printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
                strcpy(tempTowns, "Oshawa");
                int dat = 0, count = 0;
                while (dat < 100) {
                    if (strcmp(temp2->towns, tempTowns) == 0) {
                        printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", ++count, temp2->famSize,
                               temp2->testedMem, temp2->posMember, temp2->races, temp2->regions, temp2->towns);
                    }
                    temp2 = (HouseholdData *) temp2->next;
                    dat++;
                }
                goto mainMenu;
            } else if (us2 == 2) {
                char tempTowns[100];
                puts("Records with town: Brampton");
                printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
                strcpy(tempTowns, "Brampton");
                int dat = 0, count = 0;
                while (dat < 100) {
                    if (strcmp(temp2->towns, tempTowns) == 0) {
                        printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", ++count, temp2->famSize,
                               temp2->testedMem, temp2->posMember, temp2->races, temp2->regions, temp2->towns);
                    }
                    temp2 = (HouseholdData *) temp2->next;
                    dat++;
                }
                goto mainMenu;
            } else if (us2 == 3) {
                char tempTowns[100];
                puts("Records with town: Mississauga");
                printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
                strcpy(tempTowns, "Mississauga");
                int dat = 0, count = 0;
                while (dat < 100) {
                    if (strcmp(temp2->towns, tempTowns) == 0) {
                        printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", ++count, temp2->famSize,
                               temp2->testedMem, temp2->posMember, temp2->races, temp2->regions, temp2->towns);
                    }
                    temp2 = (HouseholdData *) temp2->next;
                    dat++;
                }
                goto mainMenu;
            } else if (us2 == 4) {
                char tempTowns[100];
                puts("Records with town: Maple");
                printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
                strcpy(tempTowns, "Maple");
                int dat = 0, count = 0;
                while (dat < 100) {
                    if (strcmp(temp2->towns, tempTowns) == 0) {
                        printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", ++count, temp2->famSize,
                               temp2->testedMem, temp2->posMember, temp2->races, temp2->regions, temp2->towns);
                    }
                    temp2 = (HouseholdData *) temp2->next;
                    dat++;
                }
                goto mainMenu;
            } else if (us2 == 5) {
                char tempTowns[100];
                puts("Records with town: Vaughan");
                printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
                strcpy(tempTowns, "Vaughan");
                int dat = 0, count = 0;
                while (dat < 100) {
                    if (strcmp(temp2->towns, tempTowns) == 0) {
                        printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", ++count, temp2->famSize,
                               temp2->testedMem, temp2->posMember, temp2->races, temp2->regions, temp2->towns);
                    }
                    temp2 = (HouseholdData *) temp2->next;
                    dat++;
                }
                goto mainMenu;
            } else {
                puts("invalid entry!!");
                goto mainMenu;
            }

        case 3:
            puts("Enter an integer for race: Indigenous(0), Caucasian(1), African-American(2), Asian(3), Others(4)");
            int us3 = 0;
            scanf("%d", &us3);
            temp2 = head;
            if (us3 == 0) {
                char tempRaces[100];
                puts("Records with race: Indigenous");
                printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
                strcpy(tempRaces, "Indigenous");
                int dat = 0, count = 0;
                while (dat < 100) {
                    if (strcmp(temp2->races, tempRaces) == 0) {
                        printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", ++count, temp2->famSize,
                               temp2->testedMem, temp2->posMember, temp2->races, temp2->regions, temp2->towns);
                    }
                    temp2 = (HouseholdData *) temp2->next;
                    dat++;
                }
                goto mainMenu;
            } else if (us3 == 1) {
                char tempRaces[100];
                puts("Records with race: Caucasian");
                printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
                strcpy(tempRaces, "Caucasian");
                int dat = 0, count = 0;
                while (dat < 100) {
                    if (strcmp(temp2->races, tempRaces) == 0) {
                        printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", ++count, temp2->famSize,
                               temp2->testedMem, temp2->posMember, temp2->races, temp2->regions, temp2->towns);
                    }
                    temp2 = (HouseholdData *) temp2->next;
                    dat++;
                }
                goto mainMenu;
            } else if (us3 == 2) {
                char tempRaces[100];
                puts("Records with race: African-American");
                printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
                strcpy(tempRaces, "African-American");
                int dat = 0, count = 0;
                while (dat < 100) {
                    if (strcmp(temp2->races, tempRaces) == 0) {
                        printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", ++count, temp2->famSize,
                               temp2->testedMem, temp2->posMember, temp2->races, temp2->regions, temp2->towns);
                    }
                    temp2 = (HouseholdData *) temp2->next;
                    dat++;
                }
                goto mainMenu;
            } else if (us3 == 3) {
                char tempRaces[100];
                puts("Records with race: Asian");
                printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
                strcpy(tempRaces, "Asian");
                int dat = 0, count = 0;
                while (dat < 100) {
                    if (strcmp(temp2->races, tempRaces) == 0) {
                        printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", ++count, temp2->famSize,
                               temp2->testedMem, temp2->posMember, temp2->races, temp2->regions, temp2->towns);
                    }
                    temp2 = (HouseholdData *) temp2->next;
                    dat++;
                }
                goto mainMenu;
            } else if (us3 == 4) {
                char tempRaces[100];
                puts("Records with race: Others");
                printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
                strcpy(tempRaces, "Others");
                int dat = 0, count = 0;
                while (dat < 100) {
                    if (strcmp(temp2->races, tempRaces) == 0) {
                        printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", ++count, temp2->famSize,
                               temp2->testedMem, temp2->posMember, temp2->races, temp2->regions, temp2->towns);
                    }
                    temp2 = (HouseholdData *) temp2->next;
                    dat++;
                }
                goto mainMenu;
            } else {
                puts("invalid entry!!");
                goto mainMenu;
            }
        case 4:
            puts("Enter an integer for region: Durham(0), Peel(1), York(2)");
            int usr2 = 0;
            temp2 = head;
            scanf("%d", &usr2);
            if (usr2 > 2 || usr2 < 0) {
                puts("Invalid data, enter an integer o through 2 or enter 9 to go back to the main menu. try again.");
            } else if (usr2 == 9) {
                goto mainMenu;
            } else {
                puts("Enter lowerbound of number of Covid-19 positive cases per household in the region.");
                if (usr2 == 0) {
                    int usr3 = 0;
                    scanf("%d", &usr3);
                    char tempRegions[100];
                    strcpy(tempRegions, "Durham");

                    int dat = 0, count = 0;
                    printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
                    while (dat < 100) {
                        if (strcmp(temp2->regions, tempRegions) == 0 && (temp2->posMember) >= usr3) {

                            printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", ++count, temp2->famSize,
                                   temp2->testedMem, temp2->posMember, temp2->races, temp2->regions, temp2->towns);
                        }
                        temp2 = (HouseholdData *) temp2->next;
                        dat++;
                    }
                    goto mainMenu;
                } else if (usr2 == 1) {
                    int usr3 = 0;
                    scanf("%d", &usr3);
                    char tempRegions[100];
                    strcpy(tempRegions, "Peel");

                    int dat = 0, count = 0;
                    printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
                    while (dat < 100) {
                        if (strcmp(temp2->regions, tempRegions) == 0 && (temp2->posMember) >= usr3) {

                            printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", ++count, temp2->famSize,
                                   temp2->testedMem, temp2->posMember, temp2->races, temp2->regions, temp2->towns);
                        }
                        temp2 = (HouseholdData *) temp2->next;
                        dat++;
                    }
                    goto mainMenu;
                } else {
                    int usr3 = 0;
                    scanf("%d", &usr3);
                    char tempRegions[100];
                    strcpy(tempRegions, "York");

                    int dat = 0, count = 0;
                    printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
                    while (dat < 100) {
                        if (strcmp(temp2->regions, tempRegions) == 0 && (temp2->posMember) >= usr3) {

                            printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", ++count, temp2->famSize,
                                   temp2->testedMem, temp2->posMember, temp2->races, temp2->regions, temp2->towns);
                        }
                        temp2 = (HouseholdData *) temp2->next;
                        dat++;
                    }
                    goto mainMenu;
                }
            }
            break;
        case 5:
            puts("Tested Positive Covid-19 cases:");
            int posDu = 0, posPe = 0, posYo = 0;
            char tempRegions[100];
            temp2 = head;
            for (int j = 0; j < 100; j++) {
                if (strcmp(temp2->regions, "Durham") == 0) {
                    posDu = posDu + (temp2->posMember);
                } else if (strcmp(temp2->regions, "Peel") == 0) {

                    posPe = posPe + (temp2->posMember);
                } else if (strcmp(temp2->regions, "York") == 0) {
                    
                    posYo = posYo + (temp2->posMember);
                }
            }
            if (posDu > posPe && posDu > posYo) {
                if (posYo < posDu && posYo > posPe) {
                    puts("Region-wise ranking:");
                    puts("\t\tPEEL : 3 "
                         "\n\t\tDURHAM : 1"
                         "\n\t\tYORK : 2");
                } else {
                    puts("Region-wise ranking:");
                    puts("\t\tPEEL : 2 "
                         "\n\t\tDURHAM : 1"
                         "\n\t\tYORK : 3");
                }
            } else if (posYo > posDu && posYo > posPe) {
                if (posDu < posYo && posDu > posPe) {
                    puts("Region-wise ranking:");
                    puts("\t\tPEEL : 3 "
                         "\n\t\tDURHAM : 2"
                         "\n\t\tYORK : 1");
                } else {
                    puts("Region-wise ranking:");
                    puts("\t\tPEEL : 2 "
                         "\n\t\tDURHAM : 3"
                         "\n\t\tYORK : 1");
                }

            } else {
                if (posDu < posPe && posDu > posYo) {
                    puts("Region-wise ranking:");
                    puts("\t\tPEEL : 1 "
                         "\n\t\tDURHAM : 2"
                         "\n\t\tYORK : 3");
                } else {
                    puts("Region-wise ranking:");
                    puts("\t\tPEEL : 1 "
                         "\n\t\tDURHAM : 3"
                         "\n\t\tYORK : 2");
                }

            }
            puts("Town-wise ranking:");
            goto mainMenu;

        case 6:
            printf("\nData entry for household# %d", i);
            puts("\nrace: enter an integer: Indigenous(0), Caucasian(1), African-American(2), Asian(3), Others(4)");
            int usrEntry = dataValidation(4);
            puts("region: enter an integer: Durham(0), Peel(1), York(2)");
            //will validate data
            int regTemp = dataCheck(2);
            if (regTemp == 0){
                puts("town: enter an integer: Whitby(0), Oshawa(1)");
                int townTemp = dataCheck(1);
            } else if(regTemp == 1){
                puts("town: enter an integer: Brampton(0), Mississauga(1)");
                int townTemp = dataCheck(1);
            }
            else{
                puts("town: enter an integer: Maple(0), Vaughan(1)");
                int townTemp = dataCheck(1);
            }
            puts("\nEnter num of mem, tested for covid, pos for covid:");
            int tot=0,pos=0,tes=0;
            scanf("%d\t %d\t%d",&tot,&tes,&pos);
            goto mainMenu;
        case 7:
//
//            puts("Enter an integer for region: Durham(0), Peel(1), York(2)");
//            int usr1=0, usr2=0, usr3=0;
//            scanf("%d", &usr1);
//            if(usr1==0){
//                strcpy(tempRegion,"Durham");
//                puts("town: enter an integer: Whitby(0), Oshawa(1)");
//                scanf("%d", &usr2);
//                if(usr2==0){
//                    strcpy(tempTowns,"Whitby");
//                }else{
//                    strcpy(tempTowns,"Oshawa");
//                }
//            } else if(usr1==1){
//                strcpy(tempRegion,"Peel");
//                puts("town: enter an integer: Brampton(0), Mississauga(1)");
//                scanf("%d", &usr2);
//                if(usr2==0){
//                    strcpy(tempTowns,"Brampton");
//                }else{
//                    strcpy(tempTowns,"Mississauga");
//                }
//            } else{
//                strcpy(tempRegion,"York");
//                puts("town: enter an integer: Maple(0), Vaughan(1)");
//                scanf("%d", &usr2);
//                if(usr2==0){
//                    strcpy(tempTowns,"Maple");
//                }else{
//                    strcpy(tempTowns,"Vaughan");
//                }
//            }
//            puts("\nrace: enter an integer: Indigenous(0), Caucasian(1), African-American(2), Asian(3), Others(4)");
//            scanf("%d", &usr3);
//            if (usr3 == 0){
//                strcpy(tempRaces,"Indigenous");
//
//            } else if (usr3 == 1){
//                strcpy(tempRaces,"Caucasian");
//            }
//            else if (usr3 == 2){
//                strcpy(tempRaces,"African-American");
//            }
//            else if (usr3 == 3){
//                strcpy(tempRaces,"Asian");
//            }
//            else {
//                strcpy(tempRaces,"Others");
//            }
//            temp2 = head;
//            prev2 = head;
//            while(temp2!=NULL){
//                if(strcmp(temp2->regions,tempRegion)==0){
//                    if(strcmp(temp2->towns,tempTowns)==0){
//                        if(strcmp(temp2->races,tempRaces)==0){
//                            if(prev2==head){
//                                head = (HouseholdData *) head->next;
//                                free(temp2);
//                                break;
//                            } else{
//                                prev2->next = temp2->next;
//                                free(temp2);
//                                break;
//                            }
//                        }
//                    }
//                }
//                prev2 = temp2;
//                temp2 = (HouseholdData *) temp2->next;
//            }
            break;
        case 8:
            break;
        case 9:
            fptr = fopen (filename,"w");
            puts("Successfully stored data at file.");
            temp2 = head;
            for(int k = 1; k < 101;k++)
            {
                fprintf(fptr,"%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n", k, temp2->famSize,
                        temp2->testedMem, temp2->posMember, temp2->races, temp2->regions, temp2->towns);
                temp2 = (HouseholdData *) temp2->next;
            }

            fclose (fptr);

            goto mainMenu;
        case 10:
            puts("Displaying the data from the file.");
            fptr = fopen (filename,"r");
            temp2 = head;
            char tempRegion[100],tempRace[100],tempTown[100];
            int tempCount[100],tempFamSize[100],tempTestedMem[100],tempPosMember[100];
            int k=0;
            fscanf(fptr,"%d%d%d%d%s%s%s", tempCount,tempFamSize,tempTestedMem,tempPosMember,
                   tempRace,tempRegion,tempTown);
            printf("S.no\tSize\tTotal tested\tTotal tested positive\tRace\t\t  Region\t   Town\n");
            while (!feof(fptr)){
                fscanf(fptr,"%d%d%d%d%s%s%s", tempCount,tempFamSize,tempTestedMem,tempPosMember,
                       tempRace,tempRegion,tempTown);

                printf("%d\t%d\t\t %d\t  %d\t\t\t%9.9s\t%9.9s\t%9.9s\n",*tempCount,*tempFamSize,*tempTestedMem,*tempPosMember,
                       tempRace,tempRegion,tempTown);
            }
            fclose (fptr);
            goto mainMenu;
        case 0:
            exit(0);
        default:
            puts("Sorry! Invalid entry! Please try again.");
            goto mainMenu;

    }

    return 0;
}



