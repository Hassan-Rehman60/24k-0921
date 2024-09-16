#include <stdio.h>

int main() {
    int age;
    char citizen;

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Are you a citizen? (y/n): ");
    scanf(" %c", &citizen);

    if (age >= 18 && (citizen == 'y' || citizen == 'Y')) {
        printf("Eligible to vote.\n");
    } else {
        printf("Not eligible to vote.\n");
    }

    return 0;
}