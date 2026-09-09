/*
EECS 348 Assignment 1

C program that picks a secret number between 1 and 10. The user gets up to 3 tries to guess the number. 
The user gets up to 3 tries to guess the number.

Inputs: User's guesses, entered via stdin (scanf) during program execution - up to 3 integer guesses.
Outputs: Terminal prompts/feedback for each guess, and a final win/lose message printed to stdout.

All collaborators: Gemini (Google), ChatGPT (OpenAI)

Author’s full name: Josselyn T. Bui
Creation date: 9/8/2026
Revision date: 9/8/2026
Revisions: Improved from Gemini's base version by adding scanf return, value validation to guard against non-numeric input,
matched output text exactly to the assignment's example, output format, and added full prologue/line comments.
*/

#include <stdio.h>

int main() {
    // adapted from Gemini's variable structure but fixed secret number and game state variables authored by: Josselyn T. Bui
    const int secret_number = 7;   // the number the user must guess
    int guess;                     // stores the user's current guess
    int guessed_correctly = 0;     // flag: 1 if user wins, 0 if not (Gemini's approach - safer than re-checking the loop variable after the loop ends)
    int scan_result;               // holds scanf's return value, used to validate input

    // introductory prompt shown once before guessing begins
    printf("Guess a number between 1 and 10.\n");

    /* structure from Gemini, input validation added by Josselyn
    runs at most 3 times; exits early via 'break' on a correct guess.
     */
    for (int attempt = 1; attempt <= 3; attempt++) {
        // prompt formatted to match the assignment's exact example output
        printf("Attempt %d/3. Enter your guess: ", attempt);

        // read the guess; scanf returns the number of values successfully read
        scan_result = scanf("%d", &guess);

        /* authored by Josselyn 
        if scanf failed to read an integer (like if user typed a letter, etc.),
        clear the bad input from the buffer and skip to the next attempt
        instead of crashing or looping forever on garbage input. */ 

        if (scan_result != 1) {
            printf("Invalid input - please enter a whole number.\n");
            while (getchar() != '\n');  // discard the rest of the bad input line
            continue;                   // does not count this as a used-up attempt
        }

        // check the guess against the secret number
        if (guess == secret_number) {
            printf("Correct! You win!\n");
            guessed_correctly = 1;  // mark the win
            break;                  // stop the loop immediately, as required
        } else if (guess < secret_number) {
            printf("Too low! Try again.\n"); // give feedback for a low guess
        } else {
            printf("Too high! Try again.\n"); // give feedback for a high guess
        }
    }

    /* adapted from Gemini's flag-based approach, authored by Josselyn
    if the user did not guess correctly after 3 attempts, print the losing message
     */
    if (!guessed_correctly) {
        printf("Sorry, you lose! The secret number was %d.\n", secret_number);
    }

    return 0;
}
