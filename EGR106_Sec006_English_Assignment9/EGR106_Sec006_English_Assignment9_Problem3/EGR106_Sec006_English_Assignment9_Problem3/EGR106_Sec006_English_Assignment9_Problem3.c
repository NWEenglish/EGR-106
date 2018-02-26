/**********************************************************************
*
* Name: Nicholas English
* Date: 11/1/2017
* Program: Assignment9_Problem3
* Description: This is a program that acts as a automatic teller
*   machine that dispenses money.
*
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** Used to get the user input **/
int getUserInput();

/** Used to check if the user input is valid **/
bool validUserInput(int);

/** Used to find the number of $50 bills **/
int billsReturned50(int);

/** Used to find the number of $20 bills **/
int billsReturned20(int, int);

/** Used to find the number of $10 bills **/
int billsReturned10(int, int, int);

int main() {

    /** The value that the user enters **/
    int userInput;

    /** The speed of sound at a particular air temperature **/
    int speed;

    // Calls the method to get the user input.
    userInput = getUserInput();

    /*  These methods are used to find the total number of each type
        of bill. */
    int bills50 = billsReturned50(userInput);
    int bills20 = billsReturned20(userInput, bills50);
    int bills10 = billsReturned10(userInput, bills50, bills20);

    // Prints to the user
    printf("\n You will receive:\n\    %d\t$50s\n    %d\t$20s\n    %d\t$10s", bills50, bills20, bills10);

    printf("\n\n\n");
    return 0;
}


/**********************************************************************
*
* This method is used to get a value from the user. It will ask the
* user for a value and then return the value to main.
*
* @return userInput Returns an integer value that the method got from
*   the user.
*
**********************************************************************/
int getUserInput() {

    /** Holds an integer value of what the user inputed. **/
    int userInput;

    // Holds a boolean value of if the userInput is a multiple of 10.
    bool isValid;

    // Gets the user's input
    printf("\n Please enter the amount to withdraw:\t");
    scanf("%d", &userInput);

    // Checks if the user's input is valid
    isValid = validUserInput(userInput);

    // Loops until the user enters a valid value.
    while (!isValid) {

        // Gets the new user input.
        printf("\n Please enter a new value:\t");
        scanf("%d", &userInput);

        // Checks the new user input is valid.
        isValid = validUserInput(userInput);
    }

    return userInput;
}

/**********************************************************************
*
* This method is used to get a value from the user. It will ask the
* user for a value and then return the value if it is a valid value.
*
* @param valueToCheck The user input that needs to be checked if valid.
* @return Returns true if the value passed to it falls within its
*   parameters.
* @return Returns false if the value passed to it does NOT fall within
*   its parameters.
*
**********************************************************************/
bool validUserInput(int valueToCheck) {

    if ( ( valueToCheck % 10 ) == 0 ) {
        return true;

    } else {
        printf("\n\n ERROR! Value can NOT be accepted!");
        return false;
    }
}

/**********************************************************************
*
* This method is used to calculate the total number of $50 bills.
*
* @param userInput Holds the value that the user inputed.
* @return bills Returns the total number of $50 bills.
*
**********************************************************************/
int billsReturned50(int userInput) {

    int bills = 0;

    bills = userInput / 50;

    return bills;
}

/**********************************************************************
*
* This method is used to calculate the total number of $20 bills.
*
* @param userInput Holds the value that the user inputed.
* @param bills50 Holds the number of $50 bills.
* @return bills Returns the total number of $50 bills.
*
**********************************************************************/
int billsReturned20(int userInput, int bills50) {

    int bills = 0;

    if (userInput != 0) {
        userInput = ( userInput - ( 50 * bills50 ) );
        bills = userInput / 20;
    }

    return bills;
}

/**********************************************************************
*
* This method is used to calculate the total number of $10 bills.
*
* @param userInput Holds the value that the user inputed.
* @param bills50 Holds the number of $50 bills.
* @param bills20 Holds the number of $20 bills.
* @return bills Returns the total number of $50 bills.
*
**********************************************************************/
int billsReturned10(int userInput, int bills50, int bills20) {

    int bills = 0;

    if (userInput != 0) {
        userInput = ( userInput - ( 50 * bills50 ) );

        if (userInput != 0) {
            userInput = ( userInput - ( 20 * bills20 ) );

            if (userInput != 0)
                bills = userInput / 10;
        }
    }

    return bills;
}
