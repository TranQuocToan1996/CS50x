#include <cs50.h>
#include <stdio.h>

// Get positive number for height
int get_height(string string_height)

{
    int int_height; // define local variable for this function
    do
    {
        int_height = get_int("%s", string_height);
    }
    while (int_height < 1 || int_height > 8); //checking the right range between 1 and 8
    return int_height;
}

int main(void) //function to return pyramids
{

    int height = get_height("Please input number from 1 to 8: "); // define global variable for main(void)
    for (int row = 1; row <= height; row++)
    {
        // TODO: print 1st space
        for (int space = height - row; space > 0; space--)
        {
            printf(" ");
        }
        // TODO: prints left hashe
        for (int lefthashes = row; lefthashes > 0 ;  lefthashes--)
        {
            printf("#");

        }
        // TODO: print 2 spaces middle
        printf("  ");
        // TODO: print right hashes
        for (int righthashes = row; righthashes > 0; righthashes--)
        {
            printf("#");

        }
        printf("\n");
    }

}
