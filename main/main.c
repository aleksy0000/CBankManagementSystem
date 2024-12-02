/*
    Program Descriptor: C Bank Management System

    Author: Aleksy Szopinski

    Date: 13/11/2024
*/
#include <stdio.h>
#include <string.h> //for strings username and password
#include <stdlib.h> //for file handling

int AddAcc()//account management
{
    FILE *fp = fopen("C://Users//alexs//OneDrive//Desktop//GitHub//CBankManagementSystem//main//Database//accountdetails.txt","w");
    if(fp == NULL)
    {
        printf("Could not open file for writing, ending program...\n");

        return 0;
    }
    else
    {
        printf("File opened for writing successfully!");
    }

    fprintf(fp,"2,wexford,john,smith,10,johnny2,wordpass");

    fclose(fp);
}

int ReadDatabase()
{
    FILE *fp;
    fp = fopen("C://Users//alexs//OneDrive//Desktop//GitHub//CBankManagementSystem//main//Database//accountdetails.txt","r");
    if(fp == NULL)
    {
        printf("Could not open file for reading, ending program...\n");
        return 0;//end program
    }//end if(fp == NULL)
    else
    {
        printf("File opened for reading successfully\n");
    }

    //pointers for each column heading in text file
    char *accountid, *branch, *firstname, *lastname, *balance, *username, *password;
    char line[1024];

    //read the header row
    if(fgets(line, sizeof(line), fp))
    {
        printf("Header: %s", line);
    }

    //read each subsequent row
    while(fgets(line, sizeof(line), fp))
    {
        accountid = strtok(line, ",");
        branch = strtok(NULL, ",");
        firstname = strtok(NULL, ",");
        lastname = strtok(NULL, ",");
        balance = strtok(NULL,",");
        username = strtok(NULL,",");
        password = strtok(NULL,",");


        printf("accountid: %s\nbranch: %s\nfirstname: %s\nlastname: %s\nbalance: %s\nusername: %s\npassword: %s\n", accountid, branch, firstname, lastname, balance, username, password);
    }

    fclose(fp);
}

int main()
{
    int userinput = -1;

    printf("Please choose what you'd like to do\n");
    printf("1: Add Account\n");
    printf("2: Delete Account\n");
    printf("3: View Accounts\n");
    printf("0: Exit Account Management\n");

    do
    {
        scanf("%d", &userinput);

        if(userinput = 1) //add account
        {
            AddAcc();
        }
        else if(userinput = 2) //remove account
        {

        }
        else if(userinput = 3) //view accounts
        {
            ReadDatabase();
        }
        
    } while (userinput != 0);

}