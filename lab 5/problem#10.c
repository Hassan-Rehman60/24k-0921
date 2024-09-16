#include <stdio.h>

int sum_of_digits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num >= 10) {
        num = sum_of_digits(num);
    }

    printf("Single digit sum: %d\n", num);

    return 0;
}