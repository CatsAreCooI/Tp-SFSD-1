#ifndef STRUCT_H
#define STRUCT_H


//----------------------- Define the Book structure -----------------------//
typedef struct Book {
    char Title[70];
    char Author[70];
    int pub_year;
} Book;


//----------------------- Define the BookNode structure -----------------------//
typedef struct BookNode {
    Book Book; // A Book within the node
    struct BookNode *next; // Pointer to the next BookNode
} BookNode;

#endif
