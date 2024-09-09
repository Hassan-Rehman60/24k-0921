#include <stdio.h>

int main() {

char ch;

printf("Enter a character: ");

scanf("%c", &ch);

if (ch >= 'a' && ch <= 'z')

printf("Small Alphabet\n"); else if (ch >= 'A' && ch <= 'Z') printf("Capital Alphabet\n"); else if (ch >= '0' && ch <= '9')

printf("Digit\n");

else

printf("Special Character\n");

return 0;

}