//
//  main.c
//  Extra Credit Project
//
//  Created by Reuben George on 12/9/22.
//

#include "functions.c" //functions file
#include "header.h" //header file

int main(void) {
    printTitle(); //print the title of the application
    readFile(records); //reads the monthly sales text file which inlcudes the months and sales amounts
    
    char monthedit[3]; //array for edit function
    double newAmount; //variable for edit function
    char monthshort[3]; //array for view function
    char command[10]; //array for whole program
    
    
    while(strcmp (command,"quit")) //The program will run until you type in quit.
    {
        printMenu();
        printf("Command: " );
        scanf("%s", &command);
        
        //The first part of the program asks you what task you want to do by having you type in the name of the task from the task menu which is also printed due to the printMenu function. The string you type in is saved in the command variable.
        
        if (strcmp(command,"show") == 0)
        {
            show(records); //If you type in show, then the program will show the file which includes the months and their sales amounts.
        }
        else if (strcmp(command,"view") == 0)
        {
            printf("Enter a month: ");
            scanf("%s", &monthshort);
            view(monthshort, records);
            
            //If you type in view then the program will ask you to type in a specific month for which you want to view the sales amount of. After typing in the three-letter abbreviation of the month which will be stored in the array monthshort, the program will show you the sales amount during that month.
        }
        else if (strcmp(command,"max") == 0)
        {
            max(records); //If you type in max then the program will show the highest sales amount that occured in a month
        }
        else if (strcmp(command,"min") == 0)
        {
            min(records); //If you type in min then the program will show the lowest sales amount that occured in a month.
        }
        else if(strcmp(command,"edit") == 0)
        {
        printf("Enter the three-character month to be edited: ");
                scanf("%s", &monthedit);
                printf("Enter new amount: ");
                scanf("%lf", &newAmount);
                printf("$%.2f is updated for %s\n", newAmount, monthedit);
            
                //scanf is used to take input from user
            
                edit(monthedit, newAmount, records);
                show(records);
                writeFile(records);
        }
        
        //If you type in edit, the program will then prompt you to enter the three-letter abbreviation for the month whose sales amount you want to edit (ex. jun). The program will then ask you to enter the new sales amount for that month, and after that is done, the program will show the updated list of the months and their sales amounts.
            
        else    if (strcmp(command,"total") == 0)
        {
                total(records); //If total is typed, the program will add up the sales amounts from each month and print out the total amount.
        }
        else    if (strcmp(command,"quit") == 0)
        {
                quit(); //If quit is typed, the program will stop running.
        }
        else
        {
             printf("Invalid Command! Try Again."); //If a command other than the ones on the print menu are typed, then the program will print out this message since it won't understand the command.
        }
            
        
    }
}
