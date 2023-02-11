#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round(((float)image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tempRed;
    int tempGreen;
    int tempBlue;
    int tempWidth = width - 1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            tempRed = image[i][j].rgbtRed;
            tempGreen = image[i][j].rgbtGreen;
            tempBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][tempWidth - j].rgbtRed;
            image[i][j].rgbtGreen = image[i][tempWidth - j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][tempWidth - j].rgbtBlue;

            image[i][tempWidth - j].rgbtRed = tempRed;
            image[i][tempWidth - j].rgbtGreen = tempGreen;
            image[i][tempWidth - j].rgbtBlue = tempBlue;
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
            int totalRed, totalGreen, totalBlue;
            totalRed = totalGreen = totalBlue = 0;
            float number = 0.00;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    number++;
                }

                temp[i][j].rgbtRed = round(totalRed / number);
                temp[i][j].rgbtGreen = round(totalGreen / number);
                temp[i][j].rgbtBlue = round(totalBlue / number);
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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
            RGBTRIPLE Gx;
            RGBTRIPLE Gy;
            Gx.rgbtRed = Gx.rgbtGreen = Gx.rgbtBlue = 0;
            Gy.rgbtRed = Gy.rgbtGreen = Gy.rgbtBlue = 0;
            int tempTotal;
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    // compute for Gx
                    if (y == -1)
                    {
                        if (x == 0)
                        {
                            if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                            {
                                continue;
                            }
                            else
                            {
                                Gx.rgbtRed += image[currentX][currentY].rgbtRed * -2;
                                Gx.rgbtGreen += image[currentX][currentY].rgbtGreen * -2;
                                Gx.rgbtBlue += image[currentX][currentY].rgbtBlue * -2;
                            }
                        }
                        else
                        {
                            if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                            {
                                continue;
                            }
                            else
                            {
                                Gx.rgbtRed += image[currentX][currentY].rgbtRed * -1;
                                Gx.rgbtGreen += image[currentX][currentY].rgbtGreen * -1;
                                Gx.rgbtBlue += image[currentX][currentY].rgbtBlue * -1;
                            }
                        }
                    }

                    else if (y == 1)
                    {
                        if (x == 0)
                        {
                            if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                            {
                                continue;
                            }
                            else
                            {
                                Gx.rgbtRed += image[currentX][currentY].rgbtRed * 2;
                                Gx.rgbtGreen += image[currentX][currentY].rgbtGreen * 2;
                                Gx.rgbtBlue += image[currentX][currentY].rgbtBlue * 2;
                            }
                        }
                        else
                        {
                            if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                            {
                                continue;
                            }
                            else
                            {
                                Gx.rgbtRed += image[currentX][currentY].rgbtRed * 1;
                                Gx.rgbtGreen += image[currentX][currentY].rgbtGreen * 1;
                                Gx.rgbtBlue += image[currentX][currentY].rgbtBlue * 1;
                            }
                        }
                    }

                    // compute for Gy
                    if (x == -1)
                    {
                        if (y == 0)
                        {
                            if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                            {
                                continue;
                            }
                            else
                            {
                                Gx.rgbtRed += image[currentX][currentY].rgbtRed * -2;
                                Gx.rgbtGreen += image[currentX][currentY].rgbtGreen * -2;
                                Gx.rgbtBlue += image[currentX][currentY].rgbtBlue * -2;
                            }
                        }
                        else
                        {
                            if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                            {
                                continue;
                            }
                            else
                            {
                                Gx.rgbtRed += image[currentX][currentY].rgbtRed * -1;
                                Gx.rgbtGreen += image[currentX][currentY].rgbtGreen * -1;
                                Gx.rgbtBlue += image[currentX][currentY].rgbtBlue * -1;
                            }
                        }
                    }
                    else if (x == 0)
                    {
                        Gx.rgbtRed += 0;
                        Gx.rgbtGreen += 0;
                        Gx.rgbtBlue += 0;
                    }
                    else if (x == 1)
                    {
                        if (y == 0)
                        {
                            if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                            {
                                continue;
                            }
                            else
                            {
                                Gx.rgbtRed += image[currentX][currentY].rgbtRed * 2;
                                Gx.rgbtGreen += image[currentX][currentY].rgbtGreen * 2;
                                Gx.rgbtBlue += image[currentX][currentY].rgbtBlue * 2;
                            }
                        }
                        else
                        {
                            if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                            {
                                continue;
                            }
                            else
                            {
                                Gx.rgbtRed += image[currentX][currentY].rgbtRed * 1;
                                Gx.rgbtGreen += image[currentX][currentY].rgbtGreen * 1;
                                Gx.rgbtBlue += image[currentX][currentY].rgbtBlue * 1;
                            }
                        }
                    }
                }
            }

            temp[i][j].rgbtRed = round(sqrt((Gx.rgbtRed * Gx.rgbtRed) + (Gy.rgbtRed + Gy.rgbtRed)));
            temp[i][j].rgbtGreen = round(sqrt((Gx.rgbtGreen * Gx.rgbtGreen) + (Gy.rgbtGreen + Gy.rgbtGreen)));
            temp[i][j].rgbtBlue = round(sqrt((Gx.rgbtBlue * Gx.rgbtBlue) + (Gy.rgbtBlue + Gy.rgbtBlue)));

            if (temp[i][j].rgbtRed > 255)
            {
                temp[i][j].rgbtRed = 255;
            }
            if (temp[i][j].rgbtGreen > 255)
            {
                temp[i][j].rgbtGreen = 255;
            }
            if (temp[i][j].rgbtBlue > 255)
            {
                temp[i][j].rgbtBlue = 255;
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
