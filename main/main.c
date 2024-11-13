/*
    Program Descriptor: C Bank Management System

    Author: Aleksy Szopinski

    Date: 13/11/2024
*/
#include <stdio.h>
#include <string.h> //for strings username and password
#include <stdlib.h> //for file handling

#define UNMAX 8
#define PWMAX 8

void get_input(char *str, int max_len) //declaring function, a char pointer and the max length of the string
{
    //clear the buffer
    if(fgets(str, max_len, stdin) != NULL)
    { //remove trailing newline if present
        str[strcspn(str, "\n")] = 0;
    }
    else
    {
        printf("Error reading input. \n");
        str[0] = '\0'; //Null-terminate the string in case of error
    }
}

void deposit(const char *balance, const char *data)
{

}

int main()
{
    //main menu options = deposit, withdraw, check balance, exit;
    int user_mm_input = 0;  
    int deposit = 1;
    int withdraw = 2;
    int checkbalance = 3;
    int exit = 4;

    //Boolean(but int) for username and password validation
    int pwvalid = 0;
    int unvalid = 0;

    //the username declarations
    char unfile[UNMAX];
    char un[UNMAX]; //string array for username
    FILE *unf;

    //the password declarations
    char pwfile[PWMAX];
    char pw[PWMAX];
    FILE *pwf;

    //opens username file
    unf = fopen("C:\\Users\\alexs\\OneDrive\\Desktop\\GitHub\\CBankManagementSystem\\main\\Database\\un.txt", "r");

    //opens password file
    pwf = fopen("C:\\Users\\alexs\\OneDrive\\Desktop\\GitHub\\CBankManagementSystem\\main\\Database\\un.txt", "r");

    //checks if there is a username in file
    if(unf == NULL)
    {
        printf("Error reading file.\n");
        return 1;
    }

    //checks if there is a password in file
    if(pwf == NULL)
    {
        printf("Error reading file.\n");
        return 1;
    }

    //read the first username from the file
    if(fgets(unfile, sizeof(unfile), unf) != NULL)
    {
        //remove any trailing newline from the file content
        unfile[strcspn(unfile, "\n")] = 0;
    }
    else
    {
        printf("Error reading username from file.\n");
        fclose(unf);

        return 1;
    }

    //read the first password from the file
    if(fgets(pwfile, sizeof(pwfile), pwf) != NULL)
    {
        //remove any trailing newline from the file content
        pwfile[strcspn(pwfile, "\n")] = 0;
    }
    else
    {
        printf("Error reading username from file.\n");
        fclose(pwf);

        return 1;
    }

    //close the files since we no longer need them
    fclose(unf);
    fclose(pwf);

    printf("Welcome to the C Bank Management System\n");

    printf("Please enter username\n");
    get_input(un, sizeof(un));

    if(strcmp(un, unfile) == 0)
    {
        printf("correct username!");
        unvalid = 1;
    }
    else
    {
        printf("incorrect.");
    }

    printf("Please enter password!\n");
    get_input(pw, sizeof(pw));

    if(strcmp(pw, pwfile) == 0)
    {
        print("correct password!");
        pwvalid = 1;
    }
    else
    {
        printf("Incorrect!");
    }

    //checks if username and password are correct
    if(unvalid == 1 && pwvalid == 1)
    {
        do
        {
            printf("What would you like to do?\n");
            printf("1: Deposit\n2:Withdraw\n3:Check Balance\n4:Exit");

            scanf(" %d", &user_mm_input);
        } while (user_mm_input != 1 && user_mm_input != 2 && user_mm_input != 3 && user_mm_input != 4);
        
    }

    return 0;
}