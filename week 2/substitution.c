#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(int argc, char *key[])
{
    // 1) Check and get key
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(key[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    int determine_unique_alphabet[26];
    for (int i = 0; i <= strlen(key[1]); i++)
    {
        key[1][i] = toupper(key[1][i]); // Turn into Uppercase for easy processing
        determine_unique_alphabet[key[1][i] - 65]++;
        if (isalpha(key[1][i]) == 0) // non zero number is an alphabet
        {
            printf("Key must be alphabetical characters\n");
            return 1;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (determine_unique_alphabet[i] > 1)
        {
            printf("Key not containing each letter exactly once\n");
            return 1;
        }
    }

    // 2) Get the string need to be ciphered
    char *plaintext = get_string("plaintext: ");

    // 3) Encrypt
    for (int i = 0; i <= strlen(plaintext); i++)
    {
        if (islower(plaintext[i]))
        {
            plaintext[i] = key[1][plaintext[i] - 97];
        }
        else if (isupper(plaintext[i]))
        {
            plaintext[i] = key[1][plaintext[i] - 65];
        }
    }

    // 4) Print ciphertext
    printf("ciphertext: %s\n", plaintext);
    return 0;
}