#include <stdio.h>

void check_even_odd(int num) {
    if (num % 2 == 0)
        printf("%d is Even\n", num);
    else
        printf("%d is Odd\n", num);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    check_even_odd(num);
    return 0;
}