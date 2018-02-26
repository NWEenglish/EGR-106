/** ------------------------------------------------------
* Name: Nicholas English
* Date: 9/26/2017
* Program: Assignment5Project13
* Description: Takes an input value of how many apples
*   there are. It echoes that amount back and then sorts
*   how many bags there are and how many apples will be
*   left over.
* -------------------------------------------------------- **/

#include <stdio.h>
#include <stdlib.h>

/*************************************************************
*
*   @variables initialApples The initial starting amount of
*       apples that the user inputs.
*
*   @variables remainingApples The remaining amount of apples
*       that are left over after being bagged.
*
*   @variables wholeBags The number of bags that are produced
*       from the initialApples amount. 12 apples per bag.
*
*   @variables counter Used for controlling the do-while
*       if-else statements. Initialized to 0.
*
*************************************************************/
int initialApples, remainingApples, wholeBags, counter = 0;

int main() {

    /**
    *   Loops the program until the user inputs a valid
    *   quantity of apples.
    **/
    do {
        if (counter > 0)
        {
            printf("\nYou can NOT have a negative quantity.\n");
            printf("Please enter the amount of apples you wish to bag: ");
            scanf("%d", &initialApples);
        }
        else {
            printf("\nPlease enter the amount of apples you wish to bag: ");
            scanf("%d", &initialApples);
        }

        counter++;
    }
    while (initialApples < 0);

    printf("\nYou entered %d apples to be bagged.", initialApples);

    /** -------------------------------------------------- **/

    /* Calculations */
    wholeBags = initialApples / 12;
    remainingApples = initialApples % 12;

    /** -------------------------------------------------- **/

    printf("\n\nWhole Bags Produced:\t%d", wholeBags);
    printf("\nRemaining Apples:\t%d", remainingApples);
    printf("\n\n\n");

    /** -------------------------------------------------- **/

    return 0;
}
