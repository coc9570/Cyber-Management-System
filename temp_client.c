//Work in progress - Jazz
//Paige added
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "temp_server.c"


int login(void)
{
    int user_ID;
    char pwd[30];
    printf("Enter your account ID number: ");
    scanf("%d", &user_ID);
    printf("Enter your password: ");
    scanf("%s", pwd);
    
    server(user_ID, pwd);
}

int main(void) {
    char user_type;
    
    puts("Welcome to our server!");
    printf("Are you an Admin(A) or User?(U) ");
    scanf("%s", &user_type);
    user_type = tolower(user_type);
    
    if (user_type == 'u'){
        char client;
        
        printf("Are you a currently existing client? [Y/N] ");
        scanf("%s", &client);
        client = tolower(client);
        
        if (client == 'y') {
            int wrong_login = login();
            while (wrong_login == 1) {
                wrong_login = login();
            }
        }
        
        if (client == 'n') {
            //add_user();
        }
        
    }
    
    if (user_type=='a') {
        char apwd[30];
        
        printf("Enter the admin password for this server: ");
        scanf("%s", apwd);
        
        //admin(apwd);
    }
}
