#include <cs50.h>
#include <stdio.h>

int get_first_digits(long number)
{
    while (number > 99) {
        number /= 10;
    }
    return number;
}

int main(void)
{
    long credit;
    int firsttwo;
    int count = 1;
    int sum = 0;
    do
    {
        credit = get_long("Number: ");
    }
    while (credit < 1000000000000 || credit > 9999999999999999);
    firsttwo = get_first_digits(credit);
    for (long i = credit; i > 0; i /= 10)
    {
        if (count % 2 == 0)
        {
            if (i % 10 >= 5)
            {
                sum += ((i % 10) * 2) % 10 + 1;
            }
            else
            {
                sum += (i % 10) * 2;
            }
        }
        else
        {
            sum += i % 10;
        }
        count ++;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (firsttwo >= 40 && firsttwo <= 49)
    {
        printf("VISA\n");
    }
    else if (firsttwo == 34 || firsttwo == 37)
    {
        printf("AMEX\n");
    }
    else if (firsttwo >= 51 && firsttwo <= 55)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
