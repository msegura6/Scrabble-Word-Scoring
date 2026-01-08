#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Prototypes
int calculate_score(string word, int arr[26][2]);
void uppercase(string word);

// Scores for each letter
int points[26][2] = {{'A', 1}, {'B', 3}, {'C', 3},  {'D', 2}, {'E', 1}, {'F', 4}, {'G', 2},
                     {'H', 5}, {'I', 1}, {'J', 8},  {'K', 5}, {'L', 1}, {'M', 3}, {'N', 1},
                     {'O', 1}, {'P', 4}, {'Q', 10}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1},
                     {'V', 4}, {'W', 4}, {'X', 8},  {'Y', 4}, {'Z', 10}};

int main(void)
{

    // Get Player 1's word
    string word1 = get_string("Player 1's word: ");

    // Get Player 2's word
    string word2 = get_string("Player 2's word: ");

    // Change words to uppercase
    uppercase(word1);
    uppercase(word2);

    // Calculate scores for each word
    int score1 = calculate_score(word1, points);
    int score2 = calculate_score(word2, points);

    // Find winner by comparing scores
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}

int calculate_score(string word, int arr[26][2])
{
    int score = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isalpha(word[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (word[i] == points[j][0])
                {
                    score += points[j][1];
                }
            }
        }
    }
    return score;
}

void uppercase(string word)
{
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        word[i] = toupper(word[i]);
    }
}
