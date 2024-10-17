#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Struct.h"
#include "library.h"


//----------------------- Write the library data to a binary file -----------------------//
bool WriteFile(char *FileName, BookNode *Library_Head) {
    FILE *file;
    file = fopen(FileName, "wb"); // Open the file for writing in binary mode
    if (file == NULL)
        return false; // Failed to open the file

    BookNode *Current = Library_Head;
    while (Current != NULL) {
        fwrite(&Current->Book, sizeof(Book), 1, file); // Write book data to the file
        Current = Current->next;
    }

    if (fclose(file) == EOF)
        return false; // Failed to close the file
    return true; // Successfully wrote data to the file
}


//----------------------- Read library data from a binary file and create a book list -----------------------//
BookNode *ReadFile(char *FileName) {
    FILE *file;
    file = fopen(FileName, "rb"); // Open the file for reading in binary mode
    if (file == NULL)
        return NULL; // Failed to open the file

    BookNode *Library_Head = NULL;
    Book *NewBook = calloc(1, sizeof(Book));
    while (fread(NewBook, sizeof(Book), 1, file)) {
        Library_Head = LoadABook(NewBook, Library_Head); // Load book data into the library
    }

    if (fclose(file) == EOF) {
        free(NewBook);
        return NULL; // Failed to close the file
    }
    return Library_Head; // Successfully read data from the file
}
