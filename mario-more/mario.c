#include <cs50.h>
#include <stdio.h>

// Declares the functions prototypes
int get_height();
void draw_shape(int height);

int main(void)
{
    int height;

    // Do the function get_height and it will give the returned value to the int height
    height = get_height();

    draw_shape(height);
}

// Gets the height from the user
int get_height()
{
    int height;
    // It will prompt the user for the height until he gives a correct value
    do
    {
        height = get_int("Height: \n");
    }
    while (height <= 0 || height >= 9);
    return height;
}

// Function to draw the shape to the desired height
void draw_shape(int height)
{
    for (int line = 1; line <= height; line++)
    {
        for (int spaces = height - 1; spaces >= line; spaces--)
        {
            printf(" ");
        }
        for (int fHash = 1; fHash <= line; fHash++)
        {
            printf("#");
        }
        printf("  ");
        for (int fHash = 1; fHash <= line; fHash++)
        {
            printf("#");
        }
        printf("\n");
    }
}