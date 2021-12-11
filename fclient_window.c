//Created by: Paige Arnold, Alyssa Capehart, Kyle Martin Jurilla, & Jasmine Wilson
//final version
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "fserver_window.c"

int login(void) //Log in function for user
{
    int user_ID; 			//initializes user id, will be assigned to user
    char pwd[30]; 			//character limit of 30 (0-29) for password, pwd is set
    printf("Enter your account ID number: "); 
    scanf("%d", &user_ID);		//scans for the user's id, formatting as an integer
    printf("Enter your password: ");
    scanf("%s", pwd);			//scans for password, formatting as a string
    
    server(user_ID, pwd);		//contacts server function with user's id and password
}

int main(void) { //main function/terminal for action
    char user_type;			//defines user type as a character
    
    puts("Welcome to our server!");	//puts = prints a string only, no digit or format chars
    printf("Are you an Admin(A) or User?(U) "); 
    scanf("%s", &user_type);		//scans for user type U or A, formatting as a string
    user_type = tolower(user_type);	//changes capital letter to lowercase letter of user
    
    if (user_type == 'u'){		//if the user types u, takes user to user terminal
        char client;			//defines client as a character
        printf("Are you a currently existing client? [Y/N] ");
        scanf("%s", &client);		//scans client, formatting as a string
        client = tolower(client);	//changes capital letter to lowercase letter of client
        
        if (client == 'y') {		//if the client types y
            int wrong_login = login();//initialize the variable wrong login to 0, or 1 
            while (wrong_login == 1) {//if password is incorrect (1)
                wrong_login = login();//user will keep logging in until password is correct
            }
        }
        
        if (client == 'n') {		//if the client types n
            add_user();		//calls for add user 
        }
        
    }
    
    if (user_type=='a') {		//if the user types a, takes user to admin terminal
        char apwd[30];			//character limit of 30 for password, pwd is set
        
        printf("Enter the admin password for this server: ");
        scanf("%s", apwd);		//scans for admin password, formatting as a string
        
        admin(apwd);			//contacts admin terminal with the admin password
    }
}
