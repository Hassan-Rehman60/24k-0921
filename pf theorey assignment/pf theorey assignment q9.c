#include <stdio.h>

#define SIZE 5

void displayGrid(char grid[SIZE][SIZE], int playerX, int playerY);
int isValidMove(int x, int y, char grid[SIZE][SIZE]);

int main() {
    char grid[SIZE][SIZE] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', 'I'},
        {' ', ' ', 'X', ' ', ' '},
        {'T', ' ', 'X', 'X', ' '},
        {' ', 'X', ' ', ' ', 'P'}
    };

    int playerX = 4, playerY = 4;
    char move;
    int itemsCollected = 0;

    while (1) {
        displayGrid(grid, playerX, playerY);
        printf("Items collected: %d\n", itemsCollected);
        printf("Enter move (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &move);

        int newX = playerX, newY = playerY;

        switch (move) {
            case 'W':
            case 'w': newX = playerX - 1; break;
            case 'S':
            case 's': newX = playerX + 1; break;
            case 'A':
            case 'a': newY = playerY - 1; break;
            case 'D':
            case 'd': newY = playerY + 1; break;
            case 'Q':
            case 'q': printf("Exiting game.\n"); return 0;
            default: printf("Invalid input. Try again.\n"); continue;
        }

        if (isValidMove(newX, newY, grid)) {
            if (grid[newX][newY] == 'I') {
                itemsCollected++;
                printf("Item collected!\n");
            }
            grid[playerX][playerY] = ' ';
            playerX = newX;
            playerY = newY;
            grid[playerX][playerY] = 'P';
        } else {
            printf("Invalid move!\n");
        }
    }

    return 0;
}

void displayGrid(char grid[SIZE][SIZE], int playerX, int playerY) {
    printf("\nGrid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int x, int y, char grid[SIZE][SIZE]) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || grid[x][y] == 'X') {
        return 0;
    }
return 1;
}