/***********************************************************************
*
* Name: Nicholas English
* Date: 12/3/2017
* Program: Assignment15_Problem1
* Description: In this code, a file will be read ( mat.txt ) and the
*   program will read it as a matrix and return to the user the
*   determinant. Program uses two functions: 1st is used a welcome/into
*   to the user, the 2nd is used to read the file, calculate the
*   determinant, and print the determinant to the screen.
*
***********************************************************************/

/* Libraries */
#include <stdio.h>
#include <stdlib.h>

/* Variables */
// Used to hold the address of the mat.txt file
FILE *fpin;

/** Introduces the program to the user **/
void introFunction();

/** Finds the determinant and prints it to the user **/
void determinantFunction(FILE *fpin);

int main() {

    /* Opens the file */
    fpin = fopen( "mat.txt", "r" );

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

        /* Sets the value of the determinant to the determinantFunction() */
        determinantFunction( fpin );

        /* End of code reached */
        printf("\n\n\n");
        return 0;
    }
}

/** Writes to the user a welcome/intro to the program **/
void introFunction() {

    // Intro to the user, written to the screen
    printf("\n Welcome to Assignment15_Problem 1!");
    printf("\n\n In this code, a file will be read ( mat.txt ) and the");
    printf("\n program and you will read it as a matrix and return to you ");
    printf("\n the determinant as well.\n\n");

}

/** Finds the determinant and prints it to the user **/
void determinantFunction( FILE *fpin ) {

    /* All positions in a 3x3 matrix ( a = positionArray ):
        [ a[0][0]    a[0][1]    a[0][2]
          a[1][0]    a[1][1]    a[1][2]
          a[2][0]    a[2][1]    a[2][2] ]
    */
    double positionArray[3][3];

    /* Holds the value of the determinant */
    double determinant;

    /* Used for the "for" loops */
    int i;
    int j;

    /* Used to read from the file numbers into an array */
    for ( i = 0; i < 3; i++ )
        for ( j = 0; j < 3; j++ )
            fscanf( fpin, "%lf", &positionArray[i][j]);

    /* Used to write the array to the user */
	printf("\n The determinant of matrix\n");
    for ( i = 0; i < 3; i++ ) {
        printf("\n |");

        for ( j = 0; j < 3; j++ )
            printf( "\t%3d", (int)positionArray[i][j]);

        printf(" |");
    }

    /* Calculates the determinant */
    determinant = positionArray[0][0] * ( ( positionArray[1][1] * positionArray[2][2] ) - ( positionArray[1][2] * positionArray[2][1] ) );
    determinant = determinant - ( positionArray[0][1] * ( ( positionArray[1][0] * positionArray[2][2] ) - ( positionArray[1][2] * positionArray[2][0] ) ) );
    determinant = determinant + ( positionArray[0][2] * ( ( positionArray[1][0] * positionArray[2][1] ) - ( positionArray[1][1] * positionArray[2][0] ) ) );

    /* Prints the determinant to the screen */
    printf( "\n\n\n is %d.", (int)determinant );
}
