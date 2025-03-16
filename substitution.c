#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char h_upper;

int main(int argc, string argv[])
{
    // 1. NO MORE THAN 2 ARGUMENTS ALLOWED
    if (argc != 2)
    {
        printf("%s\n", "Error: Encryption takes only two arguments. No spaces permitted.");
        return 1;
    }
    // 2. MUST BE 6 CHARACTERS
    int this = strlen(argv[1]);
    if (this != 26)
    {
        printf("%s\n", "Error: The encryption needs 26 letters.");
        return 1;
    }
    for (int h = 0; h < 26; h++)
    {
        h_upper = toupper(argv[1][h]);
        // printf("%c\n", h_upper);

        for (int i = h + 1; i < 26; i++)
        {
            // MAKE ALL CAPITAL LETTERS
            char i_upper = toupper(argv[1][i]);
            char check = toupper(argv[1][i - 1]);
            //  printf("%c", i_upper);

            // NON-LETTER CHAR TERMINATES PROGRAM
            if (check < 65 || check > 90)
            {
                printf("\n%s\n", "Error: Use letters only for the encryption");
                return 1;
            }

            // LETTER IS STORE THEN CHECKS SUCCEEDING LETTERS TO ENSURE THERE ARE NO DUPLICATES
            if (h_upper == i_upper)
            {
                printf("\n%s\n", "Error: Cannot have duplicate letters in the encryption");
                return 1;
            }
        }
        // printf("%c", h_upper);
    }
    // printf("\n");

    string plaintext = get_string("Plaintext: ");
    int length = strlen(plaintext);
    printf("%s", "ciphertext: ");

    for (int j = 0; j < length; j++)
    {
        int check = plaintext[j];
        if (check >= 65 && check <= 90)
        {
            printf("%c", toupper(argv[1][check - 65]));
        }
        else if (check >= 97 && check <= 122)
        {
            printf("%c", tolower(argv[1][check - 97]));
        }
        else
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");
}
