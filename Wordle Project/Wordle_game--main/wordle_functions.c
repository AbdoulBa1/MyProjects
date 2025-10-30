/*
 * Name: Abdoul Ba 
 * Course: CS 108
 * Assignment: Wordle Game Implementation
 * Date: Date
 *  This file contains the implementation of functions for the Wordle game.
 * The functions include logic for managing the game state, handling user input, processing guesses, 
 * selecting a secret word, updating the game board, and calculating guess statuses (correct, present, absent).
 * Additionally, this file includes functions for displaying the game state, updating the alphabet status, 
 * and printing the formatted output for each guess.
 * 
 * The functions in this file work in conjunction with other files like wordle.c and wordle_functions.h 
 * to implement the overall functionality of the Wordle game.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "wordle_functions.h"

void get_word_list(char words[][WORD_LENGTH + 1], const char *filename) {
FILE *file = fopen(filename, "r");
if (file == NULL) {
printf("Error: Could not open file %s\n", filename);
return;
}

int index = 0;
while (fscanf(file, "%5s", words[index]) == 1) {
index++;
}

fclose(file);
}

void get_secret_word(char *secret_word, int list_length, char word_list[][WORD_LENGTH + 1]) {
srand(time(NULL));
int index = rand() % list_length;
strcpy(secret_word, word_list[index]);
}

game_state_t initialize_game_state(char secret_word[]) {
game_state_t game_state;
//LOOK AT THIS AND CHANGE CAUSE IT DIDNT PASS THE AUTO GRADER 
for (int i = 0; i < MAX_ATTEMPTS; i++) {
    for (int j = 0; j < WORD_LENGTH; j++) {
        game_state.guesses[i][j] = '-';
    }
    game_state.guesses[i][WORD_LENGTH] = '\0';  // Null-terminate the string
}


for (int i = 0; i < MAX_ATTEMPTS; i++) {
for (int j = 0; j < WORD_LENGTH; j++) {
game_state.guess_statuses[i][j] = -1;
}
}

strcpy(game_state.secret_word, secret_word);
game_state.guess_count = 0;
game_state.game_status = 0;

for (int i = 0; i < 26; i++) {
game_state.alphabet_state[i] = -1;
}

return game_state;
}

int get_index_in_string(char string[], char target) {
for (int i = 0; string[i] != '\0'; i++) {
if (string[i] == target) {
return i;
}
}
return -1;
}

int get_index_in_word_list(char word[], int list_length, char word_list[][WORD_LENGTH + 1]) {
for (int i = 0; i < list_length; i++) {
if (strcmp(word, word_list[i]) == 0) {
return i;
}
}
return -1;
}

void get_next_guess(game_state_t *game_state, int list_length, char word_list[][WORD_LENGTH + 1]) {
char temp_guess[WORD_LENGTH + 10];

while (1) {
printf("Enter a guess: ");
scanf("%s", temp_guess);

if (strlen(temp_guess) != WORD_LENGTH) {
printf("Invalid guess. Guess must be exactly 5 letters.\n");
continue;
}

for (int i = 0; i < WORD_LENGTH; i++) {
game_state->current_guess[i] = toupper(temp_guess[i]);
}
game_state->current_guess[WORD_LENGTH] = '\0';

if (get_index_in_word_list(game_state->current_guess, list_length, word_list) != -1) {
break;
} else {
printf("Invalid guess. Word not in list.\n");
}
}
}

void update_state(game_state_t *game_state) {
strcpy(game_state->guesses[game_state->guess_count], game_state->current_guess);

calculate_guess_status(game_state, game_state->guess_count);

if (strcmp(game_state->current_guess, game_state->secret_word) == 0) {
game_state->game_status = 2;
}

game_state->guess_count++;

if (game_state->guess_count == MAX_ATTEMPTS && game_state->game_status != 2) {
game_state->game_status = 1;
}
}

void calculate_guess_status(game_state_t *game_state, int guess_index) {
int secret_letter_counts[26] = {0};
int guess_status[WORD_LENGTH] = {0};

for (int i = 0; i < WORD_LENGTH; i++) {
int idx = get_index_in_string(ALPHABET, game_state->secret_word[i]);
if (idx != -1) {
secret_letter_counts[idx]++;
}
}

for (int i = 0; i < WORD_LENGTH; i++) {
char guess_char = game_state->guesses[guess_index][i];
if (guess_char == game_state->secret_word[i]) {
guess_status[i] = 2;
int idx = get_index_in_string(ALPHABET, guess_char);
if (idx != -1) {
secret_letter_counts[idx]--;
}
}
}

for (int i = 0; i < WORD_LENGTH; i++) {
if (guess_status[i] == 2) continue;

char guess_char = game_state->guesses[guess_index][i];
int idx = get_index_in_string(ALPHABET, guess_char);

if (idx != -1 && secret_letter_counts[idx] > 0) {
guess_status[i] = 1;
secret_letter_counts[idx]--;
} else {
guess_status[i] = 0;
}
}

for (int i = 0; i < WORD_LENGTH; i++) {
game_state->guess_statuses[guess_index][i] = guess_status[i];
}

for (int i = 0; i < WORD_LENGTH; i++) {
int idx = get_index_in_string(ALPHABET, game_state->guesses[guess_index][i]);
if (idx != -1 && guess_status[i] > game_state->alphabet_state[idx]) {
game_state->alphabet_state[idx] = guess_status[i];
}
}
}
/*
* Don't edit any of the functions below!
*/

void clear_screen() {
system("cls");
}

void display_game_state(game_state_t *game_state) {
clear_screen();
printf("%s", BOLD);
printf(" W O R D L E \n");
printf("%s", RESET);
for (int i = 0; i < MAX_ATTEMPTS; i++) {
pretty_print(game_state->guesses[i], game_state, i);
}
printf("\n%s Letters %s\n",BOLD,RESET);
qwerty_pretty_print(QWERTY_TOP, game_state);
printf(" ");
qwerty_pretty_print(QWERTY_MID, game_state);
printf(" ");
qwerty_pretty_print(QWERTY_BOT, game_state);
printf("\n");
}

void pretty_print(char string[], game_state_t *game_state, int guess_index) {
char cur_char;
int cur_char_status = 0;

printf(" ");
for (int i = 0; i < WORD_LENGTH; i++) {
cur_char = string[i];
cur_char_status = game_state->guess_statuses[guess_index][i];

if (cur_char_status == 0) {
printf(" %c ", cur_char);
} else if (cur_char_status == 1) {
printf("%s %c %s", YELLOW, cur_char, RESET);
} else if (cur_char_status == 2) {
printf("%s %c %s", GREEN, cur_char, RESET);
} else {
printf(" %c ", cur_char);
}
}
printf("\n");
}

void qwerty_pretty_print(char qwerty[], game_state_t *game_state) {
int i_in_alpha;

for (int j = 0; j < strlen(qwerty); j++) {
i_in_alpha = get_index_in_string(ALPHABET, qwerty[j]);

if (i_in_alpha != -1) {
if (game_state->alphabet_state[i_in_alpha] == 0) {
printf("%s %c%s", RED, qwerty[j], RESET);
} else if (game_state->alphabet_state[i_in_alpha] == 1) {
printf("%s %c%s", YELLOW, qwerty[j], RESET);
} else if (game_state->alphabet_state[i_in_alpha] == 2) {
printf("%s %c%s", GREEN, qwerty[j], RESET);
} else {
printf(" %c", qwerty[j]);
}
}
}
printf("\n");
}

void display_end_game_message(game_state_t *game_state) {
if (game_state->game_status == 1) {
printf("Better luck next time.\n");
printf("The word was: %s%s%s \n", BOLD, game_state->secret_word, RESET);
} else if (game_state->game_status == 2) {
printf("You got it!\n");
printf("Total Guesses: %s%d%s\n", BOLD, game_state->guess_count, RESET);
}
}

