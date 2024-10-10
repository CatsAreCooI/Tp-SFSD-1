#ifndef FILE_H
#define FILE_H

void saveBooksToFile(struct Book* head, const char* filename);
void loadBooksFromFile(struct Book** head, const char* filename);

#endif
