/***********************************************************************
*
* Debugger: Nicholas English
* Date: 11/4/17
* Program: EGR106_SEC06_Miller_Assignment15part2
*
***********************************************************************/


/*
Author: Bret Miller
Date: 11/4/17
Program: EGR106_SEC06_Miller_Assignment15part2
Description: This program will take inputs from a file called data.txt and
will either display the data in ascending or descending order based on
what the user wishes
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
void instructions(int instruct);
int main()
{
    FILE *fpin;
    int choice=2,size=0,a,b,c,d,x,instruct;
    double list[MAX],num,end;
    fpin=fopen("data.txt","r");
    instructions(instruct);
    while(fscanf(fpin,"%lf",&end)!=EOF)
        size++;
    fclose(fpin);

    printf("Would you like the data to be displayed in ascending or descending order\n(1 for ascending, 0 for descending)");
    scanf("%d",&choice);
    fpin=fopen("data.txt","r");
    if (choice==1)
    {
        int d = 0;
        // HERE
        for(a = size; a >= 0; a--)
        {

            printf("\n\n%d\n\n", size);
            fscanf(fpin, "%lf", &num);

            //if (a==0)
            //    list[a]=num;

            for(b = a; b >= 0; b--)
            {
                // HERE
                if(b == 0)
                    {
                        list[b] = num;
                        break;
                    }

                // HERE
                list[b + 1] = list[b];

                if ( num > list[b] )
                {

                   // else {
                        //list[b-1] = num;
                    //    break;
                    //}

                }
                else if (num <= list[b])
                {
                    list[b] = num;
                    break;
                }
            }
            for(c = 0; c <= d; c++)
            {
                printf("%.2lf ", list[c]);
            }
            printf("\n");
            d++;
        }

    }
    else if(choice==0)
    {

    }


fclose(fpin);
}

void instructions(int instruction)
{
    printf("This program will display a set of values in a file called data.txt\nas it reads each new value.\nYou will decide if you would like the \nvalues displayed in ascending or descending order.");

}
