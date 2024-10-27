#include <stdio.h>

int main() {

    int matrix[2][3][3] = {
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},   
        {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}} 
    };

    int sum_page1 = 0, sum_page2 = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum_page1 += matrix[0][i][j]; 
            sum_page2 += matrix[1][i][j];  
        }
    }
    printf("Sum of elements on Page 1: %d\n", sum_page1);
    printf("Sum of elements on Page 2: %d\n", sum_page2);

    return 0;
}
