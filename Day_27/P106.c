#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.dat"


struct Employee {
    int id;
    char name[50];
    char designation[50];
    float salary;
};


void addEmployee();
void displayEmployees();
void searchEmployee();
void deleteEmployee();

int main() {
    int choice;

    while (1) {
        printf("\n=== EMPLOYEE MANAGEMENT SYSTEM ===");
        printf("\n1. Add Employee");
        printf("\n2. Display All Employees");
        printf("\n3. Search Employee by ID");
        printf("\n4. Delete Employee Record");
        printf("\n5. Exit");
        printf("\nEnter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: printf("\nExiting system. Goodbye!\n"); exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}


void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "ab"); 
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); 
    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; 

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(struct Employee), 1, fp);
    fclose(fp);

    printf("Employee record added successfully!\n");
}


void displayEmployees() {
    FILE *fp = fopen(FILE_NAME, "rb"); 
    if (fp == NULL) {
        printf("\nNo records found! Add some employees first.\n");
        return;
    }

    struct Employee emp;
    printf("\n---------------------------------------------------------------\n");
    printf("%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("---------------------------------------------------------------\n");

    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        printf("%-10d %-20s %-20s %-10.2f\n", emp.id, emp.name, emp.designation, emp.salary);
    }
    printf("---------------------------------------------------------------\n");
    fclose(fp);
}


void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int searchId, found = 0;
    struct Employee emp;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        if (emp.id == searchId) {
            printf("\nEmployee Found!");
            printf("\nID: %d", emp.id);
            printf("\nName: %s", emp.name);
            printf("\nDesignation: %s", emp.designation);
            printf("\nSalary: %.2f\n", emp.salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", searchId);
    }
    fclose(fp);
}


void deleteEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int deleteId, found = 0;
    struct Employee emp;

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

   
    FILE *tempFp = fopen("temp.dat", "wb");
    if (tempFp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        if (emp.id == deleteId) {
            found = 1; 
        } else {
            fwrite(&emp, sizeof(struct Employee), 1, tempFp);
        }
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove(FILE_NAME);             
        rename("temp.dat", FILE_NAME); 
        printf("Employee record deleted successfully!\n");
    } else {
        remove("temp.dat");            
        printf("Employee with ID %d not found.\n", deleteId);
    }
}