#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "file.h"

// Function to create a new book node
struct Book* createBook(const char* title, const char* author, int year) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    if (newBook == NULL) {
        perror("Failed to allocate memory for new book");
        exit(EXIT_FAILURE);
    }
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->year = year;
    newBook->next = NULL;
    return newBook;
}

// Function to add a book to the linked list
void addBook(struct Book** head, const char* title, const char* author, int year) {
    struct Book* newBook = createBook(title, author, year);
    newBook->next = *head; // Insert at the beginning
    *head = newBook;
}

// Function to delete a book from the linked list by title
void deleteBook(struct Book** head, const char* title) {
    struct Book *current = *head, *prev = NULL;
    while (current != NULL && strcmp(current->title, title) != 0) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Book with title '%s' not found.\n", title);
        return;
    }
    
    if (prev == NULL) {
        *head = current->next; // Book to delete is the first book
    } else {
        prev->next = current->next; // Bypass the current book
    }
    
    free(current);
    printf("Book '%s' deleted successfully.\n", title);
}

// Function to edit a book's details
void editBook(struct Book* head, const char* title) {
    struct Book* current = head;
    
    while (current != NULL && strcmp(current->title, title) != 0) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Book with title '%s' not found.\n", title);
        return;
    }
    
    printf("Editing book '%s':\n", current->title);
    printf("Enter new author: ");
    fgets(current->author, sizeof(current->author), stdin);
    current->author[strcspn(current->author, "\n")] = 0; // Remove newline

    printf("Enter new year of publication: ");
    scanf("%d", &current->year);
    getchar(); // Consume newline character
    printf("Book details updated successfully.\n");
}

// Function to display the list of books
void displayBooks(struct Book* head) {
    struct Book* current = head;
    if (current == NULL) {
        printf("No books in the library.\n");
        return;
    }
    printf("\nLibrary Books:\n");
    while (current != NULL) {
        printf("Title: %s, Author: %s, Year: %d\n", current->title, current->author, current->year);
        current = current->next;
    }
}

