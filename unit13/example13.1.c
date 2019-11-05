#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUMBER 666

void initialize_number_generator();
void choose_new_secret_number();
void readGuesses(int secret_number);
int secret_number;
int main()
{
    char command;
    printf("Guess the secret number between 1 and %d.\n\n", MAX_NUMBER);
    initialize_number_generator();
    do {
        choose_new_secret_number();
        printf("A new number has been chosen.\n");
        readGuesses(secret_number);
        printf("Play again? Y/N\n");
        scanf("%s", &command);
    } while(command == 'y' || command == 'Y');
    return 0;
}

void initialize_number_generator() {
    srand((unsigned) time(NULL));
}

void choose_new_secret_number() {
    secret_number = rand() % MAX_NUMBER + 1;
}

void readGuesses(int secret_number) {
    int guess, num_guesses = 0;
    while(getchar() != '#') {
        num_guesses++;
        printf("enter guess:");
        scanf("%d", &guess);
        if(guess == secret_number) {
            printf("you won in %d guesses!\n\n", num_guesses);
            return;
        }
        else if (guess < secret_number) {
            printf("too low, try again!\n");
        }
        else printf("too high, try again!\n");
    }
}