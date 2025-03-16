#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count;
string card_used;
string company;
int total;

int get_length(long card_num);
void card_type(long card_num);
int checksum(long card_num);

int main(void)
{
    // TODO: Prompt user
    long card_num = get_long("Number: ");

    // TODO: Calculate Checksum
    checksum(card_num);

    // TODO: Check card length
    get_length(card_num);

    // TODO: Print card type
    card_type(card_num);
    printf("%s", company);
    // printf("%s\n", card_used);
}

// Function that gets card length
int get_length(long card_num)
{
    count = 0;
    while (card_num > 0)
    {
        card_num = card_num / 10;
        ++count;
    }
    return count;
}

// Function that checks for card type
void card_type(long card_num)
{
    int bdig = card_num / pow(10, count - 2);
    int vdig = card_num / pow(10, count - 1);

    if (total % 10 != 0)
    {
        company = "INVALID\n";
    }
    else
    {
        if (count == 15 && (bdig == 34 || bdig == 37)) // AMEX
        {
            company = "AMEX\n";
        }
        else if (count == 16 && (bdig == 51 || bdig == 52 || bdig == 53 || bdig == 54 || bdig == 55)) // MASTERCARD
        {
            company = "MASTERCARD\n";
        }
        else if ((count == 13 || count == 16) && vdig == 4)
        {
            company = "VISA\n";
        }
        else
        {
            company = "INVALID\n";
        }
    }
}

// Function that calculates the checksum
int checksum(long card_num)
{
    int sum = 0;
    total = 0;
    while (card_num > 0)
    {
        int sum_dig = card_num % 10;             // summed digit
        int dub_dig = (card_num % 100 / 10) * 2; // doubled digit
        if (dub_dig >= 10)
        {
            dub_dig = (dub_dig / 10) + (dub_dig % 10);
        }
        sum = sum_dig + dub_dig;
        total += sum;
        card_num = card_num / 100;
    }
    return total;
}
