#include "helpers.h"
#include<math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float g;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            g = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);

            image[i][j].rgbtBlue = g;
            image[i][j].rgbtGreen = g;
            image[i][j].rgbtRed = g;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float r,g,b;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            b = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            g = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            r = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);


           if(r > 255)
           {
               r = 255;
           }
           if(b > 255)
           {
               b = 255;
           }

           if(g > 255)
           {
               g = 255;
           }


           image[i][j].rgbtBlue = b;
           image[i][j].rgbtGreen = g;
           image[i][j].rgbtRed = r;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int n,a,b,c;
    for(int i = 0; i < height; i++)
    {
        n = width - 1;
        for(int j = 0; j < width/2; j++)
        {
            a = image[i][n].rgbtRed;
            image[i][n].rgbtRed = image[i][j].rgbtRed;
            image[i][j].rgbtRed = a;

            b = image[i][n].rgbtGreen;
            image[i][n].rgbtGreen = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = b;

            c = image[i][n].rgbtBlue;
            image[i][n].rgbtBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = c;

            n--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum_blue;
            int sum_green;
            int sum_red;
            float counter;
            sum_blue = sum_green = sum_red = counter = 0;


            if (i >= 0 && j >= 0)
            {
                sum_red += temp[i][j].rgbtRed;
                sum_green += temp[i][j].rgbtGreen;
                sum_blue += temp[i][j].rgbtBlue;
                counter++;
            }

            if (i >= 0 && j - 1 >= 0)
            {
                sum_red += temp[i][j-1].rgbtRed;
                sum_green += temp[i][j-1].rgbtGreen;
                sum_blue += temp[i][j-1].rgbtBlue;
                counter++;
            }

            if (i - 1 >= 0 && j >= 0)
            {
                sum_red += temp[i-1][j].rgbtRed;
                sum_green += temp[i-1][j].rgbtGreen;
                sum_blue += temp[i-1][j].rgbtBlue;
                counter++;
            }

            if (i - 1 >= 0 && j - 1 >= 0)
            {
                sum_red += temp[i-1][j-1].rgbtRed;
                sum_green += temp[i-1][j-1].rgbtGreen;
                sum_blue += temp[i-1][j-1].rgbtBlue;
                counter++;
            }

            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                sum_red += temp[i][j+1].rgbtRed;
                sum_green += temp[i][j+1].rgbtGreen;
                sum_blue += temp[i][j+1].rgbtBlue;
                counter++;
            }

            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                sum_red += temp[i-1][j+1].rgbtRed;
                sum_green += temp[i-1][j+1].rgbtGreen;
                sum_blue += temp[i-1][j+1].rgbtBlue;
                counter++;
            }

            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                sum_red += temp[i+1][j].rgbtRed;
                sum_green += temp[i+1][j].rgbtGreen;
                sum_blue += temp[i+1][j].rgbtBlue;
                counter++;
            }

            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                sum_red += temp[i+1][j-1].rgbtRed;
                sum_green += temp[i+1][j-1].rgbtGreen;
                sum_blue += temp[i+1][j-1].rgbtBlue;
                counter++;
            }

            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                sum_red += temp[i+1][j+1].rgbtRed;
                sum_green += temp[i+1][j+1].rgbtGreen;
                sum_blue += temp[i+1][j+1].rgbtBlue;
                counter++;
            }
        
            image[i][j].rgbtRed = round(sum_red / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
            image[i][j].rgbtBlue = round(sum_blue / counter);
        }
    }
return;
}