#include <stdio.h>
#include <string.h>
#include "server_window.c"


int main(void)
{
    int user_ID;
    char pwd[30];
    printf("Enter your account ID number: ");
    scanf("%d", &user_ID);
    printf("Enter your password: ");
    scanf("%s", pwd);
    
    server(user_ID, pwd);
}





/*Working code for reading and printing out file line by line*/

// int main(void)
// {
//     FILE *infile;

//     if ((infile = fopen("clients.txt", "r")) == NULL) {
//         puts("File could not be accessed");
//     }
//     else {
//         int ID;
//         char password[30];
//         char first[30];
//         char last[30];
//         double credit;

//         // Test, seeing if I can write out all the values in client record
//         fscanf(infile,"%d%29s%29s%29s%lf", &ID, first, last, password, &credit);

//         while(!feof(infile) ){
//             printf("%-10d%-13s%-13s%-13s%7.2f\n", ID, first, last, password, credit);
//             fscanf(infile,"%d%29s%29s%29s%lf", &ID, first, last, password, &credit);
//         }
//         fclose(infile); 
//     }
// }
