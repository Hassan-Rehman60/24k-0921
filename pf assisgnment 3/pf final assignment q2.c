#include <stdio.h>

struct CricketPlayer {
    char name[100];
    int ballScores[12];
    int totalScore;
} playerA, playerB;

int recordScore(struct CricketPlayer player);
int isScoreValid(int score);
int determineWinner(struct CricketPlayer playerA, struct CricketPlayer playerB);
void displayScoreboard(struct CricketPlayer playerA, struct CricketPlayer playerB);

int main() {
    playerA.totalScore = 0;
    playerB.totalScore = 0;

    printf("Enter the name of Player 1: ");
    scanf("%s", playerA.name);
    printf("Enter the name of Player 2: ");
    scanf("%s", playerB.name);

    for (int ball = 0; ball < 12; ball++) {
        printf("\nEnter score of %s for ball %d: ", playerA.name, ball + 1);
        playerA.ballScores[ball] = recordScore(playerA);
        playerA.totalScore += playerA.ballScores[ball];

        printf("Enter score of %s for ball %d: ", playerB.name, ball + 1);
        playerB.ballScores[ball] = recordScore(playerB);
        playerB.totalScore += playerB.ballScores[ball];
    }

    int result = determineWinner(playerA, playerB);
    if (result == 1) {
        printf("\n%s won against %s\n", playerA.name, playerB.name);
    } else if (result == 0) {
        printf("\n%s won against %s\n", playerB.name, playerA.name);
    } else {
        printf("\nThe match is a draw\n");
    }

    displayScoreboard(playerA, playerB);
    return 0;
}

int recordScore(struct CricketPlayer player) {
    int score;
    scanf("%d", &score);
    if (isScoreValid(score)) {
        return score;
    }
    return 0;
}

int isScoreValid(int score) {
    return (score >= 0 && score <= 6);
}

int determineWinner(struct CricketPlayer playerA, struct CricketPlayer playerB) {
    if (playerA.totalScore > playerB.totalScore) {
        return 1;
    } else if (playerA.totalScore == playerB.totalScore) {
        return -1;
    }
    return 0;
}

void displayScoreboard(struct CricketPlayer playerA, struct CricketPlayer playerB) {
    printf("\nPerformance of %s in the match:\n", playerA.name);
    for (int ball = 0; ball < 12; ball++) {
        printf("Ball %d = %d\n", ball + 1, playerA.ballScores[ball]);
    }
    printf("\nAverage score: %d\n", playerA.totalScore / 12);
    printf("Total score: %d\n", playerA.totalScore);

    printf("\n========================================\n");

    printf("\nPerformance of %s in the match:\n", playerB.name);
    for (int ball = 0; ball < 12; ball++) {
        printf("Ball %d = %d\n", ball + 1, playerB.ballScores[ball]);
    }
    printf("\nAverage score: %d\n", playerB.totalScore / 12);
    printf("Total score: %d\n", playerB.totalScore);
}
