#include <stdio.h>

int main(void)
{
   FILE *cfPtr; // cfPtr = clients.txt file pointer

   // fopen opens file. Exit program if unable to create file
   if ((cfPtr = fopen("clients.txt", "w")) == NULL) {
      puts("File could not be opened");
   }
   else {
      puts("Enter the account, name, and balance.");
      puts("Enter EOF to end input.");
      printf("%s %s", "? ");

      unsigned int userID; // user ID
      char name[30]; // account name
      char password[30]; //This is where something goes wrong. I dont know how this should be defined. It should be able to act similarly to name from my understanding though.
      double credit; // account credit

      scanf("%d %29s %29s %lf", &userID, name, password, &credit);

      // write userID, name, password and credit into file with fprintf
      while (!feof(stdin)) {
         fprintf(cfPtr, "%d %s %s %.2f\n", userID, name, password, credit); //when adding it here and the scanf below it causes a loop when trying to enter data. If you take out 
         printf("%s", "? ");                                                //everything associated with password so that you are only working with userID, name, and credit
         scanf("%d %29s %29s %lf", &userID, name, password, &credit);       // including the %s in the print/scan... it works perfectly fine.
      }

      fclose(cfPtr); // fclose closes file
   }
}
