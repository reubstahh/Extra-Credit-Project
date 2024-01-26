//
//  functions.c
//  Extra Credit Project
//
//  Created by Reuben George on 12/9/22.
//
#include "header.h" //header file
void printTitle()
{
    printf("Product Sales Management Program \n\n");
}

//-----------------------------------------------------------------
//Description: This function prints out the title of the program.
//Name: printTitle
//Parameters: none
//Return: "Product Sales Management Program"
//-----------------------------------------------------------------

void printMenu() //program menu
{
    char *programmenu = "------------------------------------------------ \n"
    "\n\n Task Menu \n\n"
    "Select an option from the tasks below \n"
    "~ show: Display all sales records \n\n"
    "~ view: View an amount of a specified month \n\n"
    "~ max: View the highest sales amount \n\n"
    "~ min: View the lowest sales amount \n\n"
    "~ edit: Edit an amount of a specified month \n\n"
    "~ total: Get the total of all sales \n\n"
    "~ quit: Terminate the program \n\n\n"
    "------------------------------------------------ \n";
    
    puts(programmenu);
}

//-----------------------------------------------------------------
//Description: This function prints out the different tasks and the command you need to type in for the program to do one of those tasks.
//Name: printMenu
//Parameters: none
//Return: the program menu shown above
//-----------------------------------------------------------------

void readFile(struct SalesData records[])
{
    FILE *ptr; //pointer initialization
    char line[LINE_SIZE]; //initializes array line and sets the size to LINE_SIZE which is defined in the header file
    char *substring; //initializes substring as a pointer
    int i, j; //initializes ints i and j

    ptr = fopen("/Users/reubengeorge/Desktop/Cmpe30/Extra Credit Project/Extra Credit Project/monthly_sales.txt", "r"); //location of the monthly sales file, using fopen to open the file and the pointer to access its contents

    if(ptr == NULL)
    {
        puts("Unable to open the file."); //if file wasn't able to be found
        
    }else{
        i = 0;
        
        while(feof(ptr) == 0)
        {
            fgets(line, LINE_SIZE, ptr);
            substring = strtok(line, "\t");
            j = 0;
            
            while(substring != NULL)
            {
                if(j == 0)
                {
                strcpy(records[i].month, substring);
                    j = 1;
                }else{
                    records[i].amount = atof(substring);
                }

                substring = strtok(NULL, "\t");
            }
            i++;
            //using while and if statements to save data from the file into a struct array
        }
    }

    fclose(ptr); //closes the pointer stream
}

//-----------------------------------------------------------------
//Description: This function reads the text file and saves the data back in a struct array
//Name: readFile
//Parameters: struct SalesData records[]
//Return: nothing
//-----------------------------------------------------------------

void writeFile(struct SalesData records[]){
    FILE *ptr; //pointer initialization
    ptr = fopen("/Users/reubengeorge/Desktop/Cmpe30/Extra Credit Project/Extra Credit Project/monthly_sales.txt", "w"); //opening the file
    if(ptr == NULL)
    {
        puts("Unable to open file"); //if file is unable to be located
    }
    else
    {
        for(int i = 0; i < 12; i++)
        {
            fprintf(ptr, "%s\t%.2lf\n", records[i].month, records[i].amount); //using a for loop to write the struct array back to the text file
        }
    }
    fclose(ptr); //closes the pointer stream
}

//-----------------------------------------------------------------
//Description: This function writes the struct array back to the text file.
//Name: writeFile
//Parameters: struct SalesData records[]
//Return: nothing
//-----------------------------------------------------------------
    



void show(struct SalesData records[])
    {
        for( int i = 0; i < 12; i++)
        {
            printf("%s\t$%.2lf\n",records[i].month, records[i].amount);
        }
        //uses a for loop to go through the array and print out the months and their sales amounts
        printf("\n");
    }

//-----------------------------------------------------------------
//Description: This functions shows all the months and their sales amounts.
//Name: show
//Parameters: struct SalesData records[]
//Return: prints all the months and their sales amounts (the records array)
//-----------------------------------------------------------------
    
void view(char monthlydata[], struct SalesData records[])
    {
        for(int i = 0; i < 12; i++)
        {
            if (strcmp(records[i].month, monthlydata) == 0)
            {
                printf("The amount for the month %s is %.2lf\n",monthlydata, records[i].amount);
            }
            //uses a for loop to check the month and its certain sales amount
        }
    }

//-----------------------------------------------------------------
//Description: This function prints the sales amount of a certain month you want to see.
//Name: view
//Parameters: char monthlydata[], struct SalesData records[]
//Return: "The amount for the month ____ is _____" depending on the month you want to look at.
//-----------------------------------------------------------------
    
void max(struct SalesData records[])
    {
        double max_amount = 0; //Initializes variable max_amount and sets it to 0
        
        for(int i = 0; i < 12; i++)
        {
            if(max_amount < records[i].amount)
            {
                max_amount = records[i].amount;
            }
        //uses a for and an if loop to go through the sales amount in the file and sets variable max_amount to whatever the highest sales amount is
    }
        printf("The highest sales amount is $%.2lf\n",max_amount); //print out max_amount
}

//-----------------------------------------------------------------
//Description: This program prints out the highest sales amount on a certain month.
//Name: max
//Parameters: struct SalesData records[]
//Return: "The highest sales amount is ____" depending on whatever the highest sales amount is in the file.
//-----------------------------------------------------------------
    
void min(struct SalesData records[])
    {
        double min_amount = records[0].amount; //initializes the variable min_amount and sets it to the first value in the array
    
        for(int i = 1; i < 12; i++)
        {
            if(min_amount > records[i].amount)
            {
                min_amount = records[i].amount;
            }
            //uses a for and an if loop to go through the sales amount in the file and sets variable min_amount to whatever the loweset sales amount is
            
        }
printf("The lowest sales amount is $%.2lf\n", min_amount); //then prints out the lowest sales amount (min_amount)
    }

//-----------------------------------------------------------------
//Description: The function prints out the lowest sales amount in a certain month.
//Name: min
//Parameters: struct SalesData records[]
//Return: "The lowest sales amount is ___" depending on what the lowest sales amount is.
//-----------------------------------------------------------------
    
void edit(char str[], double newAmount, struct SalesData records[]){
    for (int i = 0; i < 12; i++)
    {    if(strcmp(records[i].month, str) == 0)
        {
            records[i].amount = newAmount;
        }
        //combination of a for and if loop which goes through the array and changes the value of the sales amount and sets it to what you wanted it to be
    }
}

//-----------------------------------------------------------------
//Description:
//Name: edit
//Parameters: char str[], double newAmount, struct SalesData records[]
//Return: the new sales amount for whichever one you changed and the updated monthly sales list
//-----------------------------------------------------------------
void total (struct SalesData records[])
{
        double yearlyTotal = 0; //initializes the variable yearlyTotal and sets it to 0
        for(int i = 0; i < 12; i++)
        {
            yearlyTotal += records[i].amount;
        }
        //for loop which goes through the array and adds up all the monthly sales numbers and sets it to the yearlyTotal variable
        
        printf("Total = %.2lf\n",yearlyTotal); //then prints out the sum
    }

//-----------------------------------------------------------------
//Description: This function adds up all the sales amounts and prints out the total sum.
//Name: total
//Parameters: struct SalesData records[]
//Return: "Total = ____" with the total sum of all sales amounts.
//-----------------------------------------------------------------
    
void quit()
{
    printf("Thank you for using my app.\n"); //statement that is printed when quit is typed in the program
    
}

//-----------------------------------------------------------------
//Description: This functions prints out the quit statement when quit is typed in the program.
//Name: quit
//Parameters: none
//Return: "Thank you for using my app."
//-----------------------------------------------------------------
