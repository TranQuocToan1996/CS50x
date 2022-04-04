#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void)
{
    // Prompt for a paragraph
    char *text = get_string("Text: ");
    // Count letters, words, sentences
    float letters = 0, words, sentences = 0, spaces = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        // 65 ~ 90 and 97 ~122 is the ascii code of letter
        if ((((65 <= text[i]) && (text[i] <= 90)) || ((90 <= text[i]) && (text[i] <= 122)))) // Same with isalpha(text[i])
        {
            letters += 1;
        }
        if (text[i] == 32) // 32 is the ascii code of space or ' '
        {
            spaces += 1;
        }
        if ((text[i] == '!') || (text[i] == '?') || (text[i] == '.'))
        {
            sentences += 1;
        }
    }
    // Calculate
    words = spaces + 1;
    float L = 100 * letters / words;
    float S = 100 * sentences / words;
    // int index_notround = (0.0588 * L - 0.296 * S - 15.8);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    // Print Grade


    // printf("%i\n", index_notround);
    // printf("%i letter(s)\n", letters);
    // printf("%i word(s)\n", words);
    // printf("%i sentence(s)\n", sentences);

    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index < 16)
    {
        printf("Grade %i\n", (int) round(index));
        return 0;
    }
    else
    {
        printf("Grade 16+\n");
        return 0;
    }

}