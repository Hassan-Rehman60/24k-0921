#include <stdio.h>

int sumOfDigits(int num) {
    if (num == 0)
        return 0;
    return (num % 10) + sumOfDigits(num / 10);
}

int main() {
    int number = 123;
    printf("Sum of digits: %d\n", sumOfDigits(number));
    return 0;
}