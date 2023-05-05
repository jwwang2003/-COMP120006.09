#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char name[3][10] = {
    "Rock",
    "Paper",
    "Scissor"
};

int main(void) {
    time_t t;
    srand((unsigned) time(&t));

    printf("Welcome to Rock Paper Scissor!\n");
    printf("How to play:\n");
    printf("To pick rock, paper, or scissor, enter 1, 2, or 3 respectively\n");
    
    int compScore = 0;
    int userScore = 0;

    while(compScore < 3 && userScore < 3) {
        printf("Enter your choice: ");

        int userChoice;
        scanf("%d", &userChoice);
        --userChoice;
        printf("You picked: %s\n", name[userChoice]);

        int compChoice = rand() % 3;
        printf("Computer RNG choose: %s\n", name[compChoice]);

        if (userChoice == 0 && compChoice == 1) {
            compScore++;
            printf("You lose! Paper wraps rock.\n");
        }
        else if (userChoice == 1 && compChoice == 2) {
            compScore++;
            printf("You lose! Scissors cut paper.\n");
        }
        else if (userChoice == 2 && compChoice == 0) {
            compScore++;
            printf("You lose! Rock smashes scissor.\n");
        }
        else if (userChoice == 0 && compChoice == 2) {
            userScore++;
            printf("You Win! Rock smashes scissor.\n");
        }
        else if (userChoice == 1 && compChoice == 0) {
            userScore++;
            printf("You Win! Paper wraps rock.\n");
            
        }
        else if (userChoice == 2 && compChoice == 1) {
            userScore++;
            printf("You Win! Scissors cut paper.\n");
        }
        else{
            printf("It's a tie!\n");
        }

        printf("\nCurrent score:\n");
        printf("User\tComputer\n");
        printf("%d\t%d\n\n", userScore, compScore);
    }

    if(compScore == 3) {
        printf("Computer wins! Unfortunately RNG was not on your side :(\n");
        printf("Better luck next time!\n");
    } else if(userScore == 3) {
        printf("You won! The computer's RNG could not beat you, yet\n");
    }

    return 0;
}