#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};


void addContact();
void listContacts();
void searchContact();
void deleteContact();

const char *FILENAME = "contacts.dat";

int main() {
    int choice;

    while (1) {
        printf("\n=== CONTACT MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Contact\n");
        printf("2. List All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        getchar(); 

        switch (choice) {
            case 1: addContact(); break;
            case 2: listContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: printf("Exiting system. Goodbye!\n"); exit(0);
            default: printf("Invalid choice! Please select between 1-5.\n");
        }
    }
    return 0;
}


void addContact() {
    FILE *fp = fopen(FILENAME, "ab"); 
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Contact newContact;

    printf("\nEnter Name: ");
    fgets(newContact.name, sizeof(newContact.name), stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0'; 

    printf("Enter Phone Number: ");
    fgets(newContact.phone, sizeof(newContact.phone), stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(newContact.email, sizeof(newContact.email), stdin);
    newContact.email[strcspn(newContact.email, "\n")] = '\0';

    fwrite(&newContact, sizeof(struct Contact), 1, fp);
    fclose(fp);

    printf("Contact saved successfully!\n");
}


void listContacts() {
    FILE *fp = fopen(FILENAME, "rb"); 
    if (fp == NULL) {
        printf("\nNo contacts found. The file is empty or does not exist.\n");
        return;
    }

    struct Contact c;
    int count = 1;

    printf("\n-------------------------------------------------------------\n");
    printf("%-5s %-20s %-15s %-20s\n", "S.No", "Name", "Phone", "Email");
    printf("-------------------------------------------------------------\n");

    while (fread(&c, sizeof(struct Contact), 1, fp) == 1) {
        printf("%-5d %-20s %-15s %-20s\n", count++, c.name, c.phone, c.email);
    }
    printf("-------------------------------------------------------------\n");

    fclose(fp);
}


void searchContact() {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("\nNo contacts available to search.\n");
        return;
    }

    char searchName[50];
    struct Contact c;
    int found = 0;

    printf("\nEnter the name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    while (fread(&c, sizeof(struct Contact), 1, fp) == 1) {
        
        if (strcmp(c.name, searchName) == 0) { 
            if (!found) {
                printf("\nContact Found:\n");
                printf("----------------------------------------\n");
            }
            printf("Name : %s\n", c.name);
            printf("Phone: %s\n", c.phone);
            printf("Email: %s\n", c.email);
            printf("----------------------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No contact found matching the name \"%s\".\n", searchName);
    }

    fclose(fp);
}


void deleteContact() {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("\nNo contacts available to delete.\n");
        return;
    }

    FILE *tempFp = fopen("temp.dat", "wb");
    if (tempFp == NULL) {
        printf("Error creating temporary storage!\n");
        fclose(fp);
        return;
    }

    char deleteName[50];
    struct Contact c;
    int found = 0;

    printf("\nEnter the name of the contact to delete: ");
    fgets(deleteName, sizeof(deleteName), stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0';

    
    while (fread(&c, sizeof(struct Contact), 1, fp) == 1) {
        if (strcmp(c.name, deleteName) == 0) {
            found = 1; 
        } else {
            fwrite(&c, sizeof(struct Contact), 1, tempFp);
        }
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove(FILENAME);         
        rename("temp.dat", FILENAME); 
        printf("Contact deleted successfully!\n");
    } else {
        remove("temp.dat"); 
        printf("Contact not found.\n");
    }
}
