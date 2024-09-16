#include <stdio.h>

int main() {
    char ch, key = 5;

    printf("Enter a character to encrypt: ");
    scanf(" %c", &ch);

    ch = ch ^ key;  // Encryption
    printf("Encrypted character: %c\n", ch);

    ch = ch ^ key;  // Decryption
    printf("Decrypted character: %c\n", ch);

    return 0;
}