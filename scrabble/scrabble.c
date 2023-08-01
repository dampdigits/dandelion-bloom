/*  Scrabble evaluates points two words entered by 2 players.
    The number of points is the sum of the point values of each letter in the word.
    The player with more points wins.
*/
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int length = strlen(word), score = 0;
    
    for (int i = 0; i < length; i++)
    {
        char character = word[i];
        if (isalpha(character))
        {
            character = toupper(character);
            int asciival = (int) character;
            score += POINTS[asciival - 65];
        }
    }
    return score;
}
