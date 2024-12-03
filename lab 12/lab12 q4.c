#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[50];
    char author[50];
    int publicationYear;
} Book;

typedef struct {
    Book *books;
} Library;

int main() {
    Library library;
    int n = 5;

    library.books = (Book *)malloc(n * sizeof(Book));

    for (int i = 0; i < n; i++) {
        printf("Enter title, author, and publication year of book %d: ", i + 1);
        scanf("%s %s %d", library.books[i].title, library.books[i].author, &library.books[i].publicationYear);
    }

    printf("Books published after the year 2000:\n");
    for (int i = 0; i < n; i++) {
        if (library.books[i].publicationYear > 2000) {
            printf("%s\n", library.books[i].title);
        }
    }

    free(library.books);
    return 0;
}
