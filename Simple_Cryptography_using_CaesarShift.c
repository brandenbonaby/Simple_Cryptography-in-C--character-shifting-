/*Program to cypher text user input text based on the inputted number user enters in cmdline*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char* argv[]) //accept user cmdline input, the first number after whitespace will be used as cypherkey
{

    int h; //creating variables to be used later on
    char get_text[100] = {'\0'};

    if ( argc >  2 || argc == 1 ){
        printf("Usage: ./Caesar *number*  \n");
        return 1;}

    int k = atoi(argv[1]); //convert cmdline input to number
    char* y = argv[1];

    for (int t =0 ; t< strlen(y); t++){ // check that every input character is a number
        if (!(isdigit(y[t]))){
            printf("Usage: ./Caesar *number*\n");
            return 1;}

    }

    //get input & print word ciphertext
    printf("plaintext:  ");
    scanf ("%[^\n]",get_text); //using regular expression to get characters up to \n

    if (strlen(get_text) > 100) {    // handles user overflow of more than 100 characters
		fputs ("only sentences of 100 characters allowed, please try again\n", stderr);
        return 1;

    }
    printf("ciphertext: ");

    //creating loop that will output the cypher text by adding k (number)
    for (int i = 0, n = strlen(get_text); i < n; i++){
        h = (int) get_text[i];
        if (isalpha(get_text[i])  && (h <= 'Z') && (h >= 'A')){  //if function to wrap text
            printf("%c", ((((h - 'A') + k) % 26) + 'A'));

        }

        else if (isalpha(get_text[i]) && (h <= 'z') && (h >= 'a')){//if function to wrap text
            printf("%c", ((((h - 'a') + k) % 26) + 'a'));

        }

        else{ // printing the characters that are not alpha numeric
            printf("%c", h);

        }

    }

    printf("\n"); //print a new line at the end of the program
    return 0;
}
