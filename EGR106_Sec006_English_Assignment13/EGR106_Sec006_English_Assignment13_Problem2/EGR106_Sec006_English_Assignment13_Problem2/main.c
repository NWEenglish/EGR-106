/***********************************************************************
*
* Name: Nicholas English
* Date: 11/26/2017
* Program: Assignment13
* Description: This code takes user input for the UPC code and
*	determines if the code is valid or invalid through calculations.
*
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(){

    /** Variable(s) **/
    int upcCode[12];
    int i;
    int total = 0;
    int sumOdd = 0;
    int sumEven = 0;
    int checkDigit = 0;


    /** Step 0 **/
    // Takes input from the user
    printf(" Please enter your UPC Code (separate each number with one space):\n ");
    scanf(" %d %d %d %d %d %d %d %d %d %d %d %d", &upcCode[0], &upcCode[1], &upcCode[2], &upcCode[3], &upcCode[4], &upcCode[5], &upcCode[6], &upcCode[7], &upcCode[8], &upcCode[9], &upcCode[10], &upcCode[11] );


    /** Step 1 **/
    // Calculates the sum of the odd AND even positioned numbers
    for ( i = 0; i < 11; i++ ) {
        if ( ( i % 2 ) == 0 )
            sumOdd = sumOdd + upcCode[ i ];
        else
            sumEven = sumEven + upcCode[ i ];
    }

    // Times the previous calculation by three
    total = ( sumOdd * 3 );


    /** Step 2 **/
    // Calculates the sum of the even positioned numbers
    // This code has been moved into the for loop in step 1

    // Adds this sumEven to the previous number
    total = total + sumEven;


    /** Step 3 **/
    // Checks if final number is a zero
    if ( ( total % 10 ) == 0 )
        checkDigit = 0;

    // If above does not run, this will be the check digit
    else
        checkDigit = ( 10 - ( total % 10 ) );


    /** Step 4 **/
    // Prints the UPC code
    printf("\n\n ");

    for(i = 0; i < 12; i++)
        printf("%d", upcCode[i]);

    // Checks if the check digit is correct
    if ( checkDigit == upcCode[ 11 ] )
        printf(" has been validated.");
    else
        printf(" has an error in the barcode.");


    /** End of code **/
    printf("\n\n\n");
    return 0;
}
