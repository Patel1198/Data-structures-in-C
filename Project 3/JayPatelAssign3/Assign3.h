//
// Created by jayko on 2021-03-23.
//

#ifndef JAYPATELASSIGN3_ASSIGN3_H
#define JAYPATELASSIGN3_ASSIGN3_H

/*
 mohitilities.c created by Muhammad Mohiuddin on 12/24/2020. It is a collection of some utility functions as summarized below:
 1- void delay( float secs)
 it introduces a delay of number of secs given as a parameter.

 2- int* sortArrayNKeepIndices(int arr[], int arrSize)
 it sorts an array and keeps track of the indices of the elements as well and return these as a pointer to indices array
 void generateRandomYetSortedIntegers(int arr[], int cnt, int range, int offset, int distinct)
 it generates 'cnt' number of random integers, which can be optionally distinct, sorts these and saves these in an array

 3- int dataValidation(int upperbound)
 it validates integer input up to the upperbound and returns the user input after validation.

 4- void generateRandomYetSortedIntegers(int arr[], int cnt, int range, int offset, int distinct)
 it generates random yet sorted and optionally distinct set of random integers with a give range and offset.

 5- void printArray(int arr[], int len)
 it prints last NUM_OF_RECORDS_TO_PRINT elements of the array or the entire array if the size of the array is smaller.
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#define SIZE 50
#define NUM_OF_RECORDS_TO_PRINT 50 // this sets the upper limit for number of elements to print in printArray function

/**
 * sortArrayNKeepIndices sorts an array and keeps track of the indices of the elements it requires limits.h file
 * @param arr is the array that needs to be sorted. array passed will be sorted in the caller function
 * @param arrSize is the array size
 * @return it returns an integer pointer to the array of old indices
 * for example for the unsorted array arr = {16, 15, 12, 10, 13}, updated arr will be {10, 12, 13, 15, 16} and
 *   return pointer will point to an array  {3, 2, 4, 1, 0} so the set of pairs of updated (of sorted array) and
 *   original (of unsorted array) indices will be  10 (0, 3), 12 (1, 2), 13 (2, 4), 15 (3, 1), 16 (4, 0)  */
int* sortArrayNKeepIndices(int arr[], int arrSize){
    static int indexArr[SIZE];
    int arr2[arrSize];
    for (int i = 0; i < arrSize; i++) {
        indexArr[i] = 0;
        arr2[i] = arr[i];
    }
    int min = 0, temp = 0;

    for (int i = 0; i < arrSize ; i++)
    {
        min = i;  // record the position of the smallest
        for (int j = i + 1; j < arrSize; j++)
        {
            // update min when finding a smaller element
            if (arr[j] < arr[min])
                min = j;
        }
        // put the smallest element at position i
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    } // array sorting ends here
    int ctr = 0;
    while ( ctr < arrSize) {
        min = 0;  // restart from first element
        for (int j = 0; j < arrSize; j++)
        {
            if (arr2[j] == INT_MAX) continue; // ignore already marked as minimum indices
            // update min when finding a smaller element
            if (arr2[j] < arr2[min])
                min = j;
        }
        indexArr[ctr] = min; // updating indexArr with the index of the next minimum
        arr2[min] = INT_MAX; // marking minimum element to be ignored next time
        ctr++;
    } //keeping track of previous indices of the array elements ends here
    return indexArr;
} // function sortArrayKeepIndices ends here


/**
 *
 * @param upperbound is the highest integer acceptable as one of the menu options, it must NOT be 9
 * @return is one of the valid options or 9 if the user wants to quit or go back to a previous menu
 */

int dataValidation(int upperbound)
{
    int n = 0, num;
    char temp[40];
    while (1)
    {

        scanf("%d", &num);
        if (num == 9) {
            return num;
            break;
        }
        else if(num >= 0 && num <= upperbound) return num;
        else
        {

            printf("Invalid data, Enter an integer 0 through %d or enter 9 to skip and/or go back to the main menu. "
                   "Try again \n",upperbound );
            continue;
        }
    }
}

int dataCheck(int upperbound)
{
    int n = 0, num;
    char temp[40];
    while (1)
    {

        scanf("%d", &num);
        if(num >= 0 && num <= upperbound) return num;
        else
        {
            printf("Invalid data, Enter an integer 0 through %d. Try again \n",upperbound );
            continue;
        }
    }
}


void delay(float number_of_seconds)
{
    // Converting time into milli_seconds
    float milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
/**
 *
 * @param arr is the array that will be populated with random yet sorted list of integers
 * @param cnt is the size of the array
 * @param range is the range or spread of the set of random integers
 * @param offset is the offset of the set of random integers
 * @param if all numbers should be distinct then set it to 1  else 0
 * Note! For a distinct set of integers, make sure range > cnt, else the function will set range equal to cnt
 */

void generateRandomYetSortedIntegers(int arr[], int cnt, int range, int offset, int distinct) {
    range =  cnt > range ? cnt : range;
    for (int dex = 0; dex < cnt; dex++ ) {
        arr[dex] = rand() % (range + 1) + offset;
        if (distinct) {
            for (int ctr = 0; ctr < dex; ctr++) {
                if (arr[dex] == arr[ctr]) {
                    dex--;
                    break;
                }
            }
        }
    }
    //quickSort(arr, 0, cnt - 1); // optionally you may provide code for quickSort and call it to sort the array
    int max = 0, temp = 0;

    for (int i = 0; i < cnt ; i++)
    {
        max = i;  // record the position of the smallest
        for (int j = i + 1; j < cnt; j++)
        {
            // update min when finding a smaller element
            if (arr[j] < arr[max])
                max = j;
        }
        // put the smallest element at position i
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    } // array sorting ends here
} // function generateRandomYetSortedIntegers ends
/**
 * printArray prints last NUM_OF_RECORDS_TO_PRINT elements of an array passed to the function. It the length of the array
 * is shorter then it displays the entire array.
 * @param arr name of the array
 * @param len size of the array
 */
void printArray(int arr[], int len)
{
    for (int dex = len < NUM_OF_RECORDS_TO_PRINT ? 0 : len - NUM_OF_RECORDS_TO_PRINT; dex < len; dex++)
    {
        printf(dex % 10 ? "": "\n");
        printf("%8d  ", arr[dex]);
    }
    printf("\n");
}//ends printArr method

#endif //JAYPATELASSIGN3_ASSIGN3_H
