/*
 * Name: Abdoul Ba
 * Course: CS 108
 * Assignment: Wordle Game Project
 * Date: 05/06/2025
 *
 * This file contains the main function and the game loop for the Wordle game.
 * It is responsible for initializing the game, calling functions from wordle_functions.c
 * to handle user input, manage the game state, and display the results.
 *
 * The game flow involves reading in a list of valid words, selecting a random secret word,
 * prompting the user for guesses, checking if the guesses are valid, updating the game state,
 * and displaying the results. The game continues until the user either wins or loses.
 *
 * This file works with wordle_functions.c and wordle_functions.h to implement the full
 * functionality of the Wordle game.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordle_functions.h"

// Define the filename for the word list
#define WORDS_FILENAME "words.txt" // Define WORDS_FILENAME here

/**
 [Abdoul Ba ]
 * [CS108]
 [Creating a game called Wordle, Major Project #2 - Wordle Game  ]
 * main - The entry point of the Wordle game.
 *
 * This function initializes the game, reads the word list from a file,
 * selects a secret word, and then enters the game loop where the player
 * makes guesses. The game continues until the player either guesses the
 * word correctly or exhausts the maximum number of attempts.
 *
 * Return: Always returns 0 to indicate successful execution.
 */
int main() {
    int wait;
    // Declare a 2D array to hold the list of valid words
    char words[WORDS_LIST_LEN][WORD_LENGTH + 1];

    // Declare a variable to hold the secret word
    char secret_word[WORD_LENGTH + 1];

    // Declare a variable to hold the game state
    game_state_t game_state;

    // Clear the screen (function should be defined in wordle_functions.c)
    clear_screen();

    // Get the list of words from the file
    get_word_list(words, WORDS_FILENAME);

    // Select a random secret word from the list
    get_secret_word(secret_word, WORDS_LIST_LEN, words);

    // Initialize the game state
    game_state = initialize_game_state(secret_word);

    // Main game loop - continues until the player runs out of attempts or guesses correctly
    while (game_state.guess_count < MAX_ATTEMPTS && game_state.game_status == 0) {
        // Display the current state of the game
        display_game_state(&game_state);

        // Get the player's next guess
        get_next_guess(&game_state, WORDS_LIST_LEN, words);

        // Update the game state with the new guess
        update_state(&game_state);
    }

    // Display the final state of the game
    display_game_state(&game_state);

    // Display the end game message (win or loss)
    display_end_game_message(&game_state);

    scanf("%d",&wait);

    return 0; // Return success
}
