#include <stdio.h>
#include <string.h>

typedef struct {
    char packageName[30];
    char destination[30];
    int duration;  // in days
    float cost;
    int availableSeats;
} TravelPackage;

void displayPackages(TravelPackage packages[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\nPackage Name: %s\nDestination: %s\nDuration: %d days\nCost: %.2f\nAvailable Seats: %d\n",
               packages[i].packageName, packages[i].destination, packages[i].duration,
               packages[i].cost, packages[i].availableSeats);
    }
}

int main() {
    TravelPackage packages[2] = {
        {"Summer Escape", "Hawaii", 7, 1500.0, 20},
        {"Winter Wonderland", "Switzerland", 10, 2500.0, 15},
    };

    printf("\nAvailable Travel Packages:\n");
    displayPackages(packages, 2);

    return 0;
}