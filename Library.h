#ifndef LIBRARY_H
#define LIBRARY_H

struct Book {
    char title[100];
    char author[100];
    int year;
    struct Book* next;
};

void addBook(struct Book** head, const char* title, const char* author, int year);
void deleteBook(struct Book** head, const char* title);
void editBook(struct Book* head, const char* title);
void displayBooks(struct Book* head);

#endif
