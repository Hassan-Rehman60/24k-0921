#include <stdio.h>
#include <string.h>

void countFrequency(char *slogan) {
    int count[256] = {0}; 

    for (int i = 0; slogan[i] != '\0'; i++) {
        count[(int)slogan[i]]++;
    }

    printf("Character frequencies in \"%s\":\n", slogan);
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            printf("'%c': %d, ", i, count[i]);
        }
    }
    printf("\n");
}

int main() {
    char *slogans[] = {"buy now", "save big", "limited offer"};
    int num_slogans = 3;

    for (int i = 0; i < num_slogans; i++) {
        countFrequency(slogans[i]);
    }

    return 0;
}
