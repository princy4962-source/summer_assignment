#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "inventory.txt"


typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;


void addProduct();
void viewInventory();
void updateProduct();
void deleteProduct();
void searchProduct();

int main() {
    int choice;

    while (1) {
        printf("\n=== INVENTORY MANAGEMENT SYSTEM ===");
        printf("\n1. Add New Product");
        printf("\n2. View All Products");
        printf("\n3. Update Product Stock/Price");
        printf("\n4. Delete a Product");
        printf("\n5. Search Product by ID");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewInventory(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: searchProduct(); break;
            case 6: 
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please choose between 1 and 6.\n");
        }
    }
    return 0;
}


void addProduct() {
    FILE *file = fopen(FILE_NAME, "ab"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Product p;
    printf("\nEnter Product ID (Integer): ");
    scanf("%d", &p.id);
    getchar(); 

    printf("Enter Product Name: ");
    fgets(p.name, sizeof(p.name), stdin);

    printf("Enter Quantity: ");
    scanf("%d", &p.quantity);
    
    printf("Enter Price: ");
    scanf("%f", &p.price);

    fwrite(&p, sizeof(Product), 1, file);
    fclose(file);

    printf("Product added successfully!\n");
}


void viewInventory() {
    FILE *file = fopen(FILE_NAME, "rb"); 
    if (file == NULL) {
        printf("\nNo inventory records found. Add some products first!\n");
        return;
    }

    Product p;
    printf("\n-----------------------------------------------------------------");
    printf("\n%-10s %-25s %-12s %-10s", "ID", "Product Name", "Quantity", "Price");
    printf("\n-----------------------------------------------------------------");

    while (fread(&p, sizeof(Product), 1, file) == 1) {
        printf("\n%-10d %-25s %-12d $%-9.2f", p.id, p.name, p.quantity, p.price);
    }
    printf("\n-----------------------------------------------------------------\n");
    fclose(file);
}


void updateProduct() {
    FILE *file = fopen(FILE_NAME, "rb+"); 
    if (file == NULL) {
        printf("\nNo inventory records found!\n");
        return;
    }

    int targetId, found = 0;
    printf("\nEnter Product ID to update: ");
    scanf("%d", &targetId);

    Product p;
    while (fread(&p, sizeof(Product), 1, file) == 1) {
        if (p.id == targetId) {
            found = 1;
            printf("Current Details - Name: %s | Qty: %d | Price: $%.2f\n", p.name, p.quantity, p.price);
            
            printf("Enter New Quantity: ");
            scanf("%d", &p.quantity);
            printf("Enter New Price: ");
            scanf("%f", &p.price);

            
            fseek(file, -sizeof(Product), SEEK_CUR);
            fwrite(&p, sizeof(Product), 1, file);
            printf("Product updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", targetId);
    }
    fclose(file);
}


void deleteProduct() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo inventory records found!\n");
        return;
    }

    int targetId, found = 0;
    printf("\nEnter Product ID to delete: ");
    scanf("%d", &targetId);

    
    FILE *tempFile = fopen("temp.txt", "wb");
    if (tempFile == NULL) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    Product p;
    while (fread(&p, sizeof(Product), 1, file) == 1) {
        if (p.id == targetId) {
            found = 1; 
        } else {
            fwrite(&p, sizeof(Product), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);             
        rename("temp.txt", FILE_NAME); 
        printf("Product deleted successfully!\n");
    } else {
        remove("temp.txt"); 
        printf("Product with ID %d not found.\n", targetId);
    }
}


void searchProduct() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo inventory records found!\n");
        return;
    }

    int targetId, found = 0;
    printf("\nEnter Product ID to search: ");
    scanf("%d", &targetId);

    Product p;
    while (fread(&p, sizeof(Product), 1, file) == 1) {
        if (p.id == targetId) {
            found = 1;
            printf("\nProduct Found:");
            printf("\nID: %d", p.id);
            printf("\nName: %s", p.name);
            printf("\nQuantity: %d", p.quantity);
            printf("\nPrice: $%.2f\n", p.price);
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", targetId);
    }
    fclose(file);
}
