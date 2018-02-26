/***********************************************************************
*
* Name: Nicholas English
* Date: 10/12/2017
* Program: Assignment7_Project3
* Description: A simple game that has a user place a bet over dice. The
*   user and the computer roll the dice and the user wants to have a
*   greater number than the computer so that they can win. User wins at
*   200 tokens and loses at 0 tokens.
*
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/***********************************************************************
*
*   @variables userDice Holds the dice roll of the user.
*
*   @variables compDice Holds the dice roll of the computer.
*
*   @variables tokens Holds the value of how many tokens the user has.
*
*   @variables wager The amount the user is betting.
*
*   @variables userConfirm Holds the character the user inputs.
*
*   @variables confirmPlay Boolean statement to act as a flag.
*
***********************************************************************/
int userDice;
int compDice;
int tokens = 100;
int wager;
char userConfirm;
bool confirmPlay = true;

int main() {

    //Gets user input
    printf(" Welcome to the dice game!\n The game allows you to place a wager and roll dice.\n");
    printf(" Your competitor is the computer!\n\n Would you like to play? Enter 'Y' for yes: ");
    scanf(" %c*", &userConfirm);

    //Checks if user wants to play the game
    if (userConfirm != 'Y' && userConfirm != 'y') {
        printf(" \n\nMaybe some other time then :(");
    }
    else {

            printf("\n\n Awesome! Let's begin!");

        while (confirmPlay) {

            //Gets the wager from the user
            printf("\n\n Please enter your wager: ");
            scanf("%d", &wager);

            /**********************************************************/

            //Checks and loops until
            while (wager <= 0 || wager > tokens){
                printf("\n Nice try, but that's not a valid wager! Try again: ");
                scanf("%d", &wager);
            }

            /**********************************************************/

            //Finds the dice roll for both parties
            srand(time(NULL));
            userDice = ( ( rand() % 6 ) + 1 );
            compDice = ( ( rand() % 6 ) + 1 );

            /**********************************************************/

            //Inform use of each dice roll
            printf("\n\n You rolled a %d", userDice);
            printf("\n The computer rolled a %d", compDice);

            /**********************************************************/

            //Compares dice rolls to find the winner
            if(userDice > compDice) {
                tokens = tokens + wager;
                printf("\n\n You won the role! You now have %d tokens!\n", tokens);

                //Checks if the user is a winner
                if (tokens >= 200) {

                    //Asks user if they want to play again.
                    printf(" You won the game!\n\n Would you like to play again? (Y/N):\t");
                    scanf(" %c*", &userConfirm);

                    if (userConfirm == 'Y' || userConfirm == 'y') {
                        confirmPlay = true;
                        tokens = 100;
                    }

                    else if (userConfirm == 'N' || userConfirm == 'n') {
                        confirmPlay = false;
                        return 0;
                    }

                    else {
                        while (userConfirm != 'Y' || userConfirm != 'y' || userConfirm != 'N' || userConfirm != 'n') {
                            printf("\n Invalid input, please try again: ");
                            scanf(" %c*", &userConfirm);
                        }
                    }
                }
            }
            else if (userDice < compDice) {
                tokens = tokens - wager;
                printf("\n\n You lost the role! You now have %d tokens!", tokens);

                //Checks if user is a loser
                if (tokens <= 0) {

                    //Asks user if they want to play again
                    printf("\n You lost the game!\n\n Would you like to play again? (Y/N):\t");
                    scanf(" %c*", &userConfirm);

                    if (userConfirm == 'Y' || userConfirm == 'y') {
                        confirmPlay = true;
                        tokens = 100;
                    }

                    else if (userConfirm == 'N' || userConfirm == 'n') {
                        confirmPlay = false;
                        return 0;
                    }

                    else {
                        while (userConfirm != 'Y' || userConfirm != 'y' || userConfirm != 'N' || userConfirm != 'n') {
                            printf("\n Invalid input, please try again: ");
                            scanf(" %c*", &userConfirm);
                        }
                    }

                }
            }
            else {
                printf("\n\n No winners! Tie game, tokens remain at %d tokens.\n\n", tokens);
            }
        }
    }
    /*****************************************************************/

    printf("\n\n\n");
    return 0;

}
