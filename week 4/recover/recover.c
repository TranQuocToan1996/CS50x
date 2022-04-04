#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <stdbool.h>


#define buffer_size 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    // Check whether there are the file of card
    if (argc != 2)
    {
        printf("Check the input\n");
        return 1;
    }
    // Open that card file and check whether the file can be openned
    char *file = argv[1];
    FILE *input = fopen(file, "r");
    if (input == NULL)
    {
        printf("Could not open the file\n");
        return 2;
    }



    // Create buffer
    unsigned char buffer[buffer_size];

    // first JPEG
    int first_JPEG = 0; // C can't use true and false like python

    // Output image
    FILE *output = NULL;


    // File counter
    int imagecounter = 0;




    // Reading 1 by 1 block until reach the EOF
    while (fread(buffer, buffer_size, 1, input) == 1)
    {
        // Check whether begin of the JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff
            && (buffer[3] & 0xe0) == 0xe0) // only 1 & is present bitwise operator in C
        {
            // Check if the first JPEG
            if (first_JPEG == 1)
            {
                fclose(output);

            }
            else // first_JPEG == 0
            {
                first_JPEG = 1; // Already find first JPEG
            }

            char filename[8];
            sprintf(filename, "%03i.jpg", imagecounter);
            output = fopen(filename, "w");
            imagecounter++;
        }

        if (first_JPEG == 1)
        {
            fwrite(buffer, buffer_size, 1, output);
        }

    }
    // Close all remaining
    fclose(input);
    fclose(output);
    return 0;
}