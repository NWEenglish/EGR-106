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
    float ratePerMile = .35;
    float startOdometer, endOdometer, totalTravel, reimbursement;

    printf("MILEAGE REIMBURSEMENT CALCULATOR");

    printf("\nEnter beginning odometer reading=> ");
    scanf("%f", &startOdometer);

    printf("\nEnter ending odometer reading=> ");
    scanf("%f", &endOdometer);

    totalTravel = endOdometer - startOdometer;
    reimbursement = ratePerMile * totalTravel;

    printf("\nYou traveled %.1f miles.\tAt $%.2f per mile,\n", totalTravel, ratePerMile);
    printf("your reimbursement is $%.2f.", reimbursement);

    return 0;
}
