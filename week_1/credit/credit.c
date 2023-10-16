#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int digit_sum(int stored);
int number_stock(string num, long int number_2);
bool string_checker(string num);


int main(void)
{
    // get input from user
    string num;
    do
    {
        num = get_string("Number: ");
    }
    while (string_checker(num) == false);
    // convert input to long int so we simplify the work
    long int number_1 = atol(num);
    long int number_2 = number_1;

    // here we define an loops number to get the things easy
    const int loops = strlen(num) / 2;

    // here we define an array that can store the numbers
    int numbers_storage_1[loops];

    // we loop over the card number to get our needs
    int sum_1 = 0;
    for (int i = 0; i < loops + 1; i++)
    {
        int result = (number_1 % 10) * 2;
        if (i == 0)
        {
            number_1 = number_1 / 10;
        }
        else
        {
            if (result >= 10)
            {
                numbers_storage_1[i] = digit_sum(result);
                sum_1 += numbers_storage_1[i];
                number_1 = number_1 / 100;
            }
            else
            {
                numbers_storage_1[i] = result;
                sum_1 += numbers_storage_1[i];
                number_1 = number_1 / 100;
            }
        }
    }
    int sum_2 = number_stock(num, number_2);
    int sum = sum_1 + sum_2;

    // check if the card is valid or not
    if (sum % 10 == 0)
    {
        if (strlen(num) == 15 && (num[0] == '3' && (num[1] == 4 || num[1] == 7)))
        {
            printf("AMEX\n");
        }
        else if (strlen(num) == 16 && num[0] == '5')
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("VISA\n");
        }
    }
    else if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
}




int number_stock(string num, long int number_2)
{
    const int loops = strlen(num) / 2;

    int numbers_storage[loops];

    for (int i = 0; i < loops; i++, number_2 = number_2 / 100)
    {
        numbers_storage[i] = number_2 % 10;
    }

    int sum = 0;
    for (int j = 0; j < loops; j++)
    {
        sum += numbers_storage[j];
    }
    return sum;
}


int digit_sum(int stored)
{
    int sum = 0;
    int remainder;
    while (stored > 0)
    {
        remainder = stored % 10;
        sum =  sum + remainder;
        stored = stored / 10;
    }
    return sum;
}



bool string_checker(string num)
{
    int check = 0;
    for (int i = 0; i < strlen(num); i++)
    {
        if (check == strlen(num))
        {
            return true;
        }
        else if (num[i] >= '0' && num[i] <= '9')
        {
            check++;
        }
        else
        {
            return false;
        }
    }
    return true;
}