#include <stdio.h>
#define TOTAL_EMPLOYEES 4

void setEmployeeDetails(struct Employee *empPtr, int total);
void calculateTenure(struct Employee empArray[], int total);

struct Employee {
    int id;
    char name[100];
    int joiningYear;
};

int main() {
    struct Employee employees[TOTAL_EMPLOYEES];
    setEmployeeDetails(employees, TOTAL_EMPLOYEES);
    calculateTenure(employees, TOTAL_EMPLOYEES);
    return 0;
}

void setEmployeeDetails(struct Employee *empPtr, int total) {
    for (int idx = 0; idx < total; idx++) {
        printf("Enter the ID of employee %d: ", idx + 1);
        scanf("%d", &(empPtr + idx)->id);
        printf("Enter the name of employee %d: ", idx + 1);
        scanf("%s", (empPtr + idx)->name);
        printf("Enter the joining year of employee %d: ", idx + 1);
        scanf("%d", &(empPtr + idx)->joiningYear);
        printf("\n");
    }
}

void calculateTenure(struct Employee empArray[], int total) {
    int qualifiedCount = 0;
    int currentYear;

    printf("Enter the current year: ");
    scanf("%d", &currentYear);

    printf("Employees with tenure exceeding 3 years\n===========================================\n");
    for (int idx = 0; idx < total; idx++) {
        if (currentYear - empArray[idx].joiningYear > 3) {
            printf("Employee %d: %d %s %d\n", idx + 1, empArray[idx].id, empArray[idx].name, empArray[idx].joiningYear);
            qualifiedCount++;
        }
    }
    printf("\nTotal employees with tenure exceeding 3 years: %d", qualifiedCount);
}
