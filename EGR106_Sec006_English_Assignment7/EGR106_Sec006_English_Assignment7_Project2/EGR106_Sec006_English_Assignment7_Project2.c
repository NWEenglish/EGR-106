/***********************************************************************
*
* Name: Nicholas English
* Date: 10/12/2017
* Program: Assignment7_Project2
* Description: Accepts user input and determines if it's divisible by 9.
*
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/***********************************************************************
*
*   @variables userInput Holds the current value that the user wants to
*       have divided by 9.
*
*   @variables tempValue Holds a temp value, which is the return value
*       from a modulated statement.
*
*   @variables totalValue Holds the added total of each digit added
*       together.
*
*   @variables flag A simple flag variable.
*
***********************************************************************/
int userInput;
int tempValue = 0;
int totalValue = 0;
bool flag = false;

int main() {

    //Gets user input
    printf(" Please enter a value: ");
    scanf("%d", &userInput);

    /******************************************************************/
    //Organizes where the computer is in its process.
    printf("\n Digits pulled out (starting on the right):");

    //Loops until we know if value is divisible by 9 or not.
    do {

        //Calculations
        tempValue = userInput % 10;
        totalValue = totalValue + tempValue;
        userInput = userInput / 10;

        //For finding the current values stored.
        printf("\n %d", tempValue);

        //Finds if we have found a divisible number
        if (userInput == 0 && (totalValue % 9) == 0)
            flag = true;

    } while (userInput != 0);

    /*****************************************************************/

    //Final output to user
    if(flag)
        printf("\n\n The value is divisible by 9!");
    else
        printf("\n\n The value is not divisible by 9!");


    /*****************************************************************/

    printf("\n\n\n");
    return 0;
}
