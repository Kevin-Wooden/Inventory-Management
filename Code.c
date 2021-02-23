/*This program will go ahead and track the inventory that a store has of watermelons.
It will utilize loops to constantly account for the inventory value*/

#include <stdio.h> //Include Macros
#include <stdlib.h>
#include "Inv.h"
int main() //Define function
{
    int StartingInv = 100; //Initialize and define the starting variables
    char answer1;
    char answer;
    int count = 1;
    printf("Do you want to use the system. Answer with Y or N\n"); //Ask user if they want to use the system
    scanf_s(" %c", &answer1); //Scan for answer
    do {
        if (answer1 != 'Y') { //Determine if answer is Y
            break;
        }
        printf("Today is day %d of tracking watermelon inventory.\n", count); 
        int amountSold; //Define variables used to track and adjust inventory values.
        int remaining;
        int amountReplenished;
        printf("Were Watermelons sold? Answer Y or N\n"); //Ask user if watermelons were sold.
        scanf_s(" %c", &answer); //Scan for answer
        if (answer == 'Y') { //If answer is Y start the inventory adjustments
            count++; //Add to the daily counter
            printf(Starting_MSG); //Give uesr initial value of watermelons
            printf(Sold_MSG); //Ask user for how many watermelons were sold
            scanf_s("%d", &amountSold); //Scan for value of watermelons sold
            remaining = StartingInv - amountSold; //Determine remaining watermelons
            printf("The remaining amount of watermelons is %d\n", remaining); //Display remaining watermelon inventory
            StartingInv = remaining;
            if (remaining < 25) { //If watermelon inventory is below 25, ask to replenish inventory.
                printf("You need to replenish the inventory.\n"); //Tell user they need to replenish inventory
                printf("Input how many watermelons to replenish: \n"); //Ask user for how many watermelons to replenish
                scanf_s("%d", &amountReplenished); //Scan for user replenish value
                StartingInv = amountReplenished + remaining; //Calculate the new starting value
                printf("There are now %d watermelons in stock\n", StartingInv); //List the new starting inventory for the next day
            }
            printf("Do you want to document tomorrows sales? Answer Y or N\n"); //Ask user if they want to restart the loop and document the next day's sales.
            scanf_s(" %c", &answer); //Scan for user's answer
            if (answer != 'Y') {
                break; //Exit Program
            }
        }
        else
            break;

    } while (answer1 = 'Y'); //Condition for do-while loop

    return 0; //End of function
}

