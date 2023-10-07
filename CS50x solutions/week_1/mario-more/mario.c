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
        for (int collum = 0; collum < height + 10; collum++)
        {
            // for space between hashes
            if (collum == height || collum == height + 1)
            {
                printf(" ");
            }
            // for the left side of pyramid
            else if (collum < height)
            {
                if (collum + row >= height - 1)
                {
                    printf("#");
                }
                else
                {
                    printf(" ");
                }
             }
             // for the right side of pyramid
             else if (collum > height)
             {
                if (collum - row < height + 3)
                {
                    printf("#");
                }
             }
        }
        printf("\n");
    }
}