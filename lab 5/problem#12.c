#include <stdio.h>

int main() {
    float attendance, assignment, exam, final_grade;

    printf("Enter attendance score (out of 10): ");
    scanf("%f", &attendance);
    printf("Enter assignment score (out of 30): ");
    scanf("%f", &assignment);
    printf("Enter exam score (out of 60): ");
    scanf("%f", &exam);

    final_grade = attendance + assignment + exam;

    printf("Final grade: %.2f\n", final_grade);

    if (final_grade >= 90) {
        printf("Grade: A\n");
    } else if (final_grade >= 80) {
        printf("Grade: B\n");
    } else if (final_grade >= 70) {
        printf("Grade: C\n");
    } else if (final_grade >= 60) {
        printf("Grade: D\n");
    } else {
        printf("Grade: F\n");
    }

    return 0;
}