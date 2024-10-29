#include <stdio.h>

int findWinningMove(int N) {
    if (N % 5 == 0) {
        return -1; 
    } else {
        return N % 5; 
    }
}

int main() {
    int N;
    printf("Enter the number of matchsticks: ");
    scanf("%d", &N);
    
    int result = findWinningMove(N);
    if (result == -1) {
        printf("It's impossible for A to win.\n");
    } else {
        printf("A should pick %d matchstick(s) on his 1st turn to guarantee a win.\n", result);
    }
    
return 0;
}