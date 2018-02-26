/* ---------------------------------------------------------
* Name: Nicholas English
* Date: 9/16/2017
* Program: EGR106_Sec006_English_Assignment3Project1
* Description: A program  that calculates mileage
* reimbursement for an individual. Program accepts input
* for starting and ending odometer reading. It then
* outputs total distance traveled and the reimbursement.
* --------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* Sets the rate to a constant of $0.35 */
    float ratePerMile = .35;

    /* Initializes the variables used in the code */
    float startOdometer, endOdometer, totalTravel, reimbursement;

    /* ---------------------------------------------------- */

    printf("MILEAGE REIMBURSEMENT CALCULATOR\n");

    printf("Enter beginning odometer reading=> ");
    scanf("%f", &startOdometer);

    printf("Enter ending odometer reading=> ");
    scanf("%f", &endOdometer);


    /* Calculates total travel time and reimbursement */
    totalTravel = endOdometer - startOdometer;
    reimbursement = ratePerMile * totalTravel;

    printf("You traveled %.1f miles. \tAt $%.2f per mile,\n", totalTravel, ratePerMile);
    printf("your reimbursement is $%.2f.", reimbursement);

    /* ---------------------------------------------------- */

    /* Ends program */
    printf("\n\n\n");
    return 0;
}
