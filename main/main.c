/*
    Program Descriptor: C Bank Management System

    Author: Aleksy Szopinski

    Date: 13/11/2024
*/
//Libraries
#include <stdio.h>
#include <stdlib.h> //for file handling
#include <string.h>

//Symbolic Names
#define NAME 30
#define PW 30
#define ACCS 10

//Struct Templates
struct bank_account
{
    char name[NAME];
    char password[PW];
    float balance;
};


//Function Signatures
void create_account(struct bank_account *);
void view_account(struct bank_account);


int main()
{
    //local variables
    int choice = -1;
    struct bank_account account;
    int i;

    //start program
    printf("Welcome to the C Bank Management System!\n");

    //Main Menu
    while(choice != 0)
    {
        printf("Please choose an option:\n");
        printf("\n1:Create Account\n2:View Account\n3:Transfer Funds\n4:Delete Account\n");
        scanf("%d",&choice);

        //Create Account
        if(choice == 1)
        {
            create_account(&account);
            
            printf("\nYou have created an account!\n");
        }
        //View Accounts
        else if(choice == 2)
        {
            view_account(account);

        }
        //Transfer Funds
        else if(choice == 3)
        {

        }
        //Delete Accounts
        else
        {

        }
    }

    return 0;//end program

}//end main()

void create_account(struct bank_account *account)
{
    
    printf("Enter Account Name:\n");
    while(getchar()!='\n');
    fgets(account->name,NAME,stdin);
    printf("Enter Account Password:\n");
    while(getchar()!='\n');
    fgets(account->password,PW,stdin);
    printf("Enter Starting Balance:\n");
    scanf("%d",account->balance);

    return;
}

void view_account(struct bank_account account)
{
    printf("\nAccount Details:\n");
    printf("Account Name:%s\n",account.name);
    printf("Account Password:%s\n",account.password);
    printf("Account Balance:%d\n",account.balance);

    return;
}