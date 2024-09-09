#include <stdio.h>

int main() {
    float cost, discount = 0, finalAmount, savedAmount;

    printf("Enter the cost of shopping: ");
    scanf("%f", &cost);

    if (cost >= 500) {
        if (cost < 2000) {
            discount = 5;
        } else if (cost <= 4000) {
            discount = 10;
        } else if (cost <= 6000) {
            discount = 20;
        } else {
            discount = 35;
        }

        savedAmount = (discount / 100) * cost;
        finalAmount = cost - savedAmount;

        printf("Original Cost: %.2f\n", cost);
        printf("Discount: %.2f%%\n", discount);
        printf("Amount Saved: %.2f\n", savedAmount);
        printf("Amount after Discount: %.2f\n", finalAmount);
    } else {
        printf("No discount applicable. Minimum amount for discount is 500.\n");
    }

    return 0;
}