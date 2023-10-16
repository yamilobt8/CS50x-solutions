#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // first ask the user for a message.
    string message = get_string("Message: ");
    // convert the given string into a series of 8-bit binary numbers, one for each character of the string
    for (int i = 0; i < strlen(message); i++)
    {
        int k = message[i];
        int counter = 0;
        int bits[BITS_IN_BYTE];
        while (counter < BITS_IN_BYTE)
        {
            if (k % 2 != 0)
            {
                bits[counter] = 1;
            }
            else
            {
                bits[counter] = 0;
            }
            k = k / 2;
            counter++;
        }
        // ga3 hadok data lichdit 3nd bits array an3tihoum lfunction print_bulb m3kosin
        for (int reverse = 8; reverse >= 0; reverse--)
        {
            print_bulb(bits[reverse]);
        }

        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
