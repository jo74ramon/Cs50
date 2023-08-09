#include "math.h"
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int gblue = image[row][column].rgbtBlue;
            int ggreen = image[row][column].rgbtGreen;
            int gred = image[row][column].rgbtRed;
            int rgbGray = round((gblue + ggreen + gred) / 3.0);
            image[row][column].rgbtBlue = rgbGray;
            image[row][column].rgbtGreen = rgbGray;
            image[row][column].rgbtRed = rgbGray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int blue = image[row][column].rgbtBlue;
            int green = image[row][column].rgbtGreen;
            int red = image[row][column].rgbtRed;
            int sblue = round(red * 0.272) + ((green) * (0.534)) + ((blue) * (0.131));
            int sgreen = round(((red) * (0.349)) + ((green) * (0.686)) + ((blue) * (0.168)));
            int sred = round(((red) * (0.393)) + ((green) * (0.769)) + (blue * (0.189)));
            if (sblue > 255) sblue = 255;
            if (sgreen > 255) sgreen = 255;
            if (sred > 255) sred = 255;
            image[row][column].rgbtBlue = sblue;
            image[row][column].rgbtGreen = sgreen;
            image[row][column].rgbtRed = sred;
            //  if (sblue > 255)
            // {
            //     sblue = 255;
            // }
            //  if (sgreen > 255)
            // {
            //     sgreen = 255;
            // }
            //  if (sred > 255)
            // {
            //     sred = 255;
            // }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width / 2; column++)
        {
            temp = image[row][column];
            image[row][column] = image[row][width - column - 1];
            image[row][width - column - 1] = temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    for (int column = 1, row = 0; column < width -1; column++)
    {
        int cblue = image[row][column].rgbtBlue;
        int cgreen = image[row][column].rgbtGreen;
        int cred = image[row][column].rgbtRed;
        int lblue = image[row][column - 1].rgbtBlue;
        int lgreen = image[row][column - 1].rgbtGreen;
        int lred = image[row][column - 1].rgbtRed;
        int rblue = image[row][column + 1].rgbtBlue;
        int rgreen = image[row][column + 1].rgbtGreen;
        int rred = image[row][column + 1].rgbtRed;
        int rdblue = image[row + 1][column + 1].rgbtBlue;
        int rdgreen = image[row + 1][column + 1].rgbtGreen;
        int rdred = image[row + 1][column + 1].rgbtRed;
        int dblue = image[row + 1][column].rgbtBlue;
        int dgreen = image[row + 1][column].rgbtGreen;
        int dred = image[row + 1][column].rgbtRed;
        int ldblue = image[row + 1][column - 1].rgbtBlue;
        int ldgreen = image[row + 1][column - 1].rgbtGreen;
        int ldred = image[row + 1][column - 1].rgbtRed;

        int avgblue = (cblue + lblue + rblue + rdblue + dblue + ldblue) / 6;
        int avggreen = (cgreen + lgreen + rgreen + rdgreen + dgreen + ldgreen) / 6;
        int avgred = (cred + lred + rred + rdred + dred + lred) / 6;

        image[row][column].rgbtBlue = avgblue;
        image[row][column].rgbtGreen = avggreen;
        image[row][column].rgbtRed = avgred;

        }

    for (int row = 1; row < height - 1; row++)
    {
        for (int column = 1; column < width -1; column++)
        {
            int cblue = image[row][column].rgbtBlue;
            int cgreen = image[row][column].rgbtGreen;
            int cred = image[row][column].rgbtRed;
            int lblue = image[row][column - 1].rgbtBlue;
            int lgreen = image[row][column - 1].rgbtGreen;
            int lred = image[row][column - 1].rgbtRed;
            int lublue = image[row - 1][column - 1].rgbtBlue;
            int lugreen = image[row - 1][column - 1].rgbtGreen;
            int lured = image[row - 1][column - 1].rgbtRed;
            int ublue = image[row - 1][column].rgbtBlue;
            int ugreen = image[row - 1][column].rgbtGreen;
            int ured = image[row - 1][column].rgbtRed;
            int rublue = image[row - 1][column + 1].rgbtBlue;
            int rugreen = image[row - 1][column + 1].rgbtGreen;
            int rured = image[row - 1][column + 1].rgbtRed;
            int rblue = image[row][column + 1].rgbtBlue;
            int rgreen = image[row][column + 1].rgbtGreen;
            int rred = image[row][column + 1].rgbtRed;
            int rdblue = image[row + 1][column + 1].rgbtBlue;
            int rdgreen = image[row + 1][column + 1].rgbtGreen;
            int rdred = image[row + 1][column + 1].rgbtRed;
            int dblue = image[row + 1][column].rgbtBlue;
            int dgreen = image[row + 1][column].rgbtGreen;
            int dred = image[row + 1][column].rgbtRed;
            int ldblue = image[row + 1][column - 1].rgbtBlue;
            int ldgreen = image[row + 1][column - 1].rgbtGreen;
            int ldred = image[row + 1][column - 1].rgbtRed;

            int avgblue = (cblue + lblue + lublue + ublue + rublue + rblue + rdblue + dblue + ldblue) / 9;
            int avggreen = (cgreen + lgreen + lugreen + ugreen + rugreen + rgreen + rdgreen + dgreen + ldgreen) / 9;
            int avgred = (cred + lred + lured + ured + rured + rred + rdred + dred + lred) / 9;

            image[row][column].rgbtBlue = avgblue;
            image[row][column].rgbtGreen = avggreen;
            image[row][column].rgbtRed = avgred;




        }
    }
    return;
}
