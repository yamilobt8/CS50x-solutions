#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int s;
    do
    {
        s = get_int("entre the start population size: ");
    }
    while (s < 9);
    // TODO: Prompt for end size
    int e;
    do
    {
        e = get_int("entre the end popultion size: ");
    }
    while (e < s);
    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (s < e)
    {
        s += (s / 3) - (s / 4);
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}
