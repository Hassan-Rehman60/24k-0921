#include <stdio.h>
#include <string.h>

void append_n_chars(char dest[], char source[], int n) {
    strncat(dest, source, n);
    printf("Concatenated String: %s\n", dest);
}

int main() {
    char dest[100], source[100];
    int n;

    printf("Enter destination string: ");
    scanf("%s", dest);
    printf("Enter source string: ");
    scanf("%s", source);
    printf("Enter number of characters to append: ");
    scanf("%d", &n);

    append_n_chars(dest, source, n);

    return 0;
}