#include <stdio.h>
#include <string.h>

typedef struct {
    char make[20];
    char model[20];
    int year;
    float price;
    int mileage;
} Car;

void addCar(Car cars[], int *count) {
    printf("\nEnter Car Make: ");
    scanf(" %[^\n]", cars[*count].make);
    printf("Enter Model: ");
    scanf(" %[^\n]", cars[*count].model);
    printf("Enter Year: ");
    scanf("%d", &cars[*count].year);
    printf("Enter Price: ");
    scanf("%f", &cars[*count].price);
    printf("Enter Mileage: ");
    scanf("%d", &cars[*count].mileage);
    (*count)++;
}

void displayCars(Car cars[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\nMake: %s\nModel: %s\nYear: %d\nPrice: %.2f\nMileage: %d\n",
               cars[i].make, cars[i].model, cars[i].year, cars[i].price, cars[i].mileage);
    }
}

int main() {
    Car cars[10];
    int count = 0;

    addCar(cars, &count);
    addCar(cars, &count);

    printf("\nCars in Dealership:\n");
    displayCars(cars, count);

    return 0;
}
