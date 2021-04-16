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
#define bzero(b,len) (memset((b), '\0', (len)), (void) 0)
int Fruit_inv[5];

struct Fruits { //Create the Structure for each fruit and the associated variables
    int startingvalue;
    char answer;
    int amountsold;
    int remaining;
    int replenished;

};
int Watermelonsreturn();
int Kiwisreturn();
int Strawberriesreturn();
int Pineapplesreturn();
int Blueberriesreturn();
struct Fruits Watermelon;
struct Fruits Kiwi;
struct Fruits Strawberry;
struct Fruits Pineapple;
struct Fruits Blueberry;

int main(int argc, char* argv[]) //Define function
{
    //Initialize and define the starting variables
      // Initializing the file pointer 
    FILE* fs;

    char ch, buffer[64];
    int i = 0, j = 0;

    // Openning the file with file handler as fs 
    fs = fopen("StartingValues.txt", "r+");

    // Read the file unless the file encounters an EOF 
    while (1) {
        // Reads the character where the seeker is currently 
        ch = fgetc(fs);

        // If EOF is encountered then break out of the while loop 
        if (ch == EOF) {
            break;
        }

        // If the delimiter is encounterd(which can be 
        // anything according to your wish) then skip the character 
        // and store the last read array of characters in 
        // an integer array 
        else if (ch == ',') {

            // Converting the content of the buffer into 
            // an array position 
            Fruit_inv[j] = atoi(buffer);

            // Increamenting the array position 
            j++;

            // Clearing the buffer, this function takes two 
            // arguments, one is a character pointer and  
            // the other one is the size of the character array 
            bzero(buffer, 64);

            // clearing the counter which counts the number 
            // of character in each number used for reading 
            // into the buffer. 
            i = 0;

            // then continue 
            continue;
        }
        else {

            // reads the current character in the buffer 
            buffer[i] = ch;

            // increamenting the counter so that the next 
            // character is read in the next position in  
            // the array of buffer 
            i++;
        }
        Fruit_inv[5] = 0;
    }
    char* w = Fruits[0];
    char* k = Fruits[1];
    char* s = Fruits[2];
    char* p = Fruits[3];
    char* b = Fruits[4];
    char User[15];
    char Pass[15];

    printf("Do you want to use the system. Answer with Y or N\n"); //Ask user if they want to use the system
    scanf("%c", &answer1); //Scan for answer
    do {
        if (answer1 != 'Y') { //Determine if answer is Y
            break;
        }
        printf("Input your Username\n");
        scanf("%s", &User);
        if (strcmp("Kevin.Wooden", User) != 0) {
            printf("Wrong Username, restart the program\n");
            break;
        }
        printf("Input your Password\n");
        scanf("%s", &Pass);
        if (strcmp("PassTest", Pass) != 0) {
            printf("Wrong Username, restart the program");
            break;
        }
        printf("Welcome Authorized User.\n");
        printf("What inventory do you want to track? Watermelons, Kiwis, Strawberries, Pineapples, or Blueberries?\n"); //Ask user what inventory the user wants to track.
        char test[15];
        scanf("%s", test); //Depending upon the users answer will initiate the respective inventory management item.
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

    // printing out all the elements that are stored in the 
    // array of integers 
    if (strcmp("Kevin.Wooden", User) && strcmp("PassTest", Pass) == 0) {
        for (i = 0; i < j; i++) {
            printf("%s: %d in stock\n", Fruits[i], Fruit_inv[i]);
        }
    }
    fclose(fs);
    fs = fopen("StartingValues.txt", "w+");
    fprintf(fs, "%d,%d,%d,%d,%d,%d", Fruit_inv[0], Fruit_inv[1], Fruit_inv[2], Fruit_inv[3], Fruit_inv[4], Fruit_inv[5]);
    fclose(fs);

    return 0;
}



int Watermelonsreturn() {
    Watermelon.startingvalue = Fruit_inv[0]; //Define variables used to track and adjust inventory values.
    if (answer2 == 'Y') {
        printf("Today is day %d of tracking watermelon inventory.\n", count);
        count++; //Add to the daily counter
        printf(Starting_MSG); //Give uesr initial value of watermelons
        printf(Sold_MSG); //Ask user for how many watermelons were sold
        scanf("%d", &Watermelon.amountsold); //Scan for value of watermelons sold
        Watermelon.remaining = Watermelon.startingvalue - Watermelon.amountsold; //Determine remaining watermelons
        printf("Do you want to print the remaining amount of Watermelonss? Y or N\n");
        scanf("%s", &Watermelon.answer);
        if (strcmp("Y", &Watermelon.answer) == 0) {
            printf("The remaining amount of Watermelons is %d\n", Watermelon.remaining); //Display remaining watermelon inventory
        }
        Watermelon.startingvalue = Watermelon.remaining;
        if (Watermelon.remaining < 25) { //If watermelon inventory is below 25, ask to replenish inventory.
            printf("You need to replenish the inventory.\n"); //Tell user they need to replenish inventory
            printf("Input how many watermelons to replenish: \n"); //Ask user for how many watermelons to replenish
            scanf("%d", &Watermelon.replenished); //Scan for user replenish value
            Watermelon.startingvalue = Watermelon.replenished + Watermelon.remaining; //Calculate the new starting value
            printf("There are now %d watermelons in stock\n", Watermelon.startingvalue); //List the new starting inventory for the next day
        }
    }
    Fruit_inv[0] = Watermelon.startingvalue;
    printf("Do you want to document tomorrows sales? Answer Y or N\n"); //Ask user if they want to restart the loop and document the next day's sales.
    scanf("%c", &answer1);
    return 0;
}
int Kiwisreturn() {
    Kiwi.startingvalue = Fruit_inv[1]; //Define variables used to track and adjust inventory values.
    if (answer2 == 'Y') {
        printf("Today is day %d of tracking Kiwi inventory.\n", count);
        count++; //Add to the daily counter
        printf(Starting_MSG1); //Give user initial value of watermelons
        printf(Sold_MSG1); //Ask user for how many Kiwis were sold
        scanf("%d", &Kiwi.amountsold); //Scan for value of watermelons sold
        Kiwi.remaining = Kiwi.startingvalue - Kiwi.amountsold; //Determine remaining Kiwis
        printf("Do you want to print the remaining amount of Kiwis? Y or N\n");
        scanf("%s", &Kiwi.answer);
        if (strcmp("Y", &Kiwi.answer) == 0) {
            printf("The remaining amount of Kiwis is %d\n", Kiwi.remaining); //Display remaining Kiwi inventory
        }
        Kiwi.startingvalue = Kiwi.remaining;
        if (Kiwi.remaining < 25) { //If Kiwi inventory is below 25, ask to replenish inventory.
            printf("You need to replenish the inventory.\n"); //Tell user they need to replenish inventory
            printf("Input how many Kiwis to replenish: \n"); //Ask user for how many Kiwis to replenish
            scanf("%d", &Kiwi.replenished); //Scan for user replenish value
            Kiwi.startingvalue = Kiwi.replenished + Kiwi.remaining; //Calculate the new starting value
            printf("There are now %d Kiwis in stock\n", Kiwi.startingvalue); //List the new starting inventory for the next day
        }
    }
    printf("Do you want to document tomorrows sales? Answer Y or N\n"); //Ask user if they want to restart the loop and document the next day's sales.
    scanf("%c", &answer1);
    Fruit_inv[1] = Kiwi.startingvalue;
    return 0;
}

int Strawberriesreturn() {
    Strawberry.startingvalue = Fruit_inv[2]; //Define variables used to track and adjust inventory values.
    if (answer2 == 'Y') {
        printf("Today is day %d of tracking Strawberry inventory.\n", count);
        count++; //Add to the daily counter
        printf(Starting_MSG2); //Give user initial value of Strawberries
        printf(Sold_MSG2); //Ask user for how many Strawberries were sold
        scanf("%d", &Strawberry.amountsold); //Scan for value of Strawberries sold
        Strawberry.remaining = Strawberry.startingvalue - Strawberry.amountsold; //Determine remaining Strawberries
        printf("Do you want to print the remaining amount of Strawberries? Y or N\n");
        scanf("%s", &Strawberry.answer);
        if (strcmp("Y", &Strawberry.answer) == 0) {
            printf("The remaining amount of Strawberries is %d\n", Strawberry.remaining); //Display remaining Strawberries inventory
        }
        Strawberry.startingvalue = Strawberry.remaining;
        if (Strawberry.remaining < 25) { //If Strawberries inventory is below 25, ask to replenish inventory.
            printf("You need to replenish the inventory.\n"); //Tell user they need to replenish inventory
            printf("Input how many Strawberries to replenish: \n"); //Ask user for how many Strawberries to replenish
            scanf("%d", &Strawberry.replenished); //Scan for user replenish value
            Strawberry.startingvalue = Strawberry.replenished + Strawberry.remaining; //Calculate the new starting value
            printf("There are now %d Strawberries in stock\n", Strawberry.startingvalue); //List the new starting inventory for the next day
        }
    }
    printf("Do you want to document tomorrows sales? Answer Y or N\n"); //Ask user if they want to restart the loop and document the next day's sales.
    scanf("%c", &answer1);
    Fruit_inv[2] = Strawberry.startingvalue;
    return 0;
}
int Pineapplesreturn() {
    Pineapple.startingvalue = Fruit_inv[3]; //Define variables used to track and adjust inventory values.
    if (answer2 == 'Y') {
        printf("Today is day %d of tracking Pinapple inventory.\n", count);
        count++; //Add to the daily counter
        printf(Starting_MSG3); //Give user initial value of Pineapples
        printf(Sold_MSG3); //Ask user for how many Pineapples were sold
        scanf("%d", &Pineapple.amountsold); //Scan for value of Pineapples sold
        Pineapple.remaining = Pineapple.startingvalue - Pineapple.amountsold; //Determine remaining Pineapples
        printf("Do you want to print the remaining amount of Pineapples? Y or N\n");
        scanf("%s", &Pineapple.answer);
        if (strcmp("Y", &Pineapple.answer) == 0) {
            printf("The remaining amount of Pineapples is %d\n", Pineapple.remaining); //Display remaining Pineapples inventory
        }
        Pineapple.startingvalue = Pineapple.remaining;
        if (Pineapple.remaining < 25) { //If Pineapples inventory is below 25, ask to replenish inventory.
            printf("You need to replenish the inventory.\n"); //Tell user they need to replenish inventory
            printf("Input how many Pineapples to replenish: \n"); //Ask user for how many Pineapples to replenish
            scanf("%d", &Pineapple.replenished); //Scan for user replenish value
            Pineapple.startingvalue = Pineapple.replenished + Pineapple.remaining; //Calculate the new starting value
            printf("There are now %d Pineapples in stock\n", Pineapple.startingvalue); //List the new starting inventory for the next day
        }
    }
    printf("Do you want to document tomorrows sales? Answer Y or N\n"); //Ask user if they want to restart the loop and document the next day's sales.
    scanf("%c", &answer1);
    Fruit_inv[3] = Pineapple.startingvalue;
    return 0;
}
int Blueberriesreturn() {
    Blueberry.startingvalue = Fruit_inv[4]; //Define variables used to track and adjust inventory values.
    if (answer2 == 'Y') {
        printf("Today is day %d of tracking Blueberry inventory.\n", count);
        count++; //Add to the daily counter
        printf(Starting_MSG4); //Give user initial value of Blueberries
        printf(Sold_MSG4); //Ask user for how many Blueberries were sold
        scanf("%d", &Blueberry.amountsold); //Scan for value of Blueberries sold
        Blueberry.remaining = Blueberry.startingvalue - Blueberry.amountsold; //Determine remaining Blueberries
        printf("Do you want to print the remaining amount of Blueberries? Y or N\n");
        scanf("%s", &Blueberry.answer);
        if (strcmp("Y", &Blueberry.answer) == 0) {
            printf("The remaining amount of Blueberries is %d\n", Blueberry.remaining); //Display remaining Blueberries inventory
        }
        Blueberry.startingvalue = Blueberry.remaining;
        if (Blueberry.remaining < 25) { //If Blueberries inventory is below 25, ask to replenish inventory.
            printf("You need to replenish the inventory.\n"); //Tell user they need to replenish inventory
            printf("Input how many Blueberries to replenish: \n"); //Ask user for how many Blueberries to replenish
            scanf("%d", &Blueberry.replenished); //Scan for user replenish value
            Blueberry.startingvalue = Blueberry.replenished + Blueberry.remaining; //Calculate the new starting value
            printf("There are now %d Blueberries in stock\n", Blueberry.startingvalue); //List the new starting inventory for the next day
        }
    }
    printf("Do you want to document tomorrows sales? Answer Y or N\n"); //Ask user if they want to restart the loop and document the next day's sales.
    scanf("%c", &answer1);
    Fruit_inv[4] = Blueberry.startingvalue;
    return 0;
}
