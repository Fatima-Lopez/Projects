#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calc_level(int letters, int words, int sentences);

int main(void)
{
    // ask the user for a text
    string text = get_string("Text: ");

    // count the letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // calculate the grade level
    int level = calc_level(letters, words, sentences);

    // output the reading level
    if (level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", level);
    }
}

int count_letters(string text)
{
    // save the number of letters
    int letters = 0;

    // count the number of letters in the text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

int count_words(string text)
{
    // save the number of words
    int words = 0;

    // count the number of words
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

    return words + 1;
}

int count_sentences(string text)
{
    // save the number of sentences
    int sentences = 0;

    // count the number of sentences
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}

int calc_level(int letters, int words, int sentences)
{
    // calculate the average number of letters and words
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;

    // calculate the grade level
    float index = 0.0588 * L - 0.296 * S - 15.8;

    return (int) round(index);
}
