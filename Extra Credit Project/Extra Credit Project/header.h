//
//  header.h
//  Extra Credit Project
//
//  Created by Reuben George on 12/9/22.
//

//libraries
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#ifndef header_h
#define header_h

//constant definitions
#define SIZE 12
#define MONTH 4
#define LINE_SIZE 20

//structure definitions
struct SalesData
{
    char month[MONTH]; //initializes array month
    double amount; //initializes variable amount
};

//typedef
struct SalesData records[SIZE];

//function prototypes
void printTitle();
void printMenu();
void readFile(struct SalesData records[]);
void writeFile(struct SalesData records[]);
void show(struct SalesData records[]);
void view(char monthlydata[], struct SalesData records[]);
void max(struct SalesData records[]);
void min(struct SalesData records[]);
void edit(char str[], double newAmount, struct SalesData records[]);
void total(struct SalesData records[]);
void quit();

#endif /* header_h */
