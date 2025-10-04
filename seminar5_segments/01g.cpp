#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book 
{
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

void print_book(struct book b) 
{
    printf("Book info:\n");
    printf("Title: %s\nPages: %d\nPrice: %g\n\n", b.title, b.pages, b.price);
}

int main()
{
    Book* ah = (Book*)malloc(sizeof(Book) * 3);

    strcpy(ah[0].title, "Don Quixote");
    ah[0].pages = 1000;
    ah[0].price = 750.0;

    strcpy(ah[1].title, "Oblomov");
    ah[1].pages = 400;
    ah[1].price = 250.0;

    strcpy(ah[2].title, "The Odyssey");
    ah[2].pages = 500;
    ah[2].price = 500.0;

    print_book(ah[0]);
    print_book(ah[1]);
    print_book(ah[2]);

    free(ah);
}