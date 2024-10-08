#include <stdio.h>

int main() {
    int a = 1, b = 2, temp, n = 6;

    printf("Fibonacci Series: %d, %d", a, b);
    for (int i = 2; i < n; i++) {
        temp = a + b;
        printf(", %d", temp);
        a = b;
        b = temp;
    }
    printf("\n");
    
    return 0;
}