/***********************************************************************
*
* Name: Nicholas English
* Date: 10/12/2017
* Program: Assignment7_Project1
* Description: A program that reports the contents of a compressed-gas
*   cylinder
*
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/***********************************************************************
*
*   @variables colorInput The user enters the color of the gas
*       in the container. The variable holds only the first letter.
*
***********************************************************************/
char colorInput[20];

int main() {

    //Receive user input and reword if entered wrong
    printf("\nPlease enter the color of the gas in the compressed cylinder: ");
    scanf("%c", &colorInput[0]);

    //Checks user input to match the correct case
    if (colorInput[0] == 'O' || colorInput[0] == 'o')
        printf("\nThe gas is Ammonia.");

    else if (colorInput[0] == 'B' || colorInput[0] == 'b')
        printf("\nThe gas is Carbon Monoxide.");

    else if (colorInput[0] == 'Y' || colorInput[0] == 'y')
        printf("\nThe gas is Hydrogen.");

    else if (colorInput[0] == 'G' || colorInput[0] == 'g')
        printf("\nThe gas is Oxygen.");

    else
        printf("\nContents Unknown.");

    /*****************************************************************/

    printf("\n\n\n");
    return 0;
}
