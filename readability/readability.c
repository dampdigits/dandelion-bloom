/*  Readability calculates the approximate grade level needed to comprehend some text.
    It uses the Coleman-Liau index reading test.
*/
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float findindex(void);
void analyzetext(void);
void display(int index);

string text;
float letters = 0, words = 0, sentences = 0;

int main(void)
{
    // Input text
    text = get_string("Text: ");

    // Count number of letters, words and sentences in text
    analyzetext();

    // Calculate Coleman-Liau index
    int index = round(findindex());

    // Display Grade
    display(index);
}

// Count the number of letters, words and sentences
void analyzetext(void)
{
    // Find length of text
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        char ch = text[i];
        // If character is a letter, one letter is counted
        if (isalpha(ch))
        {
            letters++;
        }
        // If character is a whitespace, one word is counted
        if (ch == '\t' || ch == ' ')
        {
            words++;
        }
        // If character is a terminating punctuation, one sentence is counted
        if (ch == '.' || ch == '?' || ch == '!')
        {
            sentences++;
            // If there is no character after punctuation, the last word is counted
            if ((i + 1) == length)
            {
                words++;
            }
        }
    }
}

float findindex(void)
{
    // Average number of letters per 100 words
    float L = (letters / words) * 100;
    // Average number of sentences per 100 words
    float S = (sentences / words) * 100;
    // Coleman-Liau index
    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    return index;
}

// Prints the grade
void display(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}
