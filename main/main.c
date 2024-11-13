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

void update_deposit(const char *balance, double deposit)
{
    double current_balance = 0.0;

    //open the file to read the current balance
    FILE *bal = fopen("balance.txt", "r");

    if(bal == NULL)
    {
        //if the file does not exist print error
        printf("Error opening file for reading");
    }
    else
    {
        //read the existing balance from the file
        fscanf(bal, "%lf", &current_balance);

        //close the file after reading
        fclose(bal);
    }

    //add the deposit to the current balance
    current_balance += deposit;

    //open the file again in write mode
    bal = fopen("balance.txt","w");

    //write the updated balance back to the file
    fprintf(bal, "%.2f\n", current_balance);

    //close the file
    fclose(bal);

    printf("New balance: %.2f\n", current_balance);
}

int main()
{
    //balance for reading and writing
    const char *balance = "balance.txt";
    double deposit;

    //main menu options = deposit, withdraw, check balance, exit;
    int user_mm_input = 0;  

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
    pwf = fopen("C:\\Users\\alexs\\OneDrive\\Desktop\\GitHub\\CBankManagementSystem\\main\\Database\\pw.txt", "r");

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

    do
    {
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

        if(unvalid == 1)
        {
            printf("Please enter password!\n");
            get_input(pw, sizeof(pw));

            if(strcmp(pw, pwfile) == 0)
            {
                printf("correct password!");
                pwvalid = 1;
            }
            else
            {
                printf("Incorrect!");
            }
        }
    } while (unvalid == 0 || pwvalid == 0);

    //checks if username and password are correct
    if(unvalid == 1 && pwvalid == 1)
    {
        do
        {
            printf("What would you like to do?\n");
            printf("1: Deposit\n2:Withdraw\n3:Check Balance\n4:Exit");

            scanf(" %d", &user_mm_input);

            if(user_mm_input == 1)
            {
                printf("Enter the deposit amount: ");
                scanf("%1f", &deposit);
                update_deposit(balance, deposit);
            }
        } while (user_mm_input != 4);
        
    }

    return 0;
}