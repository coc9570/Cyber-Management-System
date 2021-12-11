#include <stdio.h>

int main(void)
{
    FILE *infile;

    if ((infile = fopen("clients.txt", "w")) == NULL) {
        puts("File could not be accessed");
    }
    else {
        //variable names for if we don't HARDCODE
        // unsigned int account;
        // char first[30];
        // char last[30];
        // char password[30];
        // double credit;


        // fprintf(infile, "%d %s %s %s %.2f\n", account, first, last, password, credit)
        fprintf(infile, "%d %s %s %s %.2f\n", 9384, "Olly", "Lun", "*6539jdhi", 40.00);
        fprintf(infile, "%d %s %s %s %.2f\n", 8321, "Ben", "Will", "839FFgdq", 0.00);
        fprintf(infile, "%d %s %s %s %.2f\n", 9383, "Jenny", "Anders", "204749!gp", 50.00);


        fclose(infile);
    }
}
