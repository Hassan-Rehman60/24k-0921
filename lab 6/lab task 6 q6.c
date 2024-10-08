#include <stdio.h>

int main() {
    int series[] = {1, 2, 2, 4, 8, 32, 256, 8192, 2097152};
    int n = sizeof(series) / sizeof(series[0]);

    for (int i = 0; i < n; i++) {
        printf("%d ", series[i]);
    }
    printf("\n");

    return 0;
}
