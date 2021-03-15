#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) //if the user provided more than one command line argument (remember program name counts as 1)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    if (strlen(argv[1]) != 26) //if length of argument isnt 26
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    string s = argv[1];
    for (int i = 0, j = strlen(s); i < j; i++) //check to make sure all characters are alphabetic
        if (isalpha(s[i]) == 0) //isalpha returns non-zero value if character in array/string is a letter
        {
            printf("Invalid key\n");
            return 1;
        }

    for (int a = 0, b = strlen(s); a < b; a++) //check if character in key (s) is uppercase, if not, change to uppercase
    {
        if (isupper(s[a]) != 0)
        {
            s[a] = s[a];
        }
        else
        {
            s[a] = toupper(s[a]);
        }
    }
    for (int f = 0, g = strlen(s); f < g; f ++)
    {
        char dup = s[f]; //create a character variable of first letter in key
        int checkdup = 0; //intitalize integer to 0
        for (int u = 0, v = strlen(s); u < v; u ++) //go through the key
        {
            if (dup == s[u]) //if letter is equal to first character in key
            {
                checkdup = checkdup + 1; //add one to checkdup
            }

        }
        if (checkdup > 1) //if checkdup greater than one (i.e. character appears more than once), print error
        {
            printf("Must not repeat letters.\n");
            return 1;
        }
    }
    string text = get_string("plaintext: "); //get user input to be ciphered (called text)
    char cipher[strlen(text)]; //initialize cipher to be same length as input
    strcpy(cipher, text); // copy text into cipher to start with, then manipulate cipher below
    for (int y = 0, k = strlen(cipher); y < k; y++)
        if (isalpha(text[y]) == 0) //if value in plain test is not a letter, leave it as it is
        {
            cipher[y] = text[y];
        }
        else if (isupper(text[y]) != 0) //if the value in plain text is an uppercase letter
        {
            for (int z = 0, l = strlen(cipher); z < l; z ++) //starting with the first char in plain text
            {
                for (int x = 0; x < 26; x ++) //count from 0 to 26
                {
                    int letter = 65 + x;
                    if (text[z] == letter) //if letter is A
                    {
                        cipher[z] = s[x]; //set first variable in in cipher to the first character in key
                    }

                }
            }
        }
        else if (islower(text[y]) != 0) //if the value in plain text is a lowercase letter
        {
            for (int m = 0, p = strlen(cipher); m < p; m ++) //starting with the first char in plain text
            {
                for (int q = 0; q < 26; q ++) //count from 0 to 26
                {
                    int letter = 65 + q;
                    if (text[m] == letter + 32) //if letter is A
                    {
                        cipher[m] = s[q] + 32; //set first variable in in cipher to the first character in key
                    }

                }
            }
        }
    printf("ciphertext: %s", cipher);
    printf("\n");
    //printf("text %lu, cipher %lu, key %lu", strlen(text), strlen(cipher), strlen(s));
    return 0;
}

// problems with check 50, need to check is duplicates in key (and if so, key invalid)
