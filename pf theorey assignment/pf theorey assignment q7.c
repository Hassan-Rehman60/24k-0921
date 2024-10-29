#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 6
#define COLS 5

void generateRandomArray(char arr[ROWS][COLS]) {
    srand(time(0));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = 'A' + rand() % 26;
        }
    }
}

void printArray(char arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int searchStringInArray(char arr[ROWS][COLS], char *str) {
    int len = strlen(str);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            
            if (j + len <= COLS) {
                int k;
                for (k = 0; k < len; k++) {
                    if (arr[i][j + k] != str[k]) break;
                }
                if (k == len) return 1; 
            }
            
            if (i + len <= ROWS) {
                int k;
                for (k = 0; k < len; k++) {
                    if (arr[i + k][j] != str[k]) break;
                }
                if (k == len) return 1; 
            }
        }
    }
    return 0; 
}

int main() {
    char arr[ROWS][COLS];
    char str[50];
    int score = 0;

    generateRandomArray(arr);

    while (1) {
        printArray(arr);

        printf("Enter search string (type 'END' to stop): ");
        scanf("%s", str);

        if (strcmp(str, "END") == 0) {
            break;
        }

        if (searchStringInArray(arr, str)) {
            score++;
            printf("%s is present, Score %d\n", str, score);
        } else {
            if (score > 0) score--;
            printf("%s is not present, Score %d\n", str, score);
        }

        generateRandomArray(arr); 
    }

    printf("Final Score: %d\n", score);

return 0;
}