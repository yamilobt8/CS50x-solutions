#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    // for each row
    for (int row = 0; row < height; row++)
    {
        // for each collum
        for (int collum = 0; collum < height; collum++)
        {
            if (row + collum < height - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        // for going to the next ligne after finishing row 0
        printf("\n");
    }
}