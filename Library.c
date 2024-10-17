#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Struct.h"
#include "library.h"
#include "file.h"


//----------------------- Display the entire library -----------------------//
void DisplayLibrary(BookNode *Library_Head) {
    BookNode *Current = Library_Head;
    int i = 1;
    printf("\n\t\t\tTotal Books: %d\n\n", NumberOfBooks(Library_Head));
    while (Current != NULL) {
        printf("<Book%d> Title: %-9s\tAuthor: %-9s\tRelease date: %d\n", i,
               Current->Book.Title, Current->Book.Author, Current->Book.pub_year);
        i++;
        Current = Current->next;
    }
}


//---------------------- Add a book to the library ------------------//
BookNode *AddABook(BookNode *Library_Head) {
    char sTitle[70];
    char sAuthor[70];
    int spub_year;
    bool IS_ADDED = false;

    printf("Please Enter the Title: ");
    scanf("%s", sTitle);
    getchar();
    printf("Please Enter the Author's full name: ");
    scanf("%s", sAuthor);
    getchar();
    printf("Please Enter the Publication year: ");
    scanf("%d", &spub_year);
    getchar();

    BookNode *NewBook = calloc(1, sizeof(BookNode));
    strcpy(NewBook->Book.Title, sTitle);
    strcpy(NewBook->Book.Author, sAuthor);
    NewBook->Book.pub_year = spub_year;

    BookNode *Current = Library_Head;
    BookNode *prev = NULL;

    if (Library_Head == NULL) {
        return NewBook; // If the library is empty, add the book as the head
    } else if (Library_Head->next == NULL) {
        // Only one book in the library
        if (compareTitles(Current->Book.Title, NewBook->Book.Title) > 0) {
            NewBook->next = Library_Head;
            return NewBook;
        } else {
            Library_Head->next = NewBook;
            return Library_Head;
        }
    } else {
        // Multiple books in the library
        while (Current != NULL) {
            int cmpResult = compareTitles(Current->Book.Title, NewBook->Book.Title);
            if (cmpResult > 0) {
                if (prev == NULL) {
                    // Insert at the beginning
                    NewBook->next = Current;
                    Library_Head = NewBook;
                } else {
                    // Insert in the middle
                    prev->next = NewBook;
                    NewBook->next = Current;
                }
                IS_ADDED = true;
                return Library_Head;
            } else if (cmpResult == 0) {
                printf("This Book is already added!");

                return Library_Head;
            }
            prev = Current;
            Current = Current->next;
        }

        if (!IS_ADDED) {
            // Insert at the end
            prev->next = NewBook;
        }
        return Library_Head;
    }
}


//------------------ Compare titles (used for sorting or searching) ------------------//
int compareTitles(const char *Title1, const char *Title2) {
    return strcmp(Title1, Title2);
}


//--------------------- Delete a book from the library --------------------//
BookNode *DeleteABook(BookNode *Library_Head) {
    char tmpTitle[70];
    BookNode *Current = Library_Head;
    BookNode *Prev;
    bool IS_REMOVED = false;

    printf("Enter the title of the book to remove: ");
    scanf("%s", tmpTitle);

    int cmpResult = compareTitles(Library_Head->Book.Title, tmpTitle);
    if (cmpResult == 0) {
        printf("Book found!");
        Current = Library_Head->next;
        free(Library_Head);
        printf("Book removed!");
        return Current;
    }

    while (Current != NULL) {
        cmpResult = compareTitles(Current->Book.Title, tmpTitle);
        if (cmpResult == 0) {
            printf("Book found!");
            Prev->next = Current->next;
            free(Current);
            printf("Book removed!");
            IS_REMOVED = true;
            return Library_Head;
        }
        Prev = Current;
        Current = Current->next;
    }

    if (!IS_REMOVED) {
        printf("Book not found!");
        return Library_Head;
    }
}


//----------------------- Edit details of a book in the library -----------------------//
void EditABook(BookNode* head) {
    BookNode* Current = head;
    char tmpTitle[70], tmpAuthor[70];
    int tmpPubYear;

    printf("Enter the title of the book to edit: ");
    scanf("%s", tmpTitle);

    while (Current != NULL && strcmp(Current->Book.Title, tmpTitle) != 0) {
        Current = Current->next;
    }

    if (Current == NULL) {
        printf("Book with title '%s' not found.", tmpTitle);
        return;
    }

    printf("Editing Book '%s':\n", Current->Book.Title);
    printf("Enter new title: ");
    scanf("%s", tmpTitle);
    strcpy(Current->Book.Title, tmpTitle);
    getchar(); // Clear newline character from input buffer
    printf("Enter new author: ");
    scanf("%s", tmpAuthor);
    getchar();
    strcpy(Current->Book.Author, tmpAuthor);
    printf("Enter new year of publication: ");
    scanf("%d", &Current->Book.pub_year);
    getchar();
    printf("Book details updated successfully.");
}


//----------------------- Free memory for the entire book list -----------------------//
void freeBooks(BookNode* head) {
    BookNode* current = head;
    BookNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}


//----------------------- Get the total number of books in the library -----------------------//
int NumberOfBooks(BookNode *Library_Head) {
    int count = 0;
    BookNode *Current = Library_Head;
    while (Current != NULL) {
        count++;
        Current = Current->next;
    }
    return count;
}


//----------------------- Load a book from a struct and add it to the library -----------------------//
BookNode *LoadABook(Book *NewBook, BookNode *Library_Head) {
    BookNode *NewBookNode = calloc(1, sizeof(BookNode));
    NewBookNode->Book = *NewBook;
    BookNode *Current = Library_Head;

    if (Library_Head == NULL)
        return NewBookNode;
    else {
        while (Current->next != NULL) {
            Current = Current->next;
        }
    }

    Current->next = NewBookNode;
    return Library_Head;
}