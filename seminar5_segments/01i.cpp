#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book 
{
    char* title;
    int pages;
    float price;
};
typedef struct book Book;

struct library 
{
    Book* books;
    int numb;
};
typedef struct library Library;

void print_book(struct book b) 
{
    printf("Book info:\n");
    printf("Title: %s\nPages: %d\nPrice: %g\n\n", b.title, b.pages, b.price);
}

void library_create(Library* lib, int k) 
{
    lib->books = (Book*)malloc(k * sizeof(Book));
    lib->numb = k;
}

void library_set(Library lib, int ind, const char* title, int pages, float price) 
{
    lib.books[ind].title = (char*)malloc((strlen(title) + 1) * sizeof(char));
    strcpy(lib.books[ind].title, title);
    lib.books[ind].pages = pages;
    lib.books[ind].price = price;
}

Book* library_get(Library lib, int ind) 
{
    return &lib.books[ind];
}

void library_print(Library lib) 
{
    for (int i = 0; i != lib.numb; ++i)
    {
        printf("Book %d:\n", i + 1);
        print_book(lib.books[i]);
    }
}

void library_destroy(Library* lib) 
{
    for (int i = 0; i != lib->numb; ++i)
    {
        free(lib->books[i].title);
    }
    free(lib->books);
}

int main()
{
    Library a;  
    library_create(&a, 3);
    library_set(a, 0, "Don Quixote", 1000, 750.0);
    library_set(a, 1, "Oblomov", 400, 250.0);
    library_set(a, 2, "The Odyssey", 500, 500.0);
    library_print(a);
    library_destroy(&a);
}