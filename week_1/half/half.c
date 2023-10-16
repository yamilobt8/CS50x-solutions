// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");
    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{

    float tax_amount = bill * (tax / 100);

    float bill_tax_amount = bill + tax_amount;

    float tip_amount = bill_tax_amount * ((float)tip / 100);

    float bill_tax_tip_amount = bill_tax_amount + tip_amount;

    float amount = bill_tax_tip_amount / 2;

    return amount;
}
