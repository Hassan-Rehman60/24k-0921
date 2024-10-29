#include <stdio.h>

int main() {
    int arr[5];
    int i, smallest, second_smallest;

    printf("Enter 5 elements:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    smallest = second_smallest = 9999;
    
    for (i = 0; i < 5; i++) {
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < second_smallest && arr[i] != smallest) {
            second_smallest = arr[i];
        }
    }

    printf("The second smallest element in the array is: %d\n", second_smallest);
    return 0;
}
