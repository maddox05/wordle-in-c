# Wordle in C Project

This is a markdown document that describes the **Wordle in C** project, a word guessing game implemented in C. The game challenges players to guess a randomly chosen word within a limited number of attempts.
<br><img src = "https://s11.gifyu.com/images/SgWUc.gif">

## Project Overview

The **Wordle in C** project is an implementation of the classic word guessing game where players attempt to guess a secret word within a limited number of guesses. The project is written in C and utilizes various libraries and user-defined functions to achieve its functionality.

## Libraries Used

The following libraries are included in the project:

- `cs50.h`: Provides functions for user input and output.
- `stdio.h`: Standard I/O library for input and output operations.
- `stdlib.h`: Standard library for general functions, including memory allocation.
- `string.h`: String manipulation functions.
- `time.h`: Provides functions for time-related operations.

## Constants and Definitions

The project includes several constants and definitions that are crucial for its functionality:

- `LISTSIZE`: Defines the number of words in each text file.
- `EXACT`, `CLOSE`, and `WRONG`: Define values for different guess outcomes.
- ANSI color codes: Defines color codes for styling text output.

## User-Defined Functions

The project utilizes several user-defined functions to manage the game logic:

- `get_guess(int wordsize)`: Obtains a user's guess and ensures it matches the required length.
- `check_word(string guess, int wordsize, int status[], string choice)`: Compares the user's guess to the secret word and calculates the score.
- `print_word(string guess, int wordsize, int status[])`: Prints the user's guess with colored styling based on the guess status.

## Main Function

The `main` function is the heart of the game and contains the following key components:

1. Command-line Argument Validation: Ensures the correct number of command-line arguments and validates the input word size.
2. Wordlist Loading: Opens the appropriate wordlist file and loads its contents into an array.
3. Random Word Selection: Randomly selects a word from the loaded wordlist.
4. Game Loop: Iterates through the game loop, allowing the player to make guesses.
5. Guess Processing: Obtains the player's guess, calculates the score, and displays the guess status.
6. Game Outcome: Determines whether the player has won or lost and reveals the secret word.

## Running the Game

To play the **Wordle in C** game, compile the C code and provide a word size as a command-line argument (5, 6, 7, or 8). For example:

```bash
gcc -o wordle50 wordle50.c -lcs50
./wordle50 6
```
