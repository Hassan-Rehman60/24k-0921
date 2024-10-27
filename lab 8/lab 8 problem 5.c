#include <stdio.h>

int main() {
    int num;
    printf("Enter a starting odd number: ");
    scanf("%d", &num);
    if (num % 2 == 0) {
        printf("Please enter an odd number.\n");
        return 1;
    }

    printf("Pattern of odd numbers in decreasing order:\n");
    for (int i = num; i >= 1; i -= 2) {
        for (int j = i; j >= 1; j -= 2) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}
