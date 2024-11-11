#include <stdio.h>

void find_max_min(int arr[], int n, int *max, int *min) {
    *max = arr[0];
    *min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > *max) *max = arr[i];
        if (arr[i] < *min) *min = arr[i];
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max, min;
    find_max_min(arr, n, &max, &min);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    return 0;
}