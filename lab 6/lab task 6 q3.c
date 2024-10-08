#include <stdio.h>

int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num > 9 || num < -9) {
        printf("%d is a multiple digit number.\n", num);
    } else {
        printf("%d is not a multiple digit number.\n", num);
    }

    if (is_prime(num)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is a composite number.\n", num);
    }

    return 0;
}
