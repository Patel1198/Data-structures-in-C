#include <stdio.h>
#include <string.h>
#include "Assign2.h"

//Structure for holding data
typedef struct {
    char races[50];
    char regions[50];
    char towns[70];
    int income;
    int famSize;
    int testedMem;
    int posMember;
} HouseholdData;

//to display data
void Display();

int main() {
    Display();
    // instance of structure
    HouseholdData household[100] ;
    int usrCount = 0;
    //for manual data entry
    for(int i=0; i<3; i++){
        printf("\nData entry for household# %d", i);
        puts("\nrace: enter an integer: Indigenous(0), Caucasian(1), African-American(2), Asian(3), Others(4)");
        //will validate data
        int usrEntry = dataValidation(4);
        //if 9 then skip the manual entry
        if (usrEntry == 9){
            puts("Skipping manual data entry and generating records randomly......");
            break;
        }
            //will take manual entry
        else {
            // will copy data to structure
            if(usrEntry==0){
                strcpy(household[usrCount].races, "Indigenous");
            } else if(usrEntry==1){
                strcpy(household[usrCount].races, "Caucasian");
            } else if(usrEntry==2){
                strcpy(household[usrCount].races, "African-American");
            } else if(usrEntry==3){
                strcpy(household[usrCount].races, "Asian");
            } else{
                strcpy(household[usrCount].races, "Others");
            }

        }
        //will take input for region
        puts("region: enter an integer: Durham(0), Peel(1), York(2)");
        //will validate data
        usrEntry = dataCheck(2);

        if(usrEntry==0){
            strcpy(household[usrCount].regions, "Durham");
            //will take input for town
            puts("town: enter an integer: Whitby(0), Oshawa(1)");
            int townTemp = dataCheck(1);
            // will copy data to structure
            if(townTemp==0){
                strcpy(household[usrCount].towns, "Whitby");
            } else{
                strcpy(household[usrCount].towns, "Oshawa");
            }

        } else if(usrEntry==1){
            strcpy(household[usrCount].regions, "Peel");
            //will take input for town
            puts("town: enter an integer: Brampton(0), Mississauga(1)");
            int townTemp = dataCheck(1);
            // will copy data to structure
            if(townTemp==0){
                strcpy(household[usrCount].towns, "Brampton");
            } else{
                strcpy(household[usrCount].towns, "Mississauga");
            }

        } else if(usrEntry==2){
            strcpy(household[usrCount].regions, "York");
            //will take input for town
            puts("town: enter an integer: Maple(0), Vaughan(1)");
            int townTemp = dataCheck(1);
            // will copy data to structure
            if(townTemp==0){
                strcpy(household[usrCount].towns, "Maple");
            } else{
                strcpy(household[usrCount].towns, "Vaughan");
            }
        }

        puts("Enter annual household income:\nNote!it will be rounded down to the next nearest hundred.");
        int tempInc;
        scanf("%d", &tempInc);
        household[usrCount].income = ((tempInc+99)/100)*100;
        puts("\nEnter num of mem, tested for covid, pos for covid:");
        scanf("%d\t %d\t%d", &household[usrCount].famSize, &household[usrCount].testedMem, &household[usrCount].posMember);
        usrCount = usrCount + 1;
    }
    puts("contents to file written successfully");
    // will generate random data for 100 household
    for(int j=usrCount; j<100; j++){
        int races[1], regions[1], towns[1], income[1], members[3];
        generateRandomYetSortedIntegers(races, 1, 4, 0, 0);
        if(races[0]==0){
            strcpy(household[j].races, "Indigenous");
        } else if(races[0]==1){
            strcpy(household[j].races, "Caucasian");
        } else if(races[0]==2){
            strcpy(household[j].races, "African-American");
        } else if(races[0]==3){
            strcpy(household[j].races, "Asian");
        } else{
            strcpy(household[j].races, "Others");
        }
        generateRandomYetSortedIntegers(regions, 1, 2, 0, 0);
        generateRandomYetSortedIntegers(towns, 1, 1, 0, 0);
        if(regions[0]==0){
            strcpy(household[j].regions, "Durham");

            if(towns[0]==0){
                strcpy(household[j].towns, "Whitby");
            } else{
                strcpy(household[j].towns, "Oshawa");
            }

        } else if(regions[0]==1){
            strcpy(household[j].regions, "Peel");

            if(towns[0]==0){
                strcpy(household[j].towns, "Brampton");
            } else{
                strcpy(household[j].towns, "Mississauga");
            }

        } else if(regions[0]==2){
            strcpy(household[j].regions, "York");

            if(towns[0]==0){
                strcpy(household[j].towns, "Maple");
            } else{
                strcpy(household[j].towns, "Vaughan");
            }

        }
        generateRandomYetSortedIntegers(income, 1, 50000, 15000, 1);
        household[j].income = income[0];
        generateRandomYetSortedIntegers(members, 3, 7, 0, 0);
        household[j].famSize = members[0];
        household[j].testedMem = members[1];
        household[j].posMember = members[2];
    }
    printf("Sr no.\tRace\t\t   Region\t   Town\t\tIncome\tFamily Size"
           "\t\tCovid Tested\tCovid Positive\n");
    for(int i=0; i<100; i++){
        printf("%d\t%9.9s\t%9.9s\t%9.9s\t%d\t\t%d\t\t%d\t\t%d\n",
               (i+1), household[i].races, household[i].regions,household[i].towns,
               household[i].income,household[i].famSize, household[i].testedMem,household[i].posMember);
    }
    //  to come back
    mainMenu:
    {
        int usrEntry;
        // main menu
        puts("-------------------Above household information is obtained from voluntary contributors to the survey--------------------\n");
        puts("Main menu:\n");

        puts("Enter your choice to display");
        puts("1. Household records by races, regions,or towns");
        puts("2. races ranking for Covid-19");
        puts("3. regions ranking for Covid-19");
        puts("4. towns ranking for Covid-19");
        puts("5. races ranking by poverty");
        puts("0. Exit");
        scanf("%d", &usrEntry);

        if (usrEntry == 1) {
            //will print data based on selection
            puts("Enter an integer to see household records of a particular race (0), region (1), or town (2)");
            int usr = dataValidation(2);
            if (usr == 0) {
                char tempRace[100];
                puts("\nrace: enter an integer: Indigenous(0), Caucasian(1), African-American(2), Asian(3), Others(4)");
                int op = dataValidation(4);
                if (op == 0) {
                    strcpy(tempRace, "Indigenous");
                } else if (op == 1) {
                    strcpy(tempRace, "Caucasian");
                } else if (op == 2) {
                    strcpy(tempRace, "African-American");
                } else if (op == 3) {
                    strcpy(tempRace, "Asian");
                } else {
                    strcpy(tempRace, "Others");
                }
                printf("Sr no.\tRace\t\t   Region\t   Town\t\tIncome\tFamily Size\t\tCovid Tested\tCovid Positive\n");
                int dat = 0;
                while (dat < 100) {
                    if (strcmp(household[dat].races, tempRace) == 0) {
                        printf("%d\t%9.9s\t%9.9s\t%9.9s\t%d\t\t%d\t\t%d\t\t%d\n", (dat + 1), household[dat].races,
                               household[dat].regions,
                               household[dat].towns, household[dat].income, household[dat].famSize,
                               household[dat].testedMem,
                               household[dat].posMember);
                    }
                    dat++;
                }
                goto mainMenu;
            } else if (usr == 1) {
                char tempRegion[100];
                puts("Regions: Enter an integer: Durham(0), Peel(1), York(2)");
                int op = dataValidation(2);
                if (op == 0) {
                    strcpy(tempRegion, "Durham");
                } else if (op == 1) {
                    strcpy(tempRegion, "Peel");
                } else {
                    strcpy(tempRegion, "York");
                }
                printf("Sr no.\tRace\t\t   Region\t   Town\t\tIncome\tFamily Size\t\tCovid Tested\tCovid Positive\n");
                int dat = 0;
                while (dat < 100) {
                    if (strcmp(household[dat].regions, tempRegion) == 0) {
                        printf("%d\t%9.9s\t%9.9s\t%9.9s\t%d\t\t%d\t\t%d\t\t%d\n", (dat + 1), household[dat].races,
                               household[dat].regions,
                               household[dat].towns, household[dat].income, household[dat].famSize,
                               household[dat].testedMem,
                               household[dat].posMember);
                    }
                    dat++;
                }
                goto mainMenu;
            } else {
                char tempTowns[100];
                puts("Towns: Enter an integer: Whitby(0), Oshawa(1), Brampton(2), "
                     "Mississauga(3), Maple(4), Vaughan(5)");
                int op = dataValidation(5);
                if (op == 0) {
                    strcpy(tempTowns, "Whitby");
                } else if (op == 1) {
                    strcpy(tempTowns, "Oshawa");
                } else if (op == 2) {
                    strcpy(tempTowns, "Brampton");
                } else if (op == 3) {
                    strcpy(tempTowns, "Mississauga");
                } else if (op == 4) {
                    strcpy(tempTowns, "Maple");
                } else {
                    strcpy(tempTowns, "Vaughan");
                }
                printf("Sr no.\tRace\t\t   Region\t   Town\t\tIncome\tFamily Size\t\tCovid Tested\tCovid Positive\n");
                int dat = 0;
                while (dat < 100) {
                    if (strcmp(household[dat].towns, tempTowns) == 0) {
                        printf("%d\t%9.9s\t%9.9s\t%9.9s\t%d\t\t%d\t\t%d\t\t%d\n", (dat + 1), household[dat].races,
                               household[dat].regions,
                               household[dat].towns, household[dat].income, household[dat].famSize,
                               household[dat].testedMem,
                               household[dat].posMember);
                    }
                    dat++;
                }
            }
            goto mainMenu;
        }
        else if(usrEntry == 2) {
            //will print data based on selection
            puts("Enter 0 to see all Covid-19 cases tested or \n1 for only tested positive cases or\n"
                 "9 to go back to main menu");
            int ops;
            scanf("%d",&ops);
            if (ops ==0){
                int raceI=0, raceC=0, raceA=0, raceAs=0, raceO=0;
                for (int i = 0; i < 100; i++) {
                    if(strcmp(household[i].races, "Indigenous")==0){
                        raceI = raceI + household[i].testedMem;
                    } else if(strcmp(household[i].races, "Caucasian")==0){
                        raceC = raceC + household[i].testedMem;
                    } else if(strcmp(household[i].races, "African-American")==0){
                        raceA = raceA + household[i].testedMem;
                    } else if(strcmp(household[i].races, "Asian")==0){
                        raceAs = raceAs + household[i].testedMem;
                    } else{
                        raceO = raceO + household[i].testedMem;
                    }
                }
                puts("------------Races ranking of Covid-19------------\n");
                printf("Races :\t Covid Tested\n");
                printf("African-American : \t %d\n", raceA);
                printf("Asian : \t%d\n", raceAs);
                printf("Indigenous : \t%d\n", raceI);
                printf("Caucasian : \t%d\n", raceC);
                printf("Others : \t%d\n", raceO);
                puts("\n-------------------Above household information is obtained from voluntary contributors to the survey--------------------\n");
                goto mainMenu;
            }else if (ops ==1){
                int raceI=0, raceC=0, raceA=0, raceAs=0, raceO=0;
                for (int i = 0; i < 100; i++) {
                    if(strcmp(household[i].races, "Indigenous")==0){
                        raceI = raceI + household[i].posMember;
                    } else if(strcmp(household[i].races, "Caucasian")==0){
                        raceC = raceC + household[i].posMember;
                    } else if(strcmp(household[i].races, "African-American")==0){
                        raceA = raceA + household[i].posMember;
                    } else if(strcmp(household[i].races, "Asian")==0){
                        raceAs = raceAs + household[i].posMember;
                    } else{
                        raceO = raceO + household[i].posMember;
                    }
                }
                puts("------------Races ranking of Covid-19------------\n");
                printf("Races :\t Covid Positive\n");
                printf("African-American : \t %d\n", raceA);
                printf("Asian : \t%d\n", raceAs);
                printf("Indigenous : \t%d\n", raceI);
                printf("Caucasian : \t%d\n", raceC);
                printf("Others : \t%d\n", raceO);
                puts("\n-------------------Above household information is obtained from voluntary contributors to the survey--------------------\n");
                goto mainMenu;
            } else{
                goto mainMenu;            }
        }
        else if (usrEntry == 3) {
            //will print data based on selection
            puts("Enter 0 to see all Covid-19 cases tested or \n1 for only tested positive cases or\n"
                 "9 to go back to main menu");
            int ops;
            scanf("%d",&ops);
            if (ops ==0){
                int regD=0, regP=0, regY=0;
                for (int i = 0; i < 100; i++) {
                    if(strcmp(household[i].regions, "Durham")==0){
                        regD = regD + household[i].testedMem;
                    } else if(strcmp(household[i].regions, "Peel")==0){
                        regP = regP + household[i].testedMem;
                    } else {
                        regY = regY + household[i].testedMem;
                    }
                }
                puts("------------Races ranking of Covid-19------------\n");
                printf("Regions :\t Covid Tested\n");
                printf("Durham : \t %d\n", regD);
                printf("Peel : \t%d\n", regP);
                printf("York : \t%d\n", regY);

                puts("\n-------------------Above household information is obtained from voluntary contributors to the survey--------------------\n");
                goto mainMenu;
            }else if (ops ==1){
                int regD=0, regP=0, regY=0;
                for (int i = 0; i < 100; i++) {
                    if(strcmp(household[i].regions, "Durham")==0){
                        regD = regD + household[i].posMember;
                    } else if(strcmp(household[i].regions, "Peel")==0){
                        regP = regP + household[i].posMember;
                    } else {
                        regY = regY + household[i].posMember;
                    }
                }
                puts("------------Races ranking of Covid-19------------\n");
                printf("Regions :\t Covid Positive\n");
                printf("Durham : \t %d\n", regD);
                printf("Peel : \t%d\n", regP);
                printf("York : \t%d\n", regY);

                puts("\n-------------------Above household information is obtained from voluntary contributors to the survey--------------------\n");
                goto mainMenu;
            } else{
                goto mainMenu;
            }

        }else if (usrEntry == 4) {
            //will print data based on selection
            puts("Enter 0 to see all Covid-19 cases tested or \n1 for only tested positive cases or\n"
                 "9 to go back to main menu");
            int ops;
            scanf("%d",&ops);
            if (ops ==0){
                int towB=0, towM=0, towO=0, towW=0, towMa=0, towV=0;
                for (int i = 0; i < 100; i++) {
                    if(strcmp(household[i].towns, "Brampton")==0){
                        towB = towB + household[i].testedMem;
                    } else if(strcmp(household[i].towns, "Mississauga")==0){
                        towM = towM + household[i].testedMem;
                    }else if(strcmp(household[i].towns, "Oshawa")==0){
                        towO = towO + household[i].testedMem;
                    }else if(strcmp(household[i].towns, "Whitby")==0){
                        towW = towW + household[i].testedMem;
                    }else if(strcmp(household[i].towns, "Maple")==0){
                        towMa = towMa + household[i].testedMem;
                    } else {
                        towV = towV + household[i].testedMem;
                    }
                }
                puts("------------Races ranking of Covid-19------------\n");
                printf("Towns :\t Covid Tested\n");
                printf("Brampton : \t %d\n", towB);
                printf("Mississauga : \t%d\n", towM);
                printf("Oshawa : \t%d\n", towO);
                printf("Whitby : \t%d\n", towW);
                printf("Maple : \t%d\n", towMa);
                printf("Vaughan : \t%d\n", towV);

                puts("\n-------------------Above household information is obtained from voluntary contributors to the survey--------------------\n");
                goto mainMenu;
            }else if (ops ==1){
                int towB=0, towM=0, towO=0, towW=0, towMa=0, towV=0;
                for (int i = 0; i < 100; i++) {
                    if(strcmp(household[i].towns, "Brampton")==0){
                        towB = towB + household[i].posMember;
                    } else if(strcmp(household[i].towns, "Mississauga")==0){
                        towM = towM + household[i].posMember;
                    }else if(strcmp(household[i].towns, "Oshawa")==0){
                        towO = towO + household[i].posMember;
                    }else if(strcmp(household[i].towns, "Whitby")==0){
                        towW = towW + household[i].posMember;
                    }else if(strcmp(household[i].towns, "Maple")==0){
                        towMa = towMa + household[i].posMember;
                    } else {
                        towV = towV + household[i].posMember;
                    }
                }
                puts("------------Races ranking of Covid-19------------\n");
                printf("Towns :\t Covid Positive\n");
                printf("Brampton : \t %d\n", towB);
                printf("Mississauga : \t%d\n", towM);
                printf("Oshawa : \t%d\n", towO);
                printf("Whitby : \t%d\n", towW);
                printf("Maple : \t%d\n", towMa);
                printf("Vaughan : \t%d\n", towV);


                puts("\n-------------------Above household information is obtained from voluntary contributors to the survey--------------------\n");
                goto mainMenu;
            } else{
                goto mainMenu;
            }

        }else if (usrEntry == 5) {
            //will print data based on selection
            int povIn=0, povCa=0, povAf=0, povAsi=0, povOt=0;
            int povI=0, povC=0, povA=0, povAs=0, povO=0;
            for (int i = 0; i < 100; i++) {
                if (strcmp(household[i].races, "Indigenous") == 0) {
                    povIn++;
                    if (household[i].famSize == 1 && household[i].income < 20000) {
                        povI = povI + 1;
                    } else if (household[i].famSize == 2 && household[i].income < 25000) {
                        povI = povI + 1;
                    } else if (household[i].famSize == 3 && household[i].income < 30000) {
                        povI = povI + 1;
                    } else if (household[i].famSize == 4 && household[i].income < 35000) {
                        povI = povI + 1;
                    } else if (household[i].famSize >= 5 && household[i].income < 40000) {
                        povI = povI + 1;
                    }

                } else if (strcmp(household[i].races, "Caucasian") == 0) {
                    povCa++;
                    if (household[i].famSize == 1 && household[i].income < 20000) {
                        povC = povC + 1;
                    } else if (household[i].famSize == 2 && household[i].income < 25000) {
                        povC = povC + 1;
                    } else if (household[i].famSize == 3 && household[i].income < 30000) {
                        povC = povC + 1;
                    } else if (household[i].famSize == 4 && household[i].income < 35000) {
                        povC = povC + 1;
                    } else if (household[i].famSize >= 5 && household[i].income < 40000) {
                        povC = povC + 1;
                    }

                } else if (strcmp(household[i].races, "African-American") == 0) {
                    povAf++;
                    if (household[i].famSize == 1 && household[i].income < 20000) {
                        povA = povA + 1;
                    } else if (household[i].famSize == 2 && household[i].income < 25000) {
                        povA = povA + 1;
                    } else if (household[i].famSize == 3 && household[i].income < 30000) {
                        povA = povA + 1;
                    } else if (household[i].famSize == 4 && household[i].income < 35000) {
                        povA = povA + 1;
                    } else if (household[i].famSize >= 5 && household[i].income < 40000) {
                        povA = povA + 1;
                    }

                } else if (strcmp(household[i].races, "Asian") == 0) {
                    povAsi++;
                    if (household[i].famSize == 1 && household[i].income < 20000) {
                        povAs = povAs + 1;
                    } else if (household[i].famSize == 2 && household[i].income < 25000) {
                        povAs = povAs + 1;
                    } else if (household[i].famSize == 3 && household[i].income < 30000) {
                        povAs = povAs + 1;
                    } else if (household[i].famSize == 4 && household[i].income < 35000) {
                        povAs = povAs + 1;
                    } else if (household[i].famSize >= 5 && household[i].income < 40000) {
                        povAs = povAs + 1;
                    }

                }else {
                    povOt++;
                    if (household[i].famSize == 1 && household[i].income < 20000) {
                        povO = povO + 1;
                    } else if (household[i].famSize == 2 && household[i].income < 25000) {
                        povO = povO + 1;
                    } else if (household[i].famSize == 3 && household[i].income < 30000) {
                        povO = povO + 1;
                    } else if (household[i].famSize == 4 && household[i].income < 35000) {
                        povO = povO + 1;
                    } else if (household[i].famSize >= 5 && household[i].income < 40000) {
                        povO = povO + 1;
                    }


                }
            }
            //will print data in %
            puts("Race : Percent households below poverty line\n");
            printf("African-American : \t %.0f%%\n", ((float)povA/povAf * 100));
            printf("Asian : \t %.0f%%\n", ((float)povAs/povAsi * 100));
            printf("Indigenous : \t %.0f%%\n", ((float)povI/povIn * 100));
            printf("Caucasian : \t %.0f%%\n", ((float)povC/povCa * 100));
            printf("Others : \t %.0f%%\n", ((float)povO/povOt * 100));
            goto mainMenu;

        }else if (usrEntry == 0) {
            exit(0);
        } else{
            puts("You entered invalid data!!");
            goto mainMenu;
        }}
    return 0;
}

//will display data
void Display(){
    puts("-------------------------This program analyzes and stores information related to Covid-19 cases-------------------------");
    puts("--------------------------------and its impact on various races, regions and towns of GTA-------------------------------");
    puts("-------------------------------------------------Manual data entry module-----------------------------------------------");
    puts("Provide data of up to three households or enter 9 to skip manual data entry and to generate records randomly");
}

