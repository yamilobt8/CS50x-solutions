#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int count_letters(string text);

int count_words(string text);

int count_sentences(string text);

int main(void)
{
    // get an input from user the text
    string text = get_string("Text: ");

    int words = count_words(text);

    int letters = count_letters(text);

    int sentences = count_sentences(text);

    float L = (float) letters / (float) words * 100;

    float S = (float) sentences / (float) words * 100;

    int GRADE = round(0.0588 * L - 0.296 * S - 15.8);

    if (GRADE < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (GRADE >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", GRADE);
    }
}

// make function called count_letters
int count_letters(string text)
{
    // count letters and return the value
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            letters++;
        }
        else
        {
            letters += 0;
        }
    }
    return letters;
}

// make function called count_words
int count_words(string text)
{
    // count words and return the value
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
        else
        {
            words += 0;
        }
    }
    return words;
}

// make function called count_sentences
int count_sentences(string text)
{
    // count sentences and return the value
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            sentences++;
        }
        else
        {
            sentences += 0;
        }
    }
    return sentences;
}