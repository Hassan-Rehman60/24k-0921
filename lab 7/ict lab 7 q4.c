#include <stdio.h>

int main() {
    int arr[] = {2, 3, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int freq[n];
    for (int i = 0; i < n; i++) {
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    printf("Elements occurring more than once: ");
    for (int i = 0; i < n; i++) {
        if (freq[i] > 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}