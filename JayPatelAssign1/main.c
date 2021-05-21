#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// functions
void display(); // to display grid
void userFirEntry(); // to take first input
void userSecEntry(); // to take second input
int rowFirCheck(int testGrid[9][9]); // to check 1st input row
int rowCheck(int testGrid[9][9]); // to check rows
int rowSecCheck(int testGrid[9][9]); // to check 2nd input row
int columnCheck(int testGrid[9][9]); // to check the columns
void randomNum(int testGrid[9][9]); // to generate random numbers


int testGrid[ ][ 9 ] = {{5,3,4,6,7,8,9,1,2}, {6,7,2,1,9,5,3,4,8},{1,9,8,3,4,2,5,6,7},
                        {8,5,9,7,6,1,4,2,3},{4,2,6,8,5,3,7,9,1},{7,1,3,9,2,4,8,5,6},
                        {9,6,1,5,3,7,2,8,4},{2,8,7,4,1,9,6,3,5},{3,4,5,2,8,6,1,7,9}};

int main() {

    display(); // to display Sudoku
    userFirEntry(); // to take first input
    userSecEntry(); // to take second input
    randomNum(testGrid); // to generate random numbers
    display(); // to display Sudoku
    return 0;
}
void display(){
    //Displaying array elements
    printf("-----------------Sudoku Grid-----------------\n");
    for(int i=0; i<9; i++) {
        for(int j=0;j<9;j++) {
            printf("  %d  ", testGrid[i][j]);
            if(j==8){
                printf("\n");
            }
        }
    }
    // will check validity of grid
    if (rowCheck(testGrid)){
        if (columnCheck(testGrid)){
            puts("Given Sudoku grid is valid");
        }
    } else{
        puts("It is invalid Sudoku grid.");
    }



}

void userFirEntry(){
    int buff[9][9];
    int cnt=1;
    puts("Enter row 1 of your Sudoku grid");
    // will check for entered numbers
    while (cnt != 9){
        puts("Use Space/Tab/Return key to enter the next values\n"
             "and press 'Return' after entering nine integers."
             "\nRemember, to make a valid row of Sudoku grid,\n"
             "all integers should be distinct and range from 1 to 9");
        fgets(buff,sizeof(buff),stdin );
        cnt = sscanf(buff,"%d%d%d%d%d%d%d%d%d",&testGrid[0][0], &testGrid[0][1], &testGrid[0][2],
                     &testGrid[0][3],&testGrid[0][4],&testGrid[0][5],&testGrid[0][6],
                     &testGrid[0][7],&testGrid[0][8]);

        // will check number of entries
        if (cnt != 9 ) {
            puts("Please, Enter exactly nine INTEGERS separated by Space/Tab followed by Enter key to end");
        }else
        {
            // will check range of entry
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 9; j++) {
                    if (testGrid[i][j] < 0 || testGrid[i][j] > 9){
                        puts("one or more entries are outside the range 1 to 9!");
                        userFirEntry();
                    }
                }
            }
        }
        rowFirCheck(testGrid);

    }
    }

    void userSecEntry() {
        int buff[9][9];
        int cnt=1;
        // will check for entered numbers
        while (cnt != 9){
        puts("Enter row 2 of your Sudoku grid");
        puts("Use Space/Tab/Return key to enter the next values\n"
             "and press 'Return' after entering nine integers."
             "\nRemember, to make a valid row of Sudoku grid,\n"
             "all integers should be distinct and range from 1 to 9");
        fgets(buff, sizeof(buff), stdin);
        cnt = sscanf(buff, "%d%d%d%d%d%d%d%d%d", &testGrid[1][0], &testGrid[1][1], &testGrid[1][2],
                     &testGrid[1][3], &testGrid[1][4], &testGrid[1][5], &testGrid[1][6],
                     &testGrid[1][7], &testGrid[1][8]);
            // will check number of entries
        if (cnt != 9) {
            puts("Please, Enter exactly nine INTEGERS separated by Space/Tab followed by Enter key to end");
        } else {
            // will check range of entry
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 9; j++) {
                    if (testGrid[i][j] < 0 || testGrid[i][j] > 9) {
                        puts("one or more entries are outside the range 1 to 9!");
                        userSecEntry();
                    }
                }
            }
        }
        rowSecCheck(testGrid);

    }
    }

int rowFirCheck(int testGrid[9][9]){
    // will check every elements on row to check any duplicate entry
    for(int i=0; i<9; i++) {
        int array[9] = {0};
        for (int j = 0; j < 9; j++) {
            for(int k = 0; k < 9; k++){
                if(testGrid[i][j]==array[k]){
                    puts("\nThere is a duplicate entry\n");
                    userFirEntry();
                }
                array[k] = testGrid[i][j];
            }
        }
    }
    return 1;
}

int rowCheck(int testGrid[9][9]){
    // will check every elements on row to check any duplicate entry
    for(int i=0; i<9; i++) {
        int array[9] = {0};
        for (int j = 0; j < 9; j++) {
            for(int k = 0; k < 9; k++){
                if(testGrid[i][j]==array[k]){
                    puts("\nThere is a duplicate entry\n");
                    return 0;
                }
                array[k] = testGrid[i][j];
            }
        }
    }
    return 1;
}

int rowSecCheck(int testGrid[9][9]){
    // will check every elements on row to check any duplicate entry
    for(int i=0; i<9; i++) {
        int array[9] = {0};
        for (int j = 0; j < 9; j++) {
            for(int k = 0; k < 9; k++){
                if(testGrid[i][j]==array[k]){
                    puts("\nThere is a duplicate entry\n");
                    userSecEntry();
                }
                array[k] = testGrid[i][j];
            }
        }
    }
    return 1;
}

int columnCheck(int testGrid[9][9]){
    // will check every elements on column to check any duplicate entry
    for(int i=0; i<9; i++) {
        int array[9] = {0};
        for (int j = 0; j < 9; j++) {
            for(int k = 0; k < 9; k++){
                if(testGrid[j][i]==array[k]){
                    puts("\nThere is a duplicate entry\n");
                    break;
                }
                array[k] = testGrid[j][i];
            }
        }
    }
    return 1;
}

void randomNum(int testGrid[9][9]){
    // will generate random numbers and store in the row 3 to 9
    srand(time(NULL));

    for (int rows = 2; rows < 9; rows++){
        for (int cols = 0; cols < 9; cols++) {
            testGrid[rows][cols]=rand()%9 + 1;
        }
    }
}