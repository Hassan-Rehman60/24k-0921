#include <stdio.h>

int main() {
    float distance = 1207; // Total distance in KM (back and forth)
    float forwardRate, returnRate, totalCost;
    float fuelConsumed, fuelAvg;
    
    // Input the fuel average from the user
    printf("Enter the fuel average (km per liter): ");
    scanf("%f", &fuelAvg);
    
    // Input the fuel prices for both trips
    printf("Enter the forward trip fuel price per liter: ");
    scanf("%f", &forwardRate);
    printf("Enter the return trip fuel price per liter: ");
    scanf("%f", &returnRate);
    
    // Calculate fuel consumption
    fuelConsumed = distance / fuelAvg;
    
    // Calculate total cost of fuel for both trips
    totalCost = (distance / 2) / fuelAvg * forwardRate + (distance / 2) / fuelAvg * returnRate;
    
    // Output the result
    printf("Total fuel consumed: %.2f liters\n", fuelConsumed);
    printf("Total cost of fuel: %.2f\n", totalCost);
    
    return 0;
}