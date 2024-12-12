#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValidEmail(char *email) {
    int i = 0;
    int hasAt = 0, hasDot = 0;
    
    if (strlen(email) <= 1) return 0;

    while (*(email + i) != '\0') {
        if (*(email + i) == '@') hasAt = 1;
        if (*(email + i) == '.' && hasAt == 1) hasDot = 1;
        i++;
    }

    if (hasAt && hasDot) return 1;
    else return 0;
}

int main() {
    char *email;
    email = (char *)malloc(100 * sizeof(char));

    scanf("%s", email);

    email = (char *)realloc(email, (strlen(email) + 1) * sizeof(char));
    
    email[strlen(email)] = '\0';

    if (isValidEmail(email)) {
        printf("\nValid Email");
    } else {
        printf("\nInvalid Email");
    }

    free(email);

    return 0;
}
