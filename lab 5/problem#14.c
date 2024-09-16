#include <stdio.h>

int main() {
    int age, credit_score;
    float income;

    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter annual income: ");
    scanf("%f", &income);
    printf("Enter credit score: ");
    scanf("%d", &credit_score);

    if (age >= 18 && income >= 50000 && credit_score >= 700) {
        printf("Eligible for loan\n");
    } else {
        printf("Not eligible for loan\n");
    }

    return 0;
}