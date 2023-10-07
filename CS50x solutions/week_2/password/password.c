
#include <cs50.h>
#include <stdio.h>
#include <string.h>


bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool lower_case = false;
    bool upper_case = false;
    bool numbers = false;
    bool symbols = false;
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            lower_case = true;
        }
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            upper_case = true;
        }
        if (password[i] >= '0' && password[i] <= '9')
        {
            numbers = true;
        }
        if ((password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@') || (password[i] >= '[' && password[i] <= '`') || (password[i] >= '{' && password[i] <= '~'))
        {
            symbols = true;
        }

    }
    if (lower_case == true && upper_case == true && numbers == true && symbols == true)
    {
        return true;
    }
    return false;
}

