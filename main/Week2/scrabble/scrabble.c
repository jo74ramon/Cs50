#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet 0-25
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    int winner = 2;
    if (score1 > score2)
    {
        winner = 1;
        printf("Player %i wins!\n", winner);
    }
    else if (score1 < score2)
    {
        printf("Player %i wins!\n", winner);
    }


    else
    {
        printf("Tie!\n");

    }

printf("%d\n%d\n", score1, score2);

    // TODO: Print the winner

}

int compute_score(string word)
{
    // there is also a substracting 'A' method that reduces complexity and does not require a nested loop
    int totalPoints = 0;
    for (int j = 0; j < strlen(word); j++)
    {
        if (isalpha(word[j]))
        {
            char letter = tolower(word[j]);
            for (int i = 0; i < 26; i++)
            {
                if (letter == alphabet[i])
                {
                    totalPoints += POINTS[i];
                    break;

                }

            }

        }

    }

    // TODO: Compute and return score for string


    return totalPoints;
}
