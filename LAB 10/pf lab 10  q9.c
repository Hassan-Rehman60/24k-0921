#include <stdio.h>

int linearSearch(int arr[], int size, int target, int index) {
    if (index >= size)
        return -1;
    if (arr[index] == target)
        return index;
    return linearSearch(arr, size, target, index + 1);
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int target = 8;
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = linearSearch(arr, size, target, 0);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}