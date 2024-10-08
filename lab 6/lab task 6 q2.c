#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num > 9 || num < -9) {
        printf("%d is a multiple digit number.\n", num);
    } else {
        printf("%d is not a multiple digit number.\n", num);
    }

    return 0;
}