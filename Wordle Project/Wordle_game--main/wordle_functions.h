// Name: Abdoul Ba 
// Course: CS 108
// Assignment: Wordle Game 
// 05/06/2025
// Description: This program implements a terminal-based version of the popular Wordle game in C.
// * It reads a list of valid five-letter words from a file, randomly selects one as the secret word,
//* and allows the user up to six attempts to guess it. The game provides feedback after each guess
//* using a system of colored indicators (represented by numeric codes) to show correct letters in the correct position,
//* letters present but in the wrong position, and incorrect letters.

#ifndef WORDLE_FUNCTIONS_H
#define WORDLE_FUNCTIONS_H

#define WORDS_LIST_LEN 3103
#define WORD_LENGTH 5 /* Standard WORDLE word length */
#define MAX_ATTEMPTS 6

#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define QWERTY_TOP "QWERTYUIOP"
#define QWERTY_MID "ASDFGHJKL"
#define QWERTY_BOT "ZXCVBNM"

#define BOLD "\033[1m"
#define RESET "\033[0m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"

#define WORDS_FILENAME "words.txt"

typedef struct {
    char secret_word[WORD_LENGTH + 1];
    char current_guess[WORD_LENGTH + 1];
    char guesses[MAX_ATTEMPTS][WORD_LENGTH + 1];
    int guess_statuses[MAX_ATTEMPTS][WORD_LENGTH];
    int alphabet_state[26];
    int guess_count;
    int game_status;
} game_state_t;

/*
 * Reads the word list from a file into the provided array.
 * Pre: 'words' is a 2D array with space for WORDS_LIST_LEN words of length WORD_LENGTH + 1.
 *      'filename' is a valid string containing the file path.
 * Post: The array 'words' is populated with words from the file.
 */
void get_word_list(char words[][WORD_LENGTH + 1], const char *filename);

/*
 * Chooses a secret word randomly from the word list.
 * Pre: 'secret_word' is a character array with space for WORD_LENGTH + 1 characters.
 *      'list_length' is the number of words in the list.
 *      'word_list' is an array of valid words.
 * Post: 'secret_word' is assigned a word from 'word_list'.
 */
void get_secret_word(char *secret_word, int list_length, char word_list[][WORD_LENGTH + 1]);

/*
 * Initializes and returns a game_state_t structure with the given secret word.
 * Pre: 'secret_word' is a null-terminated string of length WORD_LENGTH.
 * Post: Returns a fully initialized game_state_t structure.
 */
game_state_t initialize_game_state(char secret_word[]);

/*
 * Returns the index of the target character in the given string.
 * Pre: 'string' is a null-terminated string.
 *      'target' is the character to find.
 * Post: Returns the index of 'target' in 'string', or -1 if not found.
 */
int get_index_in_string(char string[], char target);

/*
 * Returns the index of a word in the word list.
 * Pre: 'word' is a valid string.
 *      'list_length' is the number of words in the list.
 *      'word_list' is an array of valid words.
 * Post: Returns the index of 'word' in 'word_list', or -1 if not found.
 */
int get_index_in_word_list(char word[], int list_length, char word_list[][WORD_LENGTH + 1]);

/*
 * Prompts the player for their next guess and stores it in the game state.
 * Pre: 'game_state' is a pointer to a valid game_state_t.
 *      'list_length' and 'word_list' represent the list of valid words.
 * Post: A valid guess is added to the game state.
 */
void get_next_guess(game_state_t *game_state, int list_length, char word_list[][WORD_LENGTH + 1]);

/*
 * Updates the game state after a guess, including incrementing guess count and checking win/loss status.
 * Pre: 'game_state' is a pointer to a valid game_state_t.
 * Post: The game state reflects the new guess and updated status.
 */
void update_state(game_state_t *game_state);

/*
 * Calculates the status (green/yellow/gray) of each letter in the current guess.
 * Pre: 'game_state' is a pointer to a valid game_state_t.
 *      'guess_index' is a valid index for a guess.
 * Post: 'guess_statuses' for the specified guess is updated.
 */
void calculate_guess_status(game_state_t *game_state, int guess_index);

/*
 * Clears the console screen.
 * Pre: None.
 * Post: The console screen is cleared.
 */
void clear_screen();

/*
 * Displays the current game state including guesses and keyboard.
 * Pre: game_state is a pointer to a valid game_state_t structure.
 * Post: The game board and keyboard are displayed on the screen.
 */
void display_game_state(game_state_t *game_state);

/*
 * Displays the formatted guess with color coding based on guess statuses.
 * Pre: string is a null-terminated string representing a guess.
 *      game_state is a pointer to a valid game_state_t structure.
 *      guess_index is the index of the guess in game_state.
 * Post: The formatted guess is printed to the screen.
 */
void pretty_print(char string[], game_state_t *game_state, int guess_index);

/*
 * Displays the keyboard line with color coding based on letter statuses.
 * Pre: qwerty is a null-terminated string representing a keyboard row.
 *      game_state is a pointer to a valid game_state_t structure.
 * Post: The formatted keyboard row is printed to the screen.
 */
void qwerty_pretty_print(char qwerty[], game_state_t *game_state);

/*
 * Displays the end game message based on the game outcome.
 * Pre: game_state is a pointer to a valid game_state_t structure.
 * Post: The appropriate end game message is displayed.
 */
void display_end_game_message(game_state_t *game_state);

#endif // WORDLE_FUNCTIONS_H
