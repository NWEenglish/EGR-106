/***********************************************************************
*
* Name: Nicholas English
* Date: 11/14/2017
* Program: Assignment11
* Description: Accepts input from a text file (data.txt) and then goes
*   through the data to find the largest and smallest values. It then
*   calculates the sum and the standard deviation.
*
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *fpin;
FILE *fpout;
float largest;
float smallest;
float average;
float dataArray[ 200 ];
float stdDeviation;
float sum = 0;
float sum_squares = 0;
int length = 0;
float temp;

int main() {

    fpin = fopen( "data.txt", "r" );

    // Checks if the file exists
    if ( (fpin = fopen("data.txt", "r")) == 0 )
        printf("\nFile could not be opened\n");

    else {
        // Opens the file
        fpin = fopen( "data.txt", "r" );

        // Loop that finds the length of the file
        while ( fscanf(fpin, "%f", &temp) != EOF )
            length++;

        // Sets the initial values for largest and smallest variables
        //largest = dataArray[ 0 ];
        //smallest = dataArray[ 0 ];

        // Closes the file
        fclose( fpin );

        // Opens the file
        fpin = fopen( "data.txt", "r" );

        // Loop that finds the largest and smallest variables
        for (int i = 0; i < length; i++) {

            // Sets the initial values for largest and smallest variables
            if ( i == 0) {
            largest = dataArray[ 0 ];
            smallest = dataArray[ 0 ];
            }

            // Stores the value from each line to the array
            fscanf(fpin, "%f", &temp);
            dataArray[ i ] = temp;

            // Sets the initial values for largest and smallest variables
            if ( i == 0) {
            largest = temp;
            smallest = temp;
            }

            // Checks if larger than previous largest variable
            if (largest < dataArray[ i ])
                largest = dataArray[ i ];

            // Checks if smaller than previous smallest variable
            if (smallest > dataArray[ i ])
                smallest = dataArray[ i ];

            // Finds the sum of the array
            sum = sum + dataArray[ i ];

            // Finds the sum of the squares
            sum_squares = sum_squares + pow( dataArray[ i ], 2);
        }
    }

    // Closes the file
    fclose( fpin );

    // Finds the average of the sums
    average = ( sum / length  );

    // Finds the standard deviation
    stdDeviation = sqrt( ( sum_squares / length  ) - pow( average, 2 ) );

    // Opens the file to write to
    fpout = fopen( "output.txt", "w" );

    // Output to the user
    fprintf(fpout, "\n The smallest value is %f", smallest);
    fprintf(fpout, "\n The largest value is %f", largest);
    fprintf(fpout, "\n The standard deviation is %f",  stdDeviation);

    // Closes the file
    fclose( fpout );

    return 0;
}
