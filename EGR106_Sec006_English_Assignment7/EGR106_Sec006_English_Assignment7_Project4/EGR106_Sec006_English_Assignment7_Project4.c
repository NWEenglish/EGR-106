/***********************************************************************
*
* Name: Nicholas English
* Date: 10/12/2017
* Program: Assignment7_Project4
* Description: A program that reads in an integer from the user and
*   tests to see if it's a prime number.
*
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/***********************************************************************
*
*   @variables is_prime A flag that will result in true if the value is
*       a prime number.
*
*
*   @variables userInput Holds the value the user wants to see is prime
*
*   @variables cont Used as a flag to ask the user if they want to test
*       another value.
*
***********************************************************************/
bool is_prime;
int userInput;
int cont;

int main() {

    do {
        //Gets user input for the number we want to test is prime
        printf("\n What value would you like to see is prime?\t");
        scanf("%d", &userInput);

        //Loop to check all possibilities if the number is prime
        int m = 2;
        for (int m = 2; m <= sqrt(userInput); m++) {

            //Checks current value if it's a factor
            if ((userInput % m == 0)) {

                is_prime = false;
                m = userInput;
            }
            else
                is_prime = true;
        }

            //Output depending on is_prime status
            if (is_prime) {
                printf("%d: PRIME Number", userInput);
            }

            else {
                printf("%d: NOT A PRIME Number", userInput);

                for (int n = 1; n <= sqrt(userInput); n++) {
                    if(userInput % n == 0) {
                        int y = userInput / n;
                        printf("\n%d = %d x %d", userInput, n, y);
                    }

                }

            }

        //Asks use if they would like to test another value
        printf("\n\nWould you like to enter another value? Enter 1 for yes:\t");
        scanf("%d", &cont);

    }
    while (cont == 1);

    /*****************************************************************/

    printf("\n\n\n");
    return 0;
}
