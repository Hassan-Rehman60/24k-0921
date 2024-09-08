#include <stdio.h>

int main() {
    float principal, rate, time, interest;

    // Input the principal amount
    do {
        printf("Enter the principal amount (between 100 and 1,000,000): ");
        scanf("%f", &principal);
    } while (principal < 100 || principal > 1000000);
    
    // Input the rate of interest
    do {
        printf("Enter the rate of interest (between 5%% and 10%%): ");
        scanf("%f", &rate);
    } while (rate < 5 || rate > 10);
    
    // Input the time period
    do {
        printf("Enter the time period (between 1 and 10 years): ");
        scanf("%f", &time);
    } while (time < 1 || time > 10);
    
    // Calculate simple interest
    interest = (principal * rate * time) / 100;
    
    // Output the interest
    printf("The simple interest is: %.2f\n", interest);
    
    return 0;
}