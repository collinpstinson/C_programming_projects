#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_grid(int size);

int main(void)
{
    // get size of grid
    int n = get_size();

    // print bricks
    print_grid(n);
}

int get_size(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1 || n > 8); // n <= 1
    return n;
}

void print_grid(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size - 1; j++) // prints the spaces
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++) // prints leftside bricks
        {
            printf("#");
        }
        printf("  "); // prints rightside bricks
        for (int x = 0; x <= i; x++)
        {
            printf("#");
        }
        printf("\n");
    }
}
