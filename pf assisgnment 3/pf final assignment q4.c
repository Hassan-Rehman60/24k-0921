#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee {
    int *ratings;
    int totalScore;
};

void inputEmployeeRatings(int **ratings, int numEmployees, int numPeriods);
void displayEmployeePerformance(int **ratings, int numEmployees, int numPeriods);
int findEmployeeOfTheYear(int **ratings, int numEmployees, int numPeriods);
int findTopRatedPeriod(int **ratings, int numEmployees, int numPeriods);
int findLowestPerformingEmployee(int **ratings, int numEmployees, int numPeriods);

int main() {
    struct Employee *empPtr;
    int numEmployees, numPeriods;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter the total number of evaluations: ");
    scanf("%d", &numPeriods);

    empPtr = (struct Employee*)malloc(sizeof(struct Employee) * numEmployees);
    for (int i = 0; i < numEmployees; i++) {
        empPtr[i].ratings = (int *)malloc(sizeof(int) * numPeriods);
    }

    int **ratings = (int **)malloc(sizeof(int *) * numEmployees);
    for (int i = 0; i < numEmployees; i++) {
        ratings[i] = empPtr[i].ratings;
    }

    inputEmployeeRatings(ratings, numEmployees, numPeriods);
    displayEmployeePerformance(ratings, numEmployees, numPeriods);

    printf("\n\n\n==========================================\nEmployee %d has the highest average score.", findEmployeeOfTheYear(ratings, numEmployees, numPeriods) + 1);
    printf("\nPeriod %d has the highest average score.", findTopRatedPeriod(ratings, numEmployees, numPeriods) + 1);
    printf("\nThe worst performing employee is %d", findLowestPerformingEmployee(ratings, numEmployees, numPeriods) + 1);

    // Free the allocated memory
    for (int i = 0; i < numEmployees; i++) {
        free(empPtr[i].ratings);
    }
    free(empPtr);
    free(ratings);

    return 0;
}

void inputEmployeeRatings(int **ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        printf("Enter ratings for employee %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("Evaluation %d: ", j + 1);
            scanf("%d", &ratings[i][j]);
        }
    }
}

void displayEmployeePerformance(int **ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        printf("\n\nRatings of employee %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("Evaluation %d: %d\n", j + 1, ratings[i][j]);
        }
    }
}

int findEmployeeOfTheYear(int **ratings, int numEmployees, int numPeriods) {
    int highestAvg = -1, bestEmployeeIndex;
    for (int i = 0; i < numEmployees; i++) {
        int total = 0;
        for (int j = 0; j < numPeriods; j++) {
            total += ratings[i][j];
        }
        int avg = total / numPeriods;
        if (avg > highestAvg) {
            highestAvg = avg;
            bestEmployeeIndex = i;
        }
    }
    return bestEmployeeIndex;
}

int findTopRatedPeriod(int **ratings, int numEmployees, int numPeriods) {
    int highestAvg = -1, bestPeriodIndex;
    for (int i = 0; i < numPeriods; i++) {
        int total = 0;
        for (int j = 0; j < numEmployees; j++) {
            total += ratings[j][i];
        }
        int avg = total / numEmployees;
        if (avg > highestAvg) {
            highestAvg = avg;
            bestPeriodIndex = i;
        }
    }
    return bestPeriodIndex;
}

int findLowestPerformingEmployee(int **ratings, int numEmployees, int numPeriods) {
    int lowestAvg = 9999, worstEmployeeIndex;
    for (int i = 0; i < numEmployees; i++) {
        int total = 0;
        for (int j = 0; j < numPeriods; j++) {
            total += ratings[i][j];
        }
        int avg = total / numPeriods;
        if (avg < lowestAvg) {
            lowestAvg = avg;
            worstEmployeeIndex = i;
        }
    }
    return worstEmployeeIndex;
}
