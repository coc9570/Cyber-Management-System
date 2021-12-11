//Created by: Paige Arnold, Alyssa Capehart, Kyle Martin Jurilla, & Jasmine Wilson
//final version of Group 7: Cyber Management Project
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int user_count();
int credit_check();
int add_user();
int remove_user();

int server(int user_ID, char pwd[30])		//server function, initializes/calls for user id and pwd
{	
    FILE *infile;				//initializes infile as a file pointer

    if ((infile = fopen("clients.txt", "r")) == NULL) {	//opens clients.txt (where names, info, will be stored) and tests if its null
        puts("File could not be accessed");	//puts = prints a string only, no digit or format chars
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

     	fscanf(infile,"%d%29s%29s%29s%lf", &ID, first, last, password, &credit);		//Reads the line of the file and denotes each section/variables

        while(!feof(infile) ){		//while not end of file
            if (ID == user_ID){		//if the id matches the user input (user_id)
                user_found = 1;		// if user is found, set it = 1 (yes)
                if (strcmp(password, pwd) == 0) {	//compares the strings password and pwd
                    if (credit == 0) {	//credit equals 0 from the file
                        printf("Sorry, %s %s! You have no credit remaining in your account.\n", first, last);
                    }
                    else {
                        printf("\nHello, %s %s! You are now in the system.\n", first, last);
                        printf("Your Current Credit is $%.2f\n", credit);
                        time = credit/5.0;
                        printf("You have %.1f hours on the system.\n", time);
                    }
                }
                else {
                    puts("Sorry, you have input an incorrect password. Please try logging in again.\n");
                    return 1;
                }
            }
            fscanf(infile,"%d%29s%29s%29s%lf", &ID, first, last, password, &credit);	//Reads the line of the file and denotes each section/variables
        }
        if (user_found == 0) {		//if the user is 0, not found
            puts("Hmmm, seems like you don't have an account with us.\nLet's make an account for you!\n");
            add_user();			//perform add user function			
        }
        fclose(infile); 			
    }
    return 0;
}


int admin(char apwd[30]) {	//admin function with admin password set to 30 char.
    if (strcmp(apwd, "password")!=0) {	//comparing the user input with the password
        puts("Sorry, wrong password! Restart system to login as administrator");
    }
    
    else {
        char action=' ';			//action to a blank character
    	int user;
        puts("Actions: \nUser count = 'u'\nCredit for user = 'c'\nAdd user = 'a'\nRemove user = 'r'\nExit = 'x'");
    
        while (action != 'x') {		//while the action is not equivalent to x
            printf("What action would you like to perform: ");
            scanf("%s", &action);		//scans user and sets it to variable
            action = tolower(action);		//puts action input to lowercase letter
            switch(action) {			//beginning of switch for action
                case 'u':
                    user_count();		//runs user count counter
                    break;
                case 'c':
                    printf("Please enter ID to check credit amount: ");
                    scanf("%d", &user);	
                    credit_check(user);	//credit check function
                    break;
                case 'a':
                    add_user();		//runs add user if a is entered
                    break;
                case 'r':
                    remove_user();		//runs remove user if r is entered
                    break;
                case 'x':			//exits loop
                    break;
                default:
                    puts("Invalid input.");	//pops up if no cases/characters above are entered
                    break;
            }
        }
        puts("Thank you for using our system today! Goodbye.");
    }
}

int user_count(void) {				//user count function
    FILE *infile;				//variable infile becomes a file pointer
    int count = 0;
    char c;

    if ((infile = fopen("clients.txt", "r")) == NULL) {	
        puts("File could not be accessed");
    }
    else {
        for (c=getc(infile); c != EOF; c=getc(infile)) {	//if the character is not end of file, it continues
            if (c=='\n')			// if c is a new line
                count += 1;			// add to counter by 1
        }
    }
    fclose(infile);				//closes file
    printf("There are %d users in the system.\n", count);
}

int credit_check(int user) {			//credit check function
    FILE *infile;
    				
    if ((infile = fopen("clients.txt", "r")) == NULL) {	
        puts("File could not be accessed");
    }
    else {
        int ID;
        char password[30];
        char first[30];
        char last[30];
        double credit;
	int print = 0;
 
        while(!feof(infile) ){		//while file is not the end of file
            fscanf(infile,"%d%29s%29s%29s%lf", &ID, first, last, password, &credit);
            if (ID == user) {			//if the id matches the user
                printf("User %d has the remaining credit: $%.2f\n", ID, credit);
                print = 1;
                break;
            }
        }
        fclose(infile);
        if (print == 0)
            printf("User %d not found in system.\n", user);			
    }
}

int add_user(void) {				//add user function
    FILE *infile;				
    
    if ((infile = fopen("clients.txt", "a")) == NULL) {	
        puts("File could not be accessed");
    }
    else {        
        int newID;
        char pass[30];
        char name1[30];
        char name2[30];
        double init_cred;
        
        printf("Enter the User ID, First name, Last name, Password, and starting credit for the account you would like to create: ");
        scanf("%d%s%s%s%lf", &newID, name1, name2, pass, &init_cred);		//scans user input to set to variables
        /* Tests if the user exists in the system already, but didn't work
        int ID;
        char password[30];
        char first[30];
        char last[30];
        double credit;
	
	fscanf(infile,"%d%29s%29s%29s%lf", &ID, first, last, password, &credit);
        
        if (strcmp(first, name1)==0) {
            if (strcmp(last, name2)==0) {
                printf("Sorry, an account for %s %s already exists!", first, last);
            }
        }
        else {
            fprintf(infile, "%d %s %s %s %.2lf\n", newID, name1, name2, pass, init_cred);
            printf("Welcome to our server, %s %s!\n", name1, name2);
        }
        */
        fprintf(infile, "%d %s %s %s %.2lf\n", newID, name1, name2, pass, init_cred); //prints into the file with user's information
        printf("Welcome to our server, %s %s!\n", name1, name2);   
    }
    fclose(infile);   
}


//partially works, breaks after removing user twice
int remove_user(void) {			//remove user function
    FILE *infile, *outfile;	
    
    if ((infile = fopen("clients.txt", "r")) == NULL) {
        puts("File could not be accessed");
    }
    else {
        int ID;
        char password[30];
        char first[30];
        char last[30];
        double credit;
        int user;
        
        printf("Enter a user ID to remove: ");
        scanf("%d", &user);
        
        printf("Working on removing %d...\n", user);
        
        outfile = fopen("clients_replica.txt", "w");
        
        while(!feof(infile)){			//while is not end of file
            fscanf(infile,"%d%29s%29s%29s%lf", &ID, first, last, password, &credit);
            if (ID != user) {			//if id is not user
                fprintf(outfile,"%d %s %s %s %.2lf\n", ID, first, last, password, credit);
            }
        }
        fclose(outfile);
        remove("clients.txt");
        rename("clients_replica.txt", "clients.txt");
    }
    fclose(infile);
}
