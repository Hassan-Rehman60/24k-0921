#include <stdio.h>
#include <string.h>

void reverseString(char str[], int index) {
    int n = strlen(str);
    if (index >= n / 2)
        return;

    char temp = str[index];
    str[index] = str[n - index - 1];
    str[n - index - 1] = temp;

    reverseString(str, index + 1);
}

int main() {
    char str[] = "hello";
    reverseString(str, 0);
    printf("Reversed string: %s\n", str);
    return 0;
}