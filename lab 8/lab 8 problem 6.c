#include <stdio.h>

int main() {
    int matrix[3][3];
    
    printf("Enter elements of a 3x3 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Saddle points:\n");
    int saddleFound = 0;
    
    for (int i = 0; i < 3; i++) {
        int row_min = matrix[i][0];
        int col_index = 0;

        for (int j = 1; j < 3; j++) {
            if (matrix[i][j] < row_min) {
                row_min = matrix[i][j];
                col_index = j;
            }
        }

        int is_saddle = 1;
        for (int k = 0; k < 3; k++) {
            if (matrix[k][col_index] > row_min) {
                is_saddle = 0;
                break;
            }
        }

        if (is_saddle) {
            printf("Saddle point at (%d, %d) = %d\n", i, col_index, row_min);
            saddleFound = 1;
        }
    }

    if (!saddleFound) {
        printf("No saddle points found.\n");
    }

    return 0;
}
