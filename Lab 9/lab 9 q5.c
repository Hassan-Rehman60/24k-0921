#include <stdio.h>

void swap_integers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    swap_integers(&num1, &num2);
    printf("After swapping: %d %d\n", num1, num2);
    return 0;
}