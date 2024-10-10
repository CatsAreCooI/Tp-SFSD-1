#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "file.h"

int main() {
    struct Book* library = NULL; // Head of the linked list
    int choice;
    char title[100];
    char author[100];
    int year;

    do {
        printf("\nLibrary Menu:\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Edit Book\n");
        printf("4. Display Books\n");
        printf("5. Save Books to File\n");
        printf("6. Load Books from File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline

                printf("Enter author name: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = 0; // Remove newline

                printf("Enter year of publication: ");
                scanf("%d", &year);
                getchar(); // Consume newline character

                addBook(&library, title, author, year);
                break;

            case 2:
                printf("Enter book title to delete: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                deleteBook(&library, title);
                break;

            case 3:
                printf("Enter book title to edit: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                editBook(library, title);
                break;

            case 4:
                displayBooks(library);
                break;

            case 5:
                saveBooksToFile(library, "books.txt");
                break;

            case 6:
                loadBooksFromFile(&library, "books.txt");
                break;

            case 7:
                freeBooks(library);
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}
