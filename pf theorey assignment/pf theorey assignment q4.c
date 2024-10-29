#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char *transactions[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int num_transactions = 6;
    char sorted[6][10]; 
    int used[6] = {0};  

    for (int i = 0; i < num_transactions; i++) {
        strcpy(sorted[i], transactions[i]);
        sortString(sorted[i]);
    }

    for (int i = 0; i < num_transactions; i++) {
        if (!used[i]) {
            printf("[");
            printf("%s", transactions[i]);
            used[i] = 1;
            for (int j = i + 1; j < num_transactions; j++) {
                if (strcmp(sorted[i], sorted[j]) == 0 && !used[j]) {
                    printf(", %s", transactions[j]);
                    used[j] = 1;
                }
            }
            printf("]\n");
        }
    }

    return 0;
}
