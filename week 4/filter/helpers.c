#include "helpers.h"
#include <math.h>
#include <stdlib.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float gray = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            gray = round((image[j][i].rgbtRed + image[j][i].rgbtGreen + image[j][i].rgbtBlue) / 3.0) ;
            image[j][i].rgbtRed = gray;
            image[j][i].rgbtGreen = gray;
            image[j][i].rgbtBlue = gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepia_color[3]; // [Red, green, blue]
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sepia_color[0] = round(0.393 * image[j][i].rgbtRed + 0.769 * image[j][i].rgbtGreen + 0.189 * image[j][i].rgbtBlue);
            sepia_color[1] = round(0.349 * image[j][i].rgbtRed + 0.686 * image[j][i].rgbtGreen + 0.168 * image[j][i].rgbtBlue);
            sepia_color[2] = round(0.272 * image[j][i].rgbtRed + 0.534 * image[j][i].rgbtGreen + 0.131 * image[j][i].rgbtBlue);
            for (int RGB = 0; RGB < 3; RGB++)
            {
                if (sepia_color[RGB] > 255)
                {
                    sepia_color[RGB] = 255;
                }
            }
            image[j][i].rgbtRed = sepia_color[0];
            image[j][i].rgbtGreen = sepia_color[1];
            image[j][i].rgbtBlue = sepia_color[2];
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE cache;
    int sumBlue;
    int sumGreen;
    int sumRed;
    for (int i = 0; i < width / 2; i++) // width divide by 2 because symetric of the image
    {
        for (int j = 0; j < height; j++)
        {
            cache = image[j][i];
            image[j][i] = image[j][width - 1 - i]; // minus 1 because the array begin at 0
            image[j][width - 1 - i] = cache;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE sum;
    int sumBlue;
    int sumGreen;
    int sumRed;
    float counter;
    //create a temporary table of colors to not alter the calculations
    RGBTRIPLE cache[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sumBlue = 0;
            sumGreen = 0;
            sumRed = 0;
            counter = 0.0;

            // sums values of the pixel and 8 neighboring ones, skips iteration if it goes outside the pic
            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    sumBlue += image[j + k][i + h].rgbtBlue;
                    sumGreen += image[j + k][i + h].rgbtGreen;
                    sumRed += image[j + k][i + h].rgbtRed;
                    counter++;
                }
            }

            // averages the sum to make picture look blurrier
            cache[j][i].rgbtBlue = round(sumBlue / counter);
            cache[j][i].rgbtGreen = round(sumGreen / counter);
            cache[j][i].rgbtRed = round(sumRed / counter);
        }
    }

    //copies values from temporary table
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i] = cache[j][i];
        }
    }
}