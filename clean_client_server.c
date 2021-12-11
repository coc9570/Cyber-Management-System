#include <stdio.h>
#include <string.h>

int main(void)
{
    int user_ID;
    char pwd[30];
    printf("Enter your account ID number: ");
    scanf("%d", &user_ID);
    printf("Enter your password: ");
    scanf("%s", pwd);
    
    server(user_ID, pwd[30]);
    // I had trouble getting this program to run when I had the below code as a seperate method.
    // The method would have been called server() and the origonal server method is commented out below. 

    ////////////////////////////////////////////////////////////////////////////////////

    // FILE *infile;

    // if ((infile = fopen("clients.txt", "r")) == NULL) {
    //     puts("File could not be accessed");
    // }
    // else 
    // {
    //     int ID;
    //     char password[30];
    //     char first[30];
    //     char last[30];
    //     double credit;
    //     int user_found = 0;

    //     fscanf(infile,"%d%29s%29s%29s%lf", &ID, first, last, password, &credit);

    //     while(!feof(infile) ){
    //         if (ID == user_ID & (strcmp(password, pwd) == 0)) {
    //             user_found = 1;
    //             if (credit == 0) {
    //                 puts("Sorry, you have no credit remaining in your account.");
    //             }
    //             else {
    //                 printf("Hello, %s %s! You are now in the system.\n", first, last);
    //                 printf("Your Current Credit is $%.2f\n", credit);
    //             }
    //         }
    //         fscanf(infile,"%d%29s%29s%29s%lf", &ID, first, last, password, &credit);
    //     }
    //     if (user_found == 0) {
    //         puts("Unfortunately, either you do not have an account \nwith us or you have entered an incorrect password.");
    //     }
    //     fclose(infile); 
    // }
}


/* server method. */ 

int server(int user_ID, char pwd[30])
{
    FILE *infile;

    if ((infile = fopen("clients.txt", "r")) == NULL) {
        puts("File could not be accessed");
    }
    else 
    {
        int ID;
        char password[30];
        char first[30];
        char last[30];
        double credit;
        int user_found = 0;

        fscanf(infile,"%d%29s%29s%29s%lf", &ID, first, last, password, &credit);

        while(!feof(infile) ){
            if (ID == user_ID & (strcmp(password, pwd) == 0)) {
                user_found = 1;
                if (credit == 0) {
                    puts("You have no credit remaining in your account.");
                }
                else {
                    printf("Hello, %s %s! You are now in the system.\n", first, last);
                    printf("Your Current Credit is $%.2f\n", credit);
                }
            }
            fscanf(infile,"%d%29s%29s%29s%lf", &ID, first, last, password, &credit);
        }
        if (user_found == 0) {
            puts("Sorry, unfortunately you do not have an account with us.");
        }
        fclose(infile); 
    }
}




