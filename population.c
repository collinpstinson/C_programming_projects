#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int current = 0;
    int year = 0;
    if (start == end)
    {
        year = 0;
    }
    else
    {
        while (end > current)
        {
            current = start + start / 3 - start / 4;
            int diff = end - current;
            start = current;
            year++;
        }
    }
    // TODO: Print number of years
    printf("Years: %i\n", year);
}
