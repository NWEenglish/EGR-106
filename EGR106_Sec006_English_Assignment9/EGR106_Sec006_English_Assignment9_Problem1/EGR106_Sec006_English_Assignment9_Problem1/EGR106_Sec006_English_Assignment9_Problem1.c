/**********************************************************************
*
* Name: Nicholas English
* Date: 11/1/2017
* Program: Assignment9_Problem1
* Description: Gets a value from the user that the user wishes to find
*   the factorial of. The program checks if that number is valid (valid
*   being defined as nonnegtive integers less than 8), and then runs
*   the user value through R.W. Gosper's proposed approximation formula
*   for the factorial of a value.
*
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Value of PI was given by the textbook
#define PI 3.14159265

// Value of E had to be found by calculating. Was NOT given by textbook.
#define E 2.71828182

/** Used to get the user input **/
int getUserInput();

/** Used to check if the user input is valid **/
bool validUserInput(int);

/** Used to find the factorial of the user input **/
float factorial(int);

int main() {

    /** The value that the user enters **/
    int userInput;

    /** The factorial of the user input **/
    float factorialOfInput;

    // Calls the method to get the user input.
    userInput = getUserInput();

    // Calls the method to get the factorial value of the user input.
    factorialOfInput = factorial(userInput);

    printf("\n The factorial of %d is approximately %f", userInput, factorialOfInput);

    printf("\n\n\n");
    return 0;
}


/**********************************************************************
*
* This method is used to get a value from the user. It will ask the
* user for a value and then return the value if it is a valid value.
*
* @return userInput Returns an integer value that the method got from
*   the user.
*
**********************************************************************/
int getUserInput() {

    /** Holds an integer value of what the user inputed. **/
    int userInput;

    /** Holds a boolean value of if the userInput is within the correct
        parameters (between 0 and 8). **/
    bool isValid;

    // Gets the user's input
    printf("\n Please enter a value:\t");
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

    if (valueToCheck >= 0 && valueToCheck < 8) {
        return true;

    } else {
        printf("\n\n ERROR! Value can NOT be accepted!");
        return false;
    }
}

/**********************************************************************
*
* This method is used to calculate the approximate value of the
* factorial of the user input. This approximation is based off of
* R.W. Gosper's formula.
*
* @param userInput Holds the value that the user inputed.
* @return factoredValue Returns the factorial value of userInput.
*
**********************************************************************/
float factorial(int userInput) {

    /** Holds the value as it is being approximated as to what the
        factorial of userInput is. **/
    float factoredValue;

    // Debugging values
    float tempValue1 = ( ( ( 2 * userInput ) + (float)( 1 / 3 ) ) * PI );
    float tempValue2 = sqrt( ( ( ( 2 * userInput ) + (float)( 1 / 3 ) ) * PI ) );
    printf("\n ____________________________________ \n\n Debugging values (n = %d):", userInput);
    printf("\n\n\t 2n + 1/3 = %f\n\t sqrt( 2n + 1/3 ) = %f", tempValue1, tempValue2);
    printf("\n ____________________________________ \n");

    // Calculations
    factoredValue = sqrt( ( ( ( 2 * userInput ) + (float)( 1 / 3 ) ) * PI ) );
    factoredValue = factoredValue * pow(userInput, userInput) * pow(E, ( (-1) * userInput) );

    return factoredValue;
}
