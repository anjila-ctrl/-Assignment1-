#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Toss Function
char toss() {
    char userChoice, machineChoice;
    printf("Toss Time: Choose 'b' for bat or 'w' for bowl: ");
    scanf(" %c", &userChoice);

    srand(time(0));
    int tossResult = rand() % 2;
    if (tossResult == 0) {
        machineChoice = 'b';
    } else {
        machineChoice = 'w';
    }

    if (userChoice == machineChoice) {
        printf("You won the toss! You chose to %s first.\n", userChoice == 'b' ? "bat" : "bowl");
        return userChoice;
    } else {
        printf("You lost the toss. Machine chose to %s first.\n", machineChoice == 'b' ? "bat" : "bowl");
        return machineChoice;
    }
}

// Play a Turn (Batting Logic)
int playTurn(char player) {
    int totalRuns = 0, guess, machineRun;
    while (1) {
        printf("Guess the machine's run (1-6): ");
        scanf("%d", &guess);

        machineRun = (rand() % 6) + 1; // Generate random runs between 1 and 6
        printf("Machine chose: %d\n", machineRun);

        if (guess == machineRun) {
            printf("OUT! You guessed correctly.\n");
            break;
        } else {
            totalRuns += machineRun;
            printf("Runs scored: %d | Total runs: %d\n", machineRun, totalRuns);
        }
    }
    return totalRuns;
}

int main() {
    srand(time(0)); // Initialize random seed

    printf("Welcome to AMUST Cricket!\n");
    char turn = toss();
    int userScore, machineScore;

    // First Innings
    if (turn == 'b') {
        printf("\nYou will bat first.\n");
        userScore = playTurn('u');
        printf("Your total score: %d\n", userScore);

        printf("\nMachine's turn to chase:\n");
        machineScore = playTurn('m');
    } else {
        printf("\nMachine will bat first.\n");
        machineScore = playTurn('m');
        printf("Machine's total score: %d\n", machineScore);

        printf("\nYour turn to chase:\n");
        userScore = playTurn('u');
    }

    // Final Result
    printf("\n--- Final Result ---\n");
    if (userScore > machineScore) {
        printf("Congratulations! You won the match!\n");
    } else if (userScore < machineScore) {
        printf("Machine won the match. Better luck next time!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}
