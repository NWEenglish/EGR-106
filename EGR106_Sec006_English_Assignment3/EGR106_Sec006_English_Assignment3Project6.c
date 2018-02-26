/* ---------------------------------------------------------
* Name: Nicholas English
* Date: 9/16/2017
* Program: EGR106_Sec006_English_Assignment3Project6
* Description: Calculates final exam grade needed based off of
* average current grade, grade needed, and exam worth.
* --------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* Initializes the variables used in the code */
    char desiredGrade;
    float minimumAVG, currentAVG, examWorth, gradeNeeded;

    /* ---------------------------------------------------- */
    printf("Enter desired grade> ");
    scanf("%c", &desiredGrade);
    desiredGrade = toupper(desiredGrade);

    printf("Enter minimum average required> ");
    scanf("%f", &minimumAVG);

    printf("Enter current average in course> ");
    scanf("%f", &currentAVG);

    printf("Enter how much the final counts\nas a percentage of the course grade> ");
    scanf("%f", &examWorth);


    /* Calculates grade needed on the final exam */
    gradeNeeded = ((minimumAVG) + ((100 - examWorth) * currentAVG) / (examWorth * 100));

    /* ----------------------------------------- */


    printf("\nYou need a score of %.2f on the final to get a %c.", gradeNeeded, desiredGrade);

    /* ---------------------------------------------------- */

    /* Ends program */
    printf("\n\n\n");
    return 0;
}
