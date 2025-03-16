#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_sentences(string text);
int count_words(string text);

int main(void)
{
    string prompt = get_string("Text: ");

    count_letters(prompt);
    count_sentences(prompt);
    count_words(prompt);

    float L = (float) count_letters(prompt) / (float) count_words(prompt) * 100;
    float S = (float) count_sentences(prompt) / (float) count_words(prompt) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int rounded_index = round(index);

    if (rounded_index > 0 && rounded_index < 16)
    {
        printf("%s%i\n", "Grade ", rounded_index);
    }
    else if (rounded_index < 1)
    {
        printf("%s", "Before Grade 1\n");
    }
    else
    {
        printf("%s", "Grade 16+\n");
    }
}

int count_letters(string text)
{
    int l_count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            l_count++;
        }
    }
    return l_count;
}

int count_sentences(string text)
{
    int s_count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            s_count++;
        }
    }
    return s_count;
}

int count_words(string text)
{
    int w_count = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            w_count++;
        }
    }
    return w_count;
}
