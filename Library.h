#ifndef LIBRARY_H
#define LIBRARY_H

#include "Struct.h" // Include the necessary header for your book structure

//--------------------------------Declaration-------------------------------------//

// Function to display the entire library
void DisplayLibrary(BookNode *);

// Function to add a book to the library
BookNode *AddABook(BookNode *);

// Function to compare titles (used for sorting or searching)
int compareTitles(const char*, const char*);

// Function to delete a book from the library
BookNode *DeleteABook(BookNode *);

// Function to edit book details
void EditABook(BookNode*);

// Function to free memory for the entire book list
void freeBooks(BookNode*);

// Function to get the total number of books in the library
int NumberOfBooks(BookNode*);

// Function to load a book from a file and add it to the library
BookNode *LoadABook(Book*, BookNode*);

#endif
