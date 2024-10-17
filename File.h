#ifndef FILE_H
#define FILE_H

#include <stdbool.h>

#include "Struct.h" // Include the necessary header for your book structure

//--------------------------------Declaration-------------------------------------//

// Function to write the library data to a file
bool WriteFile(char *, BookNode *);

// Function to read library data from a file and create a book list
BookNode *ReadFile(char *);

#endif
