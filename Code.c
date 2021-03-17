/*This program will go ahead and track the inventory that a store has of watermelons.
It will utilize loops to constantly account for the inventory value*/

#include <stdio.h> //Include Macros
#include <stdlib.h>
#include <string.h>
#include "Inv.h"
int count = 1;
char answer;
char answer1;
char answer2;
char Fruits[5][15] = { "Watermelons", "Kiwis", "Strawberries", "Pineapples", "Blueberries" };
int Fruit_inv[5] = { 100, 200, 400, 250, 400 };
int Watermelonsreturn();
int Kiwisreturn();
int Strawberriesreturn();
int Pineapplesreturn();
int Blueberriesreturn();

int main() //Define function
{
    //Initialize and define the starting variables
    char* w = Fruits[0];
    char* k = Fruits[1];
    char* s = Fruits[2];
    char* p = Fruits[3];
    char* b = Fruits[4];

    printf("Do you want to use the system. Answer with Y or N\n"); //Ask user if they want to use the system
    scanf("%c", &answer1); //Scan for answer
    do {
        if (answer1 != 'Y') { //Determine if answer is Y
            break;
        }
        printf("What inventory do you want to track? Watermelons, Kiwis, Strawberries, Pineapples, or Blueberries?\n");
        char test[15];
        scanf("%s", test);
        if (strcmp(w, test) == 0) {
            printf("Were Watermelons sold? Answer Y or N\n");
            scanf("%s", &answer2);
            Watermelonsreturn();
        }
        if (strcmp(k, test) == 0) {
            printf("Were Kiwis sold? Answer Y or N\n");
            scanf("%s", &answer2);
            Kiwisreturn();
        }
        if (strcmp(s, test) == 0) {
            printf("Were Strawberries sold? Answer Y or N\n");
            scanf("%s", &answer2);
            Strawberriesreturn();
        }
        if (strcmp(p, test) == 0) {
            printf("Were Pineapples sold? Answer Y or N\n");
            scanf("%s", &answer2);
            Pineapplesreturn();
        }
        if (strcmp(b, test) == 0) {
            printf("Were Blueberries sold? Answer Y or N\n");
            scanf("%s", &answer2);
            Blueberriesreturn();
        }
        scanf("%c", &answer1);
        if (answer1 != 'Y') {
            break; //Exit Program
        }
    } while (answer1 == 'Y'); //Condition for do-while loop

    return 0; //End of function
}


int Watermelonsreturn() {
    int StartingWatermelon = Fruit_inv[0];
    int amountSold; //Define variables used to track and adjust inventory values.
    int remaining;
    int amountReplenished;
    if (answer2 == 'Y') {
        printf("Today is day %d of tracking watermelon inventory.\n", count);
        count++; //Add to the daily counter
        printf(Starting_MSG); //Give user initial value of watermelons
        printf(Sold_MSG); //Ask user for how many watermelons were sold
        scanf("%d", &amountSold); //Scan for value of watermelons sold
        remaining = StartingWatermelon - amountSold; //Determine remaining watermelons
        printf("The remaining amount of watermelons is %d\n", remaining); //Display remaining watermelon inventory
        StartingWatermelon = remaining;
        if (remaining < 25) { //If watermelon inventory is below 25, ask to replenish inventory.
            printf("You need to replenish the inventory.\n"); //Tell user they need to replenish inventory
            printf("Input how many watermelons to replenish: \n"); //Ask user for how many watermelons to replenish
            scanf("%d", &amountReplenished); //Scan for user replenish value
            StartingWatermelon = amountReplenished + remaining; //Calculate the new starting value
            printf("There are now %d watermelons in stock\n", StartingWatermelon); //List the new starting inventory for the next day
        }
    }
    Fruit_inv[0] = StartingWatermelon;
    printf("Do you want to document tomorrows sales? Answer Y or N\n"); //Ask user if they want to restart the loop and document the next day's sales.
    scanf("%c", &answer1);
    return 0;
}
int Kiwisreturn() {
    int StartingKiwi = Fruit_inv[1];
    int amountSold2; //Define variables used to track and adjust inventory values.
    int remaining2;
    int amountReplenished2;
    if (answer2 == 'Y') {
        printf("Today is day %d of tracking Kiwi inventory.\n", count);
        count++; //Add to the daily counter
        printf(Starting_MSG1); //Give uesr initial value of Kiwis
        printf(Sold_MSG1); //Ask user for how many Kiwis were sold
        scanf("%d", &amountSold2); //Scan for value of Kiwis sold
        remaining2 = StartingKiwi - amountSold2; //Determine remaining Kiwis
        printf("The remaining amount of Kiwis is %d\n", remaining2); //Display remaining Kiwi inventory
        StartingKiwi = remaining2;
        if (remaining2 < 25) { //If Kiwi inventory is below 25, ask to replenish inventory.
            printf("You need to replenish the inventory.\n"); //Tell user they need to replenish inventory
            printf("Input how many Kiwis to replenish: \n"); //Ask user for how many Kiwis to replenish
            scanf("%d", &amountReplenished2); //Scan for user replenish value
            StartingKiwi = amountReplenished2 + remaining2; //Calculate the new starting value
            printf("There are now %d Kiwis in stock\n", StartingKiwi); //List the new starting inventory for the next day
        }
    }
    printf("Do you want to document tomorrows sales? Answer Y or N\n"); //Ask user if they want to restart the loop and document the next day's sales.
    scanf("%c", &answer1);
    Fruit_inv[1] = StartingKiwi;
    return 0;
}
int Strawberriesreturn() {
    int StartingStrawberry = Fruit_inv[2];
    int amountSold2; //Define variables used to track and adjust inventory values.
    int remaining2;
    int amountReplenished2;
    if (answer2 == 'Y') {
        printf("Today is day %d of tracking Strawberry inventory.\n", count);
        count++; //Add to the daily counter
        printf(Starting_MSG2); //Give user initial value of Strawberries
        printf(Sold_MSG2); //Ask user for how many Strawberries were sold
        scanf("%d", &amountSold2); //Scan for value of Strawberries sold
        remaining2 = StartingStrawberry - amountSold2; //Determine remaining Strawberries
        printf("The remaining amount of Strawberries is %d\n", remaining2); //Display remaining Strawberry inventory
        StartingStrawberry = remaining2;
        if (remaining2 < 25) { //If Strawberry inventory is below 25, ask to replenish inventory.
            printf("You need to replenish the inventory.\n"); //Tell user they need to replenish inventory
            printf("Input how many Strawberries to replenish: \n"); //Ask user for how many Strawberries to replenish
            scanf("%d", &amountReplenished2); //Scan for user replenish value
            StartingStrawberry = amountReplenished2 + remaining2; //Calculate the new starting value
            printf("There are now %d Strawberries in stock\n", StartingStrawberry); //List the new starting inventory for the next day
        }
    }
    printf("Do you want to document tomorrows sales? Answer Y or N\n"); //Ask user if they want to restart the loop and document the next day's sales.
    scanf("%c", &answer1);
    Fruit_inv[2] = StartingStrawberry;
    return 0;
}
int Pineapplesreturn() {
    int StartingPineapple = Fruit_inv[3];
    int amountSold2; //Define variables used to track and adjust inventory values.
    int remaining2;
    int amountReplenished2;
    if (answer2 == 'Y') {
        printf("Today is day %d of tracking Pinapple inventory.\n", count);
        count++; //Add to the daily counter
        printf(Starting_MSG3); //Give user initial value of Pineapples
        printf(Sold_MSG3); //Ask user for how many Pineapples were sold
        scanf("%d", &amountSold2); //Scan for value of Pineapples sold
        remaining2 = StartingPineapple - amountSold2; //Determine remaining Pineapples
        printf("The remaining amount of Pineapples is %d\n", remaining2); //Display remaining Pineapple inventory
        StartingPineapple = remaining2;
        if (remaining2 < 25) { //If Pineapple inventory is below 25, ask to replenish inventory.
            printf("You need to replenish the inventory.\n"); //Tell user they need to replenish inventory
            printf("Input how many Pineapples to replenish: \n"); //Ask user for how many Pineapples to replenish
            scanf("%d", &amountReplenished2); //Scan for user replenish value
            StartingPineapple = amountReplenished2 + remaining2; //Calculate the new starting value
            printf("There are now %d Pineapples in stock\n", StartingPineapple); //List the new starting inventory for the next day
        }
    }
    printf("Do you want to document tomorrows sales? Answer Y or N\n"); //Ask user if they want to restart the loop and document the next day's sales.
    scanf("%c", &answer1);
    Fruit_inv[3] = StartingPineapple;
    return 0;
}
int Blueberriesreturn() {
    int StartingBlueberry = Fruit_inv[4];
    int amountSold2; //Define variables used to track and adjust inventory values.
    int remaining2;
    int amountReplenished2;
    if (answer2 == 'Y') {
        printf("Today is day %d of tracking Blueberry inventory.\n", count);
        count++; //Add to the daily counter
        printf(Starting_MSG4); //Give user initial value of Blueberries
        printf(Sold_MSG4); //Ask user for how many Blueberries were sold
        scanf("%d", &amountSold2); //Scan for value of Blueberries sold
        remaining2 = StartingBlueberry - amountSold2; //Determine remaining Blueberries
        printf("The remaining amount of Blueberries is %d\n", remaining2); //Display remaining Blueberry inventory
        StartingBlueberry = remaining2;
        if (remaining2 < 25) { //If Blueberry inventory is below 25, ask to replenish inventory.
            printf("You need to replenish the inventory.\n"); //Tell user they need to replenish inventory
            printf("Input how many Blueberries to replenish: \n"); //Ask user for how many Blueberries to replenish
            scanf("%d", &amountReplenished2); //Scan for user replenish value
            StartingBlueberry = amountReplenished2 + remaining2; //Calculate the new starting value
            printf("There are now %d Blueberries in stock\n", StartingBlueberry); //List the new starting inventory for the next day
        }
    }
    printf("Do you want to document tomorrows sales? Answer Y or N\n"); //Ask user if they want to restart the loop and document the next day's sales.
    scanf("%c", &answer1);
    Fruit_inv[4] = StartingBlueberry;
    return 0;
}
