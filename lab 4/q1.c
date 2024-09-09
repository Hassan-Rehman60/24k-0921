#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num % 3 == 0)
        printf("This number is a multiple of 3.\n");
    else
        printf("This number is not a multiple of 3.\n");

    return 0;
}