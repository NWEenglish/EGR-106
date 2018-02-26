/***********************************************************************
*
* Name: Nicholas English
* Date: 12/5/2017
* Program: Assignment15_Problem2
* Description: This program takes a file ( data.txt ) and write an
*   array from the file. The user then has the choice to sort the file
*   in either ascending order or descending order. Each step will be
*   printed to the user as it is sorted.
*
***********************************************************************/

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Macro */
#define MAX 50

/** Variables **/
// Used to hold the address of the data.txt file
FILE *fpin;

// Holds the number of points organized so far
int n;

// Holds the current value
float input;

// Both hold a choice from the user
char choiceTemp;
bool choice; //true is ascending, false is descending

// Creates the array
float sortArray[MAX];

/** Introduces the program to the user **/
void introFunction();

/** Sorts file into an array **/
void sortFunction( int n, float input, bool choice, float sortArray[MAX] );

/** Prints the sorted array **/
void printSortedFunction( float sortArray[MAX], int length );

int main() {

    /* Opens the file */
    fpin = fopen( "data.txt", "r" );

    /* Checks to make sure the file exists */
    // Runs if it does NOT exist
    if ( fpin == 0 ) {
        printf("\n There appears to be a problem with the program.");
        printf("\n Please contact a representative if this problem persists.");
        exit(-1);
    }

    // Runs if it DOES exist
    else {

        /* Calls introFunction() */
        introFunction();

        /* Gets the choice from the user */
        printf("\n Would you like the numbers to be sorted in descending or ascending order?");
        printf("\n Enter D or A for your choice respectively: \t");
        scanf("%c", &choiceTemp);

        /* If choice was invalid */
        while ( choiceTemp != 'A' && choiceTemp != 'a' && choiceTemp != 'D' && choiceTemp != 'd') {
            printf("\n That was an invalid choice! Please try again: \t");
            scanf( "\n%c", &choiceTemp );
        }

        /* Sorts the choice into true or false */
        if ( choiceTemp == 'A' || choiceTemp == 'a' )
            choice = true;

        if ( choiceTemp == 'D' || choiceTemp == 'd' )
            choice = false;

        /* Sorts and prints the array each time a item is scanned in */
        for ( n = 0; fscanf( fpin, "%f", &input ) != EOF && n < MAX; n++ ) {

            // Sorts the function */
            sortFunction( n, input, choice, sortArray );

            // Calls the print function
            printSortedFunction( sortArray, n );

        }

        /* End of code reached */
        printf("\n\n\n");
        return 0;
    }
}

/** Writes to the user a welcome/intro to the program **/
void introFunction() {

    // Intro to the user, written to the screen
    printf("\n Welcome to Assignment15_Problem2!");
    printf("\n This program takes a file ( data.txt ) and write an array from ");
    printf("\n the file. You, the user, then has the choice to sort the file in");
    printf("\n either ascending order or descending order. Each step will be ");
    printf("\n printed to the user as it is sorted.\n\n");

}

/** Sorts file into an array **/
void sortFunction( int n, float input, bool choice, float sortArray[] ) {

    /* Variables */
    // For the "for" loops
    int i;
    int j;

    // Just a temp value to act as a holder
    float temp;

    /* Assigns the first value of the array */
    if ( n == 0 )
        sortArray[0] = input;

    /* Ascending order */
    else if ( choice ) {

        // Loops through the array until it can place the input in the correct spot
        for ( i = n - 1; i >= 0; i-- ) {

            // Shifts a value over one
            temp = sortArray[i];
            sortArray[i + 1] = temp;

            // Runs once the code finds a value less than the input
            if ( input > temp ) {
                sortArray[i + 1] = input;
                break;
            }

            // Runs if the code reaches the end and still has not been less than a value
            else if ( i == 0 )
                sortArray[0] = input;
        }
    }

    /* Descending order */
    else {

        // Loops through the array until it can place the input in the correct spot
        for ( i = n - 1; i >= 0; i-- ) {

            // Shifts a value over one
            temp = sortArray[i];
            sortArray[i + 1] = temp;

            // Runs once the code finds a value greater than the input
            if ( input < temp ) {
                sortArray[i + 1] = input;
                break;
            }

            // Runs if the code reaches the end and still has not been greater than a value
            else if ( i == 0 )
                sortArray[0] = input;
        }
    }
}

/** Prints the sorted array **/
void printSortedFunction( float sortArray[], int length ) {

    /* Variables */
    // For the "for" loop
    int i;

    /* Loops through the array to print what is currently sorted */
    printf("\n\n");
    for ( i = 0; i <= length; i++)
        printf( " %5.1f\t", sortArray[i] );
}
