/*  Program implements a substitution cipher, i.e. encrypts text.
    The KEY provided consists of 26 distinct alphabets and is case insensitive.
    Each of which corresponds to its respective letter from A to Z in terms of order.
    eg. $ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
        plaintext:  Hello, World
        ciphertext: Jrssb, Ybwsp
*/
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int valid(string argv[]);
void encrypt(string argv[], string text, char *cipher);

int main(int argc, string argv[])
{
    // Returns error if user doesn't provides key as command line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Returns error if KEY isn't 26 character long
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // Encrypts text if KEY is valid
    if (valid(argv) == 0)
    {
        string text = get_string("plaintext: ");
        int length = strlen(text);
        char cipher[length];
        // Encrypts text
        encrypt(argv, text, cipher);
        // Prints cipher
        printf("ciphertext: %s\n", cipher);
        return 0;
    }
    else
    {
        return 1;
    }
}




















// Encrypts text
void encrypt(string argv[], string text, char *cipher)
{
    int length = strlen(text);
    int i;

    for (i = 0; i < length; i++)
    {
        char codedletter;
        char ch = text[i];
        int asciival = (int) ch;

        // If alphabet in plain text is in uppercase
        if (asciival > 64 && asciival < 91)
        {
            // An uppercase cypher alphabet is added to ciphertext
            codedletter = (char) argv[1][asciival - 65];
            cipher[i] = toupper(codedletter);
        }
        // If alphabet in plain text is in lowercase
        else if (asciival > 96 && asciival < 123)
        {
            // An lowercase cypher alphabet is added to ciphertext
            codedletter = (char) argv[1][asciival - 97];
            cipher[i] = tolower(codedletter);
        }
        // If character is not an alphabet, it is added to ciphertext as it is
        else
        {
            cipher[i] = ch;
        }
    }
    cipher[i] = '\0';
}

// Validates KEY
int valid(string argv[])
{
    int length = strlen(argv[1]);

    for (int i = 0; i < (length - 1); i++)
    {
        char ch = argv[1][i];
        if (isalpha(ch))
        {
            // Returns error if there are repeated alphabets in KEY
            for (int j = i + 1; j < length; j++)
            {
                if (ch == argv[1][j])
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }
        // Returns error if KEY contains character that isn't an alphabet
        else
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }
    return 0;
}
