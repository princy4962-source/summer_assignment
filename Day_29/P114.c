#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


void create(int arr[], int *n);
void display(int arr[], int n);
void insert(int arr[], int *n);
void deleteElement(int arr[], int *n);
void search(int arr[], int n);

int main() {
    int arr[MAX_SIZE];
    int n = 0; 
    int choice;

    while (1) {
        printf("\n========= ARRAY OPERATIONS MENU =========");
        printf("\n1. Create / Initialize Array");
        printf("\n2. Display Array");
        printf("\n3. Insert Element");
        printf("\n4. Delete Element");
        printf("\n5. Search Element");
        printf("\n6. Exit");
        printf("\n=========================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                create(arr, &n);
                break;
            case 2:
                display(arr, n);
                break;
            case 3:
                insert(arr, &n);
                break;
            case 4:
                deleteElement(arr, &n);
                break;
            case 5:
                search(arr, n);
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select an option between 1 and 6.\n");
        }
    }
    return 0;
}


void create(int arr[], int *n) {
    printf("Enter the number of elements to initialize (Max %d): ", MAX_SIZE);
    scanf("%d", n);

    if (*n < 0 || *n > MAX_SIZE) {
        printf("Invalid size! Resetting size to 0.\n");
        *n = 0;
        return;
    }

    printf("Enter %d elements:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Array initialized successfully!\n");
}


void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty! Nothing to display.\n");
        return;
    }

    printf("Array elements are: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}


void insert(int arr[], int *n) {
    if (*n >= MAX_SIZE) {
        printf("Error: Array Overflow! Cannot insert more elements.\n");
        return;
    }

    int element, pos;
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position index (0 to %d): ", *n);
    scanf("%d", &pos);

   
    if (pos < 0 || pos > *n) {
        printf("Invalid position! Position must be between 0 and %d.\n", *n);
        return;
    }

    
    for (int i = *n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos] = element; 
    (*n)++;            
    printf("Element inserted successfully!\n");
}


void deleteElement(int arr[], int *n) {
    if (*n == 0) {
        printf("Error: Array Underflow! No elements to delete.\n");
        return;
    }

    int pos;
    printf("Enter the position index to delete (0 to %d): ", *n - 1);
    scanf("%d", &pos);

    
    if (pos < 0 || pos >= *n) {
        printf("Invalid position! Position must be between 0 and %d.\n", *n - 1);
        return;
    }

    int deletedValue = arr[pos];

   
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--; 
    printf("Deleted element %d from position %d.\n", deletedValue, pos);
}


void search(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty! Cannot perform search.\n");
        return;
    }

    int target, found = -1;
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            found = i;
            break; 
        }
    }

    if (found != -1) {
        printf("Element %d found at index position %d.\n", target, found);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
}
