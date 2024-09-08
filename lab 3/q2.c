#include <stdio.h>

int main() {
    int a, b;

    // Input values from the user
    printf("Enter the first integer value (a): ");
    scanf("%d", &a);

    printf("Enter the second integer value (b): ");
    scanf("%d", &b);

    // Display the values before swapping
    printf("Before swapping: a = %d, b = %d\n", a, b);

    // Swapping the values
    a = a + b;
    b = a - b;
    a = a - b;

    // Display the values after swapping
    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}
