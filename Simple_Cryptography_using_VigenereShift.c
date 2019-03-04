/*Program to cypher user inputted text based on the inputted string user types into shell. letter wrapping occuring using modulo operator*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define Alphabet_len 26

// accept user input on the command line
int main(int argc, char * argv[])
{
    //creating variables to be used for letter wrapping
    int h = 0;
    int g = 0;
    int e = 0;
    char get_text[100] = {'\0'}; //initilizating string to be used later

    // printing error annd prompting user should they enter more than 1 argument
    if ( argc >  2 || argc == 1 ){
        printf("Usage: ./vignere Keyword \n");
        return 1;
    }

    char * y = argv[1];// create variable y to shift key

    // check if any of the things user types in are not letters and print error if they are
    for (int t =0 ; t< strlen(y); t++){
        if (!isalpha(y[t])){
            printf("Usage: ./vignere Keyword\n");
            return 1;
        }
    }

    printf("plaintext:  "); //ask user for input and print the word ciphertext
    scanf ("%[^\n]",get_text); //using regular expression to get characters up to \n
    printf("ciphertext: ");
    if (strlen(get_text) > 100) {// handles user overflow of more than 100 characters
		fputs ("only sentences of 100 characters allowed, please try again\n", stderr);
        return 1;
    }

    //creating loop that will output the cypher text by adding K
    for (int i = 0, n = strlen(get_text); i < n; i++){
        h = (int) get_text[i];
        g = e % strlen(y); // creating wrapping affect for K

        if (islower(y[g]) && islower(get_text[i])){
            int k =  ((y[g] - 'a') %  Alphabet_len );
            printf("%c", ((((h-'a')+ k) % Alphabet_len) + 'a')); // wrapping affect for plain text
            e++;
        }
        else if (islower(y[g]) && isupper(get_text[i])){
            int k =  ((y[g] - 'a') %  Alphabet_len);// making k to add to plaintext to encrypt plaintext
            printf("%c", ((((h-'A') +k) % Alphabet_len) + 'A')); // wrapping affect for plain text
            e++;
        }

        if (isupper(y[g]) && isupper(get_text[i])){
            int k =  ((y[g] - 'A') %  Alphabet_len ); // making k to add to plaintext to encrypt plaintext
            printf("%c", (((((h-'A') +k) % Alphabet_len) + 'A'))); // wrapping affect for plain text
            e++;
        }
        else if   (isupper(y[g]) && islower(get_text[i])){
            int k =  ((y[g] - 'A') %  Alphabet_len );// making k to add to plaintext to encrypt plaintext
            printf("%c", ((((h-'a')+ k) % Alphabet_len) + 'a')); // wrapping affect for plain text
            e++;
        }
        else if (!isalpha(get_text[i])){ // printing the characters that are not alpha numeric
            printf("%c", h);
        }
    }

    //print a new line at the end of the program
    printf("\n");
    return 0; // exit once program completes
}

