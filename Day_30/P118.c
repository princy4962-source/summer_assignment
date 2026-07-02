#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100


struct Book {
    int id;
    char title[100];
    char author[50];
};


struct Book library[MAX_BOOKS];
int bookCount = 0;


void addBook();
void displayBooks();
void searchBook();

int main() {
    int choice;

    while (1) {
        printf("\n=============================\n");
        printf(" MINI LIBRARY MANAGEMENT SYSTEM \n");
        printf("=============================\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                printf("\nThank you for using the Library System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select between 1 and 4.\n");
        }
    }
    return 0;
}


void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nLibrary is full! Cannot add more books.\n");
        return;
    }

    struct Book newBook;
    printf("\nEnter Book ID (Integer): ");
    scanf("%d", &newBook.id);
    
    
    while (getchar() != '\n');

    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; 

    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; 

    
    library[bookCount] = newBook;
    bookCount++;

    printf("\nBook added successfully!\n");
}


void displayBooks() {
    if (bookCount == 0) {
        printf("\nThe library is empty. No books to display.\n");
        return;
    }

    printf("\n%-10s %-40s %-30s\n", "Book ID", "Title", "Author");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-10d %-40s %-30s\n", library[i].id, library[i].title, library[i].author);
    }
}


void searchBook() {
    if (bookCount == 0) {
        printf("\nThe library is empty. Search unavailable.\n");
        return;
    }

    int searchId;
    int found = 0;

    printf("\nEnter the Book ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            printf("\nBook Found!");
            printf("\nID: %d", library[i].id);
            printf("\nTitle: %s", library[i].title);
            printf("\nAuthor: %s\n", library[i].author);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nBook with ID %d not found.\n", searchId);
    }
}
