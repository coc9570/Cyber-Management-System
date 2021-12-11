#include <stdio.h>
#include <string.h>


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
        double time=0;

        fscanf(infile,"%d%29s%29s%29s%lf", &ID, first, last, password, &credit);

        while(!feof(infile) ){
            if (ID == user_ID & (strcmp(password, pwd) == 0)) {
                user_found = 1;
                if (credit == 0) {
                    printf("Sorry, %s %s! You have no credit remaining in your account.\n", first, last);
                }
                else {
                    printf("Hello, %s %s! You are now in the system.\n", first, last);
                    printf("Your Current Credit is $%.2f\n", credit);
                    time = credit/5;
                    printf("You have %.1f hours on the system.\n", time);
                }
            }
            fscanf(infile,"%d%29s%29s%29s%lf", &ID, first, last, password, &credit);
        }
        if (user_found == 0) {
            puts("Sorry, your ID/Password is incorrect or you do not have an account with us, try again.");
        }
        fclose(infile); 
    }
}
 
