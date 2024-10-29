#include <stdio.h>
int main() {
    int n, i, j, center;

    printf("Enter an odd value for N: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("Please enter an odd number.\n");
        return 1;
    }

    center = n / 2;

    for (i = 0; i <= center; i++) {
        for (j = 0; j < n; j++) {
            if (j >= center - i && j <= center + i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    for (i = center - 1; i >= 0; i--) {
        for (j = 0; j < n; j++) {
            if (j >= center - i && j <= center + i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

return 0;
}