#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int marks;
} Student;

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student *students = (Student *)malloc(n * sizeof(Student));
    int sum = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter name and marks for student %d: ", i + 1);
        scanf("%s %d", students[i].name, &students[i].marks);
        sum += students[i].marks;
    }

    printf("Average Marks: %.2f\n", (float)sum / n);

    free(students);
    return 0;
}
