/**********************************************************************
*
* Name: Nicholas English
* Date: 11/1/2017
* Program: Assignment9_Problem2
* Description: This is a program that calculates the speed of sound in
*   air at a given temperature.
*
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/** Used to get the user input **/
int getUserInput();

/** Used to find the speed of sound **/
float speedOfSound(int);

int main() {

    /** The value that the user enters **/
    int userInput;

    /** The speed of sound at a particular air temperature **/
    float speed;

    // Calls the method to get the user input.
    userInput = getUserInput();

    /* Calls the method to get the speed of sound at a particular
       air temperature. */
    speed = speedOfSound(userInput);

    printf("\n The speed of air at %d degrees fahrenheit is %f ft/sec.", userInput, speed);

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

    // Gets the user's input
    printf("\n Please enter the air temperature in degrees fahrenheit:\t");
    scanf("%d", &userInput);

    return userInput;
}

/**********************************************************************
*
* This method is used to calculate the speed of sound in air of at a
* given temperature.
*
* @param userInput Holds the value that the user inputed.
* @return speed Returns speed of sound at a particular temperature in
*   feet per seconds.
*
**********************************************************************/
float speedOfSound(int userInput) {

    /** Holds the value as it is being calculated as to what the speed
        of sound is at a specified temperature. **/
    float speed;

    speed = 5 * userInput;
    speed = sqrt( ( ( speed + 297 ) / 247 ) ) ;
    speed = speed * 1086;

    return speed;
}
