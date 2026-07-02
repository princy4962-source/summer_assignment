#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100


typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;


Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;


void addEmployee();
void displayEmployees();
void searchEmployee();
void deleteEmployee();

int main() {
    int choice;

    while (1) {
        printf("\n=== MINI EMPLOYEE MANAGEMENT SYSTEM ===\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                printf("Exiting system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}


void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("System full! Cannot add more employees.\n");
        return;
    }

    Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);

   
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == emp.id) {
            printf("Error: Employee ID %d already exists!\n", emp.id);
            return;
        }
    }

    printf("Enter Name: ");
    getchar(); 
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; 
    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    employees[employeeCount] = emp;
    employeeCount++;
    printf("Employee added successfully!\n");
}


void displayEmployees() {
    if (employeeCount == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%-10d %-20s %-20s %-10.2f\n", 
               employees[i].id, employees[i].name, employees[i].designation, employees[i].salary);
    }
}


void searchEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records to search.\n");
        return;
    }

    int searchId;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == searchId) {
            printf("\nRecord Found:\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Designation: %s\n", employees[i].designation);
            printf("Salary: %.2f\n", employees[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", searchId);
}


void deleteEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records to delete.\n");
        return;
    }

    int deleteId;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == deleteId) {
            
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee record deleted successfully!\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", deleteId);
}
