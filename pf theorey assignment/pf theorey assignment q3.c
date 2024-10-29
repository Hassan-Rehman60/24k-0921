#include <stdio.h>
#include <string.h>

void compressWord(char *word, char *compressed, int *removed_count) {
    int i, j = 0;
    *removed_count = 0;

    for (i = 0; word[i] != '\0'; i++) {
        if (i == 0 || word[i] != word[i - 1]) {
            compressed[j++] = word[i];
        } else {
            (*removed_count)++;
        }
    }
    compressed[j] = '\0';
}

int main() {
    char *words[] = {"booooook", "coooool", "heeeey"};
    int num_words = 3;
    char compressed[100];
    int removed_count;

    for (int i = 0; i < num_words; i++) {
        compressWord(words[i], compressed, &removed_count);
        printf("Original: %s, Compressed: %s, Characters removed: %d\n", words[i], compressed, removed_count);
    }

    return 0;
}
