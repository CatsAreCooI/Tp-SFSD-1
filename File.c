#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h" 

// Function to free the linked list
void freeBooks(struct Book* head) {
    struct Book* current = head;
    struct Book* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
// Function to save the list of books to a text file
void saveBooksToFile(struct Book* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }
    struct Book* current = head;
    while (current != NULL) {
        fprintf(file, "%s\n%s\n%d\n", current->title, current->author, current->year);
        current = current->next;
    }
    fclose(file);
    printf("Books saved to '%s' successfully.\n", filename);
}

// Function to load the list of books from a text file
void loadBooksFromFile(struct Book** head, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }
    
    char title[100], author[100];
    int year;
    
    while (fgets(title, sizeof(title), file) != NULL) {
        title[strcspn(title, "\n")] = 0; // Remove newline
        fgets(author, sizeof(author), file);
        author[strcspn(author, "\n")] = 0; // Remove newline
        fscanf(file, "%d\n", &year);
        addBook(head, title, author, year);
    }
    
    fclose(file);
    printf("Books loaded from '%s' successfully.\n", filename);
}

