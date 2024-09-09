#include <stdio.h>

int main() {
    int customerId, units;
    char name[50];
    float amount;

    printf("Enter Customer ID: ");
    scanf("%d", &customerId);

    printf("Enter Customer Name: ");
    scanf("%s", name);

    printf("Enter units consumed: ");
    scanf("%d", &units);

    if (units <= 199) {
        amount = units * 16.20;
    } else if (units >= 200 && units < 300) {
        amount = units * 20.10;
    } else if (units >= 300 && units < 500) {
        amount = units * 27.10;
    } else {
        amount = units * 30.50;
    }

    printf("\nElectricity Bill\n");
    printf("Customer ID: %d\n", customerId);
    printf("Customer Name: %s\n", name);
    printf("Units Consumed: %d\n", units);
    printf("Total Amount: %.2f\n", amount);

    return 0;
}