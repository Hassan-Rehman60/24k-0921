#include <stdio.h>
#include <string.h>

void reverse_string(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    printf("Reversed String: %s\n", str);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    reverse_string(str);
    return 0;
}