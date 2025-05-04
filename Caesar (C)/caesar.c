#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int only_digits(string arg);
char rotate(char letter, int key);

int main(int argc, string argv[])
{
    // Verify that the command-line argument is only one argument and a digit
    if (argc != 2 || argc == 1 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // Convert argv[1] `int`
        int key = atoi(argv[1]);

        // Get a plaintext from the user
        string text = get_string("plaintext: ");

        printf("ciphertext: ");

        // For every character in text:
        for (int i = 0, len = strlen(text); i < len; i++)
        {
            // If the character is a letter, rotate
            if (isalpha(text[i]))
            {
                char cipherchar = rotate(text[i], key);
                printf("%c", cipherchar);
            }
            else
            {
                printf("%c", text[i]);
            }
        }

        printf("\n");
    }

    return 0;
}

int only_digits(string arg)
{
    // check that every character in the argument is a digit
    for (int i = 0, len = strlen(arg); i < len; i++)
    {
        if (!(isdigit(arg[i])))
        {
            return false;
        }
        else
        {
            continue;
        }
    }

    return true;
}

char rotate(char letter, int key)
{
    // reduce the letter's value depending if it is lowercase or uppercase
    char base = 0;
    if (islower(letter))
    {
        base = 'a';
    }
    else
    {
        base = 'A';
    }

    // encrypt the letter
    int cipher = (((int) letter - base) + key) % 26;

    return (char) cipher + base;
}
