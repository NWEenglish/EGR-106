/***********************************************************************
*
* Name: Nicholas English
* Date: 11/14/2017
* Program: Assignment13B
* Description:
*
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/** Reverses the order of the array **/
void reverse ( int data[MAX], int size );

/** Counts the number of zeros and ones in the data.txt file **/
int countZerosOnes ( int data[MAX], int size, int *pNumZeros, int *pNumOnes );

/** Display to the user information **/
void display ( int data[MAX], int size );

int main() {

    FILE *fp;
    int size = 0;
    int numZeros;
    int numOnes;
    int totalCount;
    int dataArray[MAX];
    int temp;
    int *pNumOnes;
    int *pNumZeros;

    /** Part one code **/
    // Checks if the file exists
    if ( (fp = fopen( "data.txt", "r" ) ) == 0 )
        printf("\nFile could not be opened\n");

    else {

        // Opens the file
        fp = fopen( "data.txt", "r" );

        // Loops to assign values to the array and find the size
        for ( int i = 0; fscanf(fp, "%d", &temp) != EOF; i++) {
            dataArray[i] = temp;
            size = i + 1;
        }

    /** Part two code **/
    printf("\n\n Original Data:");
    display ( dataArray, size );

    /** Part three code **/
    reverse ( dataArray, size );

    /** Part four code **/
    totalCount = countZerosOnes ( dataArray, size, &pNumZeros, &pNumOnes );
    printf( "\n\n Number of zeros in original array = %d.", pNumZeros );
    printf( "\n Number of ones in original array = %d.", pNumOnes );
    printf( "\n Total count of ones & zeros = %d.", totalCount );
    }

    printf("\n\n\n");
    return 0;
}

/***********************************************************************/

/** Displays an array to the user **/
void display ( int data[MAX], int size ) {
    printf("\n List ==>");

    for ( int j = 0; j < size; j++) {
        printf(" %d", data[j]);
    }
}

/***********************************************************************/

/** Reverses the order of an array. Essentially, it "flips" the array **/
void reverse ( int data[MAX], int size ) {
    int temp;
    int end = size - 1;

    // Loops until array has been flipped
    for ( int start = 0; start < ( size / 2 ); start++, end-- ) {

        // Flips the array
        temp = data[start];
        data[start] = data[end];
        data[end] = temp;
    }

    // Calls the display method to print the flipped array
    printf("\n\n Flipped Data:");
    display ( data, size );
}

/***********************************************************************/

/** Counts the total number of zeros and ones **/
int countZerosOnes( int data[MAX], int size, int *pNumZeros, int *pNumOnes ) {

    // Values to hold the number of zeros and ones
    int numZeros = 0;
    int numOnes = 0;

    // Finds number of zeros in the array
    for ( int i = 0; i < size; i++ ) {
        if ( data[ i ] == 0 )
            numZeros++;
    }

    // Finds the number of ones in the array
    for ( int i = 0; i < size; i++ ) {
        if ( data[ i ] == 1 )
            numOnes++;
    }

    // Assigns points to their respective values
    *pNumOnes = numOnes;
    *pNumZeros = numZeros;

    // Returns the totalCount ( total number of zeros and ones )
    return ( numZeros + numOnes );
}
