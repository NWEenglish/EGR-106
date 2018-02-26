/** -------------------------------------------------------
* Name: Nicholas English
* Date: 9/26/2017
* Program: Assignment5Project11
* Description: Takes values for m and n as input and
*   displays the values of the Pythagorean triple.
* -------------------------------------------------------- **/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*************************************************************
*
*   @variables m_value Represents the m value of the
*       Pythagorean triple.
*
*   @variables n_value Represents the n value of the
*       Pythagorean triple.
*
*   @variables side1 Output variable of what side1 is from
*       the Pythagorean triple.
*
*   @variables side2 Output variable of what side2 is from
*       the Pythagorean triple.
*
*   @variables hypotenuse Output variable of what the
*       hypotenuse is from the Pythagorean triple.
*
*   @variables counter Initialized to 0 and used for
*       controlling the do-while loop.
*
*************************************************************/
int m_value, n_value, side1, side2, hypotenuse, counter = 0;

int main() {
    printf("In order for this program to operate correctly,\nthe m value MUST be greater than the n value.");

    /* ---------------------------------------------------- */

    printf("\n\nPlease enter a value for n: ");
    scanf("%d", &n_value);

    /**
    *   Loops the program until the user inputs a m_value
    *   greater than n_value
    **/
    do{
        if(counter >= 1){
            printf("Please enter a value GREATER than n for the value of m: ");
            scanf("%d", &m_value);
        }
        else {
            printf("Please enter a value for m: ");
            scanf("%d", &m_value);
        }
        counter++;
    }
    while (m_value < n_value);

    /** -------------------------------------------------- **/

    /* Calculations */
    side1 = pow(m_value, 2) - pow(n_value, 2);
    side2 = 2 * m_value * n_value;
    hypotenuse = pow(m_value, 2) + pow(n_value, 2);

    /** -------------------------------------------------- **/

    printf("\nSide 1:\t\t%d", side1);
    printf("\nSide 2:\t\t%d", side2);
    printf("\nHypotenuse:\t%d", hypotenuse);
    printf("\n\n\n");

    /** -------------------------------------------------- **/

    return 0;
}
