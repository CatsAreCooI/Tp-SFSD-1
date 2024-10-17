#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "Struct.h"
#include "library.h"
#include "file.h"

//----------------------------------Main----------------------------------------//

int main() {
    struct BookNode *Library_Head = NULL;
    int choice;
    int TotalBooks = 0;

     system("cls");

    do {
        // User input Menu
        printf("\t--------- Library Menu: ---------\n\n");
        printf(" 1. Add Book\n");
        printf(" 2. Delete Book\n");
        printf(" 3. Edit Book\n");
        printf(" 4. Display Books\n");
        printf(" 5. Save Books to File\n");
        printf(" 6. Load Books from File\n");
        printf(" 7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clean the newline character from the input buffer

        switch (choice) {
            case 1:
                Library_Head = AddABook(Library_Head); // Call the function to add a book
                sleep(1); // sleep for 1 seconds
                system("cls"); // clear the screen
                break;

            case 2:
                Library_Head = DeleteABook(Library_Head); // Call the function to delete a book
                sleep(1); // sleep for 1 seconds
                system("cls"); // clear the screen
                break;

            case 3:
                EditABook(Library_Head); // Call the function to edit a book
                sleep(1); // sleep for 1 seconds
                system("cls"); // clear the screen
                break;

            case 4:
                DisplayLibrary(Library_Head); // Call the function to display the library
                printf("\nPress Enter to continue..."); 
                getchar();
                system("cls"); // clear the screen
                break;

            case 5:
                if (WriteFile("LibraryData", Library_Head)){
                    printf("Write data OK."); // Successfully wrote data to file
                    sleep(1); // sleep for 1 seconds
                    system("cls"); // clear the screen
                }
                else {
                    printf("Error Writing to the File."); // Error writing to file
                    sleep(1); // sleep for 1 seconds
                    system("cls"); // clear the screen
                }
                break;

            case 6:
                Library_Head = ReadFile("LibraryData"); // Read data from file

                if (Library_Head == NULL){
                    printf("Error Reading from the File."); // Error reading from file
                    sleep(1); // sleep for 1 seconds
                    system("cls"); // clear the screen
                }
                else {
                    printf("\nData read OK."); // Successfully read data from file
                    sleep(1); // sleep for 1 seconds
                    system("cls"); // clear the screen
                }
                break;

            case 7:
                freeBooks(Library_Head); // Free memory for the book list to end the program
                printf("Exiting.");
                usleep(500000); // sleep for .5 seconds
                printf(".");
                usleep(500000); // sleep for .5 seconds
                printf(".");
                usleep(500000); // sleep for .5 seconds
                break;

            default:
                printf("Invalid choice. Please try again.\n"); // Invalid input case
                sleep(1); // sleep for 1 seconds
                system("cls"); // clear the screen
                break;
        }
    } while (choice != 7); 

    return 0; 
}

