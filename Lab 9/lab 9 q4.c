#include <stdio.h>
#include <string.h>

int is_palindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n = 5; // Array size example
    char words[5][20]; // Array of strings
    printf("Enter 5 words:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    for (int i = 0; i < n; i++) {
        if (is_palindrome(words[i])) {
            printf("%s is a Palindrome\n", words[i]);
        } else {
            printf("%s is Not a Palindrome\n", words[i]);
        }
    }
    return 0;
}