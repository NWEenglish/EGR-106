/***********************************************************************
*
* Name: Nicholas English
* Date: 11/26/2017
* Program: Assignment13
* Description: This code reads a file that holds a n value, position
* (x, y, z), and also holds its mass. This program runs to format the
* information in a more user friendly way. The program also calculates
* the center of gravity. All of this is displayed in "data.txt".
*
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

/** Default size of the of the array **/
#define MAX 100

/** Takes an open input file and assigns values to an array **/
int fget_point_mass( FILE *fp, int location[][3], int mass[3], int nMAX);

/** Calculates the center of gravity of the system **/
void center_grav( int location[][3], int mass[], int nValue);

/** Writes back to the file and places the values with "meaningful" labels **/
void fwrite_point_mass(  FILE *fp, int location[][3], int mass[], int nValue, float centerOfGravity[3]);

    /** Variable(s) **/
    FILE *fpin;
    FILE *fpout;
    int temp;
    int location[MAX][3];
    int mass[3];
    int nValue;
    int nMAX = 10;
    int sum;
    float centerOfGravity[3];

int main() {


    // Assigns the file pointers to a file
    fpin = fopen( "mass_position.txt", "r" );
    fpout = fopen( "data.txt", "w" );

    /** Checks if the files exists **/
    // Runs if it does NOT exist and then ends the program
    if ( fpin == 0 ) {
        printf("\nFile could not be opened\n");
        exit (-1);
    }

    // Runs if the file DOES exist
    else {


        // Runs to set values to arrays and find the nValue
        printf("\n Extracting data from file...");
        nValue = fget_point_mass( fpin, location, mass, nMAX);
        printf("\n Data collected successfully!");
        fclose( fpin );

        // Runs to find the centerOfGravity
        printf("\n\n Finding center of gravity...");
        center_grav( location, mass, nValue );
        printf("\n Center of gravity calculated!");

        // Runs to write the values to the file
        printf("\n\n Writing to file information...");
        fwrite_point_mass( fpout, location, mass, nValue, centerOfGravity );
        printf("\n Data written successfully!");
        printf("\n Data has been written to \"data.txt\"");
        fclose( fpout );

    }

    /** End of code reached **/
    printf("\n\n\n");
    return 0;
}

/**********************************************************************/

/** Takes an open input file and assigns values to an array **/
int fget_point_mass( FILE *fp, int location[][3], int mass[], int nMAX) {

    // Variable(s)
    int i;
    int j;
    int nValue;

    // Finds the nValue
    fscanf( fp, "%d", &nValue );

        /** Loops through the up-down direction of the text file **/
        for ( i = 0; i < nValue; i++ ) {

            /** Loops through the left-right direction of the text file **/
            for ( j = 0; j <= 3; j++ ) {

                // Assigns values to the mass array
                if ( j == 3 )
                    fscanf( fp, "%d", &mass[ i ] );

                // Assigns the location to the array
                else
                    fscanf( fp, "%d", &location[ i ][ j ]);
            }
        }

    return nValue;
}

/**********************************************************************/

/** Calculates the center of gravity of the system **/
void center_grav( int location[][3], int mass[], int nValue) {

    // Variable(s)
    int totalMass = 0;
    int i;
    int j;

    /** Calculations **/
    // Beginning calculation
    for ( i = 0; i < nValue; i++) {

        // Finds totalMass
        totalMass = totalMass + mass[i];

        // Finds the center (beginning part)
        for ( j = 0; j < 3; j++)
            centerOfGravity[ j ] = centerOfGravity[ j ] + ( mass[ i ] * location[ i ][ j ] );
    }

    // Finds the center (final part)
    for ( i = 0; i < 3; i ++)
        centerOfGravity[ i ] = ( centerOfGravity[ i ] / totalMass );
}

/**********************************************************************/

/** Writes back to the file and places the values with "meaningful" labels **/
void fwrite_point_mass(  FILE *fp, int location[][3], int mass[], int nValue, float centerOfGravity[]) {

    // Variable(s)
    int i;

    /** Prints locations **/
    // Initial line for locations
    fprintf(fp, " location %2d\t  %2d\t  %2d", location[0][0], location[0][1], location[0][2]);

    // Loops through the rest of the locations
    for ( i = 1; i < nValue; i++ )
        fprintf(fp,"\n\t  %2d\t  %2d\t  %2d", location[i][0], location[i][1], location[i][2] );

    /** Prints mass **/
    // Initial line for mass
    fprintf(fp,"\n\n mass\t %2d", mass[0]);

    // Loops through the rest of the masses
    for ( i = 1; i < nValue; i++ )
        fprintf(fp,"\n\t %2d", mass[ i ]);

    /** Prints the n value **/
    fprintf(fp,"\n\n n\t %2d", nValue);

    /** Prints the center of gravity **/
    fprintf(fp,"\n\n center   %.2f     %.2f    %.2f", centerOfGravity[0], centerOfGravity[1], centerOfGravity[2] );

}
