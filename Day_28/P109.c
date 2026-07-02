#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100


struct Book {
    int id;
    char title[100];
    char author[50];
    float price;
};


void addBook(struct Book library[], int *count);
void displayBooks(const struct Book library[], int count);
void searchBook(const struct Book library[], int count);

int main() {
    struct Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    LIBRARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search Book by ID");
        printf("\n4. View Total Book Count");
        printf("\n5. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                searchBook(library, bookCount);
                break;
            case 4:
                printf("\nTotal books currently in the library: %d\n", bookCount);
                break;
            case 5:
                printf("\nThank you for using the Library Management System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}


void addBook(struct Book library[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("\nError: Library storage is full!\n");
        return;
    }

    struct Book newBook;
    printf("\nEnter Book ID (Integer): ");
    scanf("%d", &newBook.id);
    
    
    getchar(); 

    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; 

    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; 

    printf("Enter Price: ");
    scanf("%f", &newBook.price);

    library[*count] = newBook;
    (*count)++;
    
    printf("\nSuccess: Book added successfully!\n");
}


void displayBooks(const struct Book library[], int count) {
    if (count == 0) {
        printf("\nThe library is empty. No books to display.\n");
        return;
    }

    printf("\n--------------------------------------------------------------------------------");
    printf("\n%-10s %-35s %-25s %-10s", "Book ID", "Title", "Author", "Price");
    printf("\n--------------------------------------------------------------------------------");
    
    for (int i = 0; i < count; i++) {
        printf("\n%-10d %-35s %-25s $%-9.2f", 
               library[i].id, library[i].title, library[i].author, library[i].price);
    }
    printf("\n--------------------------------------------------------------------------------\n");
}


void searchBook(const struct Book library[], int count) {
    if (count == 0) {
        printf("\nThe library is empty. Cannot search.\n");
        return;
    }

    int searchId;
    int found = 0;
    
    printf("\nEnter the Book ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (library[i].id == searchId) {
            printf("\n--- Book Found ---");
            printf("\nID:     %d", library[i].id);
            printf("\nTitle:  %s", library[i].title);
            printf("\nAuthor: %s", library[i].author);
            printf("\nPrice:  $%.2f\n", library[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nBook with ID %d not found.\n", searchId);
    }
}
