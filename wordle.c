#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// each of our text files contains 1000 words
#define LISTSIZE 1000

// values for colors and score (EXACT == right letter, right place; CLOSE == right letter, wrong place; WRONG == wrong letter)
#define EXACT 2
#define CLOSE 1
#define WRONG 0

// ANSI color codes for boxed in letters
#define GREEN "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET "\e[0;39m"

// user-defined function prototypes
string get_guess(int wordsize);
int check_word(string guess, int wordsize, int status[], string choice);
void print_word(string guess, int wordsize, int status[]);

int main(int argc, string argv[])
{
    // ensure proper usage
    // TODO #1
    if (argc != 2)
    {
        printf("err1\n");
        return 1;
        exit(1);
    }
    int wordsize = 0;
    if (argv[1][0] - 48 == 5 || argv[1][0] - 48 == 6 || argv[1][0] - 48 == 7 || argv[1][0] - 48 == 8)
    {
        wordsize = argv[1][0] - 48;
    }
    else
    {
        printf("err2\n");

        exit(1);
    }

    // ensure argv[1] is either 5, 6, 7, or 8 and store that value in wordsize instead
    // TODO #2

    // open correct file, each file has exactly LISTSIZE words
    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    // load word file into an array of size LISTSIZE
    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }

    // pseudorandomly select a word for this game
    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];

    // allow one more guess than the length of the word
    int guesses = wordsize + 1;
    bool won = false;

    // print greeting, using ANSI color codes to demonstrate
    printf(GREEN "This is WORDLE50" RESET "\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    // main game loop, one iteration for each guess
    for (int i = 0; i < guesses; i++)
    {
        // obtain user's guess
        string guess = get_guess(wordsize);

        // array to hold guess status, initially set to zero
        int status[wordsize];

        for (int j = 0; j < sizeof(status); j++)
        {
            status[j] = 0;
        }
        // set all elements of status array initially to 0, aka WRONG
        // TODO #4 DONE!

        // Calculate score for the guess
        int score = check_word(guess, wordsize, status, choice);

        printf("Guess %i: ", i + 1);

        // Print the guess
        print_word(guess, wordsize, status);

        // if they guessed it exactly right, set terminate loop
        if (score == EXACT * wordsize)
        {
            won = true;
            break;
        }
    }

    printf("Word was: %s", choice);
    return 0;
}

string get_guess(int wordsize)
{
    string guess = "";
    do
    {
        guess = get_string("Input a %i-letter word: ", wordsize);
    }
    while (strlen(guess) != wordsize);

    // ensure users actually provide a guess that is the correct length
    // TODO #3

    return guess;
}

int check_word(string guess, int wordsize, int status[], string choice) // choice is random from .txt file
{
    int score = 0;

    for (int i = 0; i < wordsize; i++)
    {
        if (guess[i] == choice[i])
        {
            status[i] = EXACT;
            score = score + status[i];
            printf("Exact Match ");
        }
        else
        {
            for (int j = 0; j < wordsize; j++)
            {
                if (guess[i] == choice[j])
                {
                    status[i] = CLOSE;
                    score = score + status[i];
                    printf("CLOSE Match ");
                }
                else if (j == (wordsize - 1) && guess[i] != choice[j])
                { // prob cause errs
                    status[i] = WRONG;
                    score = score + status[i];
                    printf("WRONG MATCH ");
                }
            }
        }
        printf("SCORE IS NOW %i ", score);
    }
    return score;
    // compare guess to choice and score points as appropriate, storing points in status
    // TODO #5

    // iterate over each letter of the guess
    // iterate over each letter of the choice
    // compare the current guess letter to the current choice letter
    // if they're the same position in the word, score EXACT points (green) and break so you don't compare that letter further
    // if it's in the word, but not the right spot, score CLOSE point (yellow)
    // keep track of the total score by adding each individual letter's score from above
}

void print_word(string guess, int wordsize, int status[])
{
    for (int i = 0; i < wordsize; i++)
    {
        if (status[i] == EXACT)
        {
            printf(GREEN "%c" RESET, guess[i]);
        }
        else if (status[i] == CLOSE)
        {
            printf(YELLOW "%c" RESET, guess[i]);
        }
        else
        {
            printf(RED "%c" RESET, guess[i]);
        }
    }

    // print word character-for-character with correct color coding, then reset terminal font to normal
    // TODO #6

    printf("\n");
    return;
}
