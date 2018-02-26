/**********************************************************************
*
* Name: Nicholas English
* Date: 11/1/2017
* Program: Assignment9_Problem4
* Description: This is a program that determines whether a quadratic
*   equation has one real root, two real roots, or imaginary roots.
*   Then, if the roots are real, display the roots of the quadratic
*   equation.
*
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/** Used to check the discriminant **/
int discriminant(int, int, int);

int main() {

    /** The coefficients for the quadratic function **/
    float a, b, c;

    /** Checks if the user wants to go again **/
    int again;

    /** Holds the value of the roots **/
    float root1, root2;

    /** The discriminant value **/
    int d;

    // Explains to the user what the program is
    printf("\n This program finds the number of roots whether or not that");
    printf("\n that those roots are real or imaginary. Use the following");
    printf("\n format to determine those coefficients:");
    printf("\n\n\t ax^2 + bx + c = 0\n");

    do {

        // Gets the user input for a,b, and c.
        printf("\n Enter the coefficient for a:\t");
        scanf("%f", &a);
        printf("\n a = %.3f\n", a);
        printf("\n Enter the coefficient for b:\t");
        scanf("%f", &b);
        printf("\n b = %.3f\n", b);
        printf("\n Enter the coefficient for c:\t");
        scanf("%f", &c);
        printf("\n c = %.3f\n", c);

        // Finds the number of roots (and their type).
        d = discriminant(a, b, c);

        // Two real roots
        if (d > 0) {
            root1 = ( ( ( (-1) * b ) + sqrt( pow(b, 2) - ( 4 * a * c ) ) ) / ( 2 * a ) );
            root2 = ( ( ( (-1) * b ) - sqrt( pow(b, 2) - ( 4 * a * c ) ) ) / ( 2 * a ) );
            printf("\n There are two real roots.\n\tX1 = %.3f\n\tX2 = %.3f", root1, root2);

        // One real root
        } else if ( d == 0) {
            root1 = ( ( (-1) * b ) / ( 2 * a ) );
            printf("\n There is only one real root.\n\tX1 = %.3f", root1);

        // Two imaginary roots
        } else {
            root1 = ( ( ( (-1) * b ) + sqrt( abs( pow(b, 2) - ( 4 * a * c ) ) ) ) / ( 2 * a ) );
            root2 = ( ( ( (-1) * b ) - sqrt( abs( pow(b, 2) - ( 4 * a * c ) ) ) ) / ( 2 * a ) );
            printf("\n There are two imaginary roots.\n\tX1 = %.3fi\n\tX2 = %.3fi", root1, root2);

        }

        // Checks if the user wishes to run the program again.
        do {
            printf("\n\n Would you like to run the program again?\n Enter 1 for yes and 0 for now:\t");
            scanf(" %d", &again);

        } while ( again != 1 && again != 0 );

    } while(again);

    return 0;
}

/**********************************************************************
*
* This method is used to calculate the discriminant value.
*
* @param a Holds the a coefficient value
* @param b Holds the b coefficient value
* @param c Holds the c coefficient value
* @return bills Returns the discriminant value.
*
**********************************************************************/
int discriminant(int a, int b, int c) {

    // The discriminant value
    int d;

    d = ( pow(b, 2) - ( 4 * a * c ) );

    return d;
}
