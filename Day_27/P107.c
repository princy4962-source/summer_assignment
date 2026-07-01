#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "salary_data.dat"


typedef struct {
    int id;
    char name[50];
    float basic_salary;
    float allowance;
    float deductions;
    float net_salary;
} Employee;


void addEmployee();
void displayEmployees();
void searchEmployee();
void modifySalary();
void deleteEmployee();
void calculateNetSalary(Employee *emp);

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    SALARY MANAGEMENT SYSTEM     ");
        printf("\n=================================");
        printf("\n1. Add New Employee");
        printf("\n2. Display All Employees & Salaries");
        printf("\n3. Search Employee by ID");
        printf("\n4. Modify Salary Components");
        printf("\n5. Delete Employee Record");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: modifySalary(); break;
            case 5: deleteEmployee(); break;
            case 6: 
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}


void calculateNetSalary(Employee *emp) {
    emp->net_salary = emp->basic_salary + emp->allowance - emp->deductions;
}


void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (fp == NULL) {
        printf("\nError opening file!");
        return;
    }

    Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); // Clear newline buffer
    
    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; 

    printf("Enter Basic Salary: ");
    scanf("%f", &emp.basic_salary);
    printf("Enter Allowances (e.g., HRA, TA): ");
    scanf("%f", &emp.allowance);
    printf("Enter Deductions (e.g., Tax, PF): ");
    scanf("%f", &emp.deductions);

    calculateNetSalary(&emp);

    fwrite(&emp, sizeof(Employee), 1, fp);
    fclose(fp);

    printf("\nRecord added successfully!\n");
}


void displayEmployees() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found! Please add an employee first.\n");
        return;
    }

    Employee emp;
    printf("\n%-5s %-20s %-12s %-10s %-10s %-12s", "ID", "Name", "Basic", "Allow.", "Deduct.", "Net Salary");
    printf("\n-------------------------------------------------------------------------");
    
    while (fread(&emp, sizeof(Employee), 1, fp)) {
        printf("\n%-5d %-20s %-12.2f %-10.2f %-10.2f %-12.2f", 
               emp.id, emp.name, emp.basic_salary, emp.allowance, emp.deductions, emp.net_salary);
    }
    printf("\n-------------------------------------------------------------------------\n");
    fclose(fp);
}


void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int targetId, found = 0;
    Employee emp;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &targetId);

    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == targetId) {
            found = 1;
            printf("\nEmployee Found:");
            printf("\nID: %d", emp.id);
            printf("\nName: %s", emp.name);
            printf("\nBasic Salary: %.2f", emp.basic_salary);
            printf("\nAllowances: %.2f", emp.allowance);
            printf("\nDeductions: %.2f", emp.deductions);
            printf("\nNet Salary: %.2f\n", emp.net_salary);
            break;
        }
    }
    if (!found) {
        printf("\nEmployee with ID %d not found.\n", targetId);
    }
    fclose(fp);
}


void modifySalary() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int targetId, found = 0;
    Employee emp;

    printf("\nEnter Employee ID to modify metrics: ");
    scanf("%d", &targetId);

    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == targetId) {
            found = 1;
            printf("\nCurrent Basic Salary: %.2f. Enter New: ", emp.basic_salary);
            scanf("%f", &emp.basic_salary);
            printf("Current Allowances: %.2f. Enter New: ", emp.allowance);
            scanf("%f", &emp.allowance);
            printf("Current Deductions: %.2f. Enter New: ", emp.deductions);
            scanf("%f", &emp.deductions);

            calculateNetSalary(&emp);

            
            fseek(fp, -sizeof(Employee), SEEK_CUR);
            fwrite(&emp, sizeof(Employee), 1, fp);
            printf("\nSalary records updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("\nEmployee with ID %d not found.\n", targetId);
    }
    fclose(fp);
}


void deleteEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    FILE *tempFp = fopen("temp.dat", "wb");
    if (tempFp == NULL) {
        printf("\nError processing request!");
        fclose(fp);
        return;
    }

    int targetId, found = 0;
    Employee emp;

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &targetId);

    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == targetId) {
            found = 1; 
        } else {
            fwrite(&emp, sizeof(Employee), 1, tempFp);
        }
    }

    fclose(fp);
    fclose(tempFp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("\nEmployee record deleted successfully.\n");
    } else {
        printf("\nEmployee with ID %d not found.\n", targetId);
    }
}
