#include <stdio.h>

int main() {
    for (int i = 65536; i >= 0; i /= 2) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}