#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50


char studentNames[MAX_STUDENTS][NAME_LENGTH];
int studentRolls[MAX_STUDENTS];
float studentMarks[MAX_STUDENTS];
int totalStudents = 0;


void displayMenu();
void addStudent();
void viewAllStudents();
void searchStudentByName();
void calculateAverage();

int main() {
    int choice;

    
    while (1) {
        displayMenu();
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Exiting program.\n");
            break;
        }

        
        while (getchar() != '\n'); 

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewAllStudents();
                break;
            case 3:
                searchStudentByName();
                break;
            case 4:
                calculateAverage();
                break;
            case 5:
                printf("\nExiting program. Thank you!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}


void displayMenu() {
    printf("\n====================================");
    printf("\n   STUDENT DATABASE MINI-PROJECT    ");
    printf("\n====================================");
    printf("\n1. Add New Student");
    printf("\n2. View All Students");
    printf("\n3. Search Student by Name");
    printf("\n4. Calculate Class Average Marks");
    printf("\n5. Exit");
    printf("\n====================================\n");
}


void addStudent() {
    if (totalStudents >= MAX_STUDENTS) {
        printf("\nDatabase is full! Cannot add more students.\n");
        return;
    }

    printf("\nEnter Student Name: ");
    
    fgets(studentNames[totalStudents], NAME_LENGTH, stdin);
    
    studentNames[totalStudents][strcspn(studentNames[totalStudents], "\n")] = '\0';

    printf("Enter Roll Number: ");
    scanf("%d", &studentRolls[totalStudents]);

    printf("Enter Marks: ");
    scanf("%f", &studentMarks[totalStudents]);

    totalStudents++;
    printf("\nStudent added successfully!\n");
}


void viewAllStudents() {
    if (totalStudents == 0) {
        printf("\nNo student records found in the database.\n");
        return;
    }

    printf("\n%-5s %-25s %-10s %-5s\n", "No.", "Name", "Roll No.", "Marks");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < totalStudents; i++) {
        printf("%-5d %-25s %-10d %-5.2f\n", i + 1, studentNames[i], studentRolls[i], studentMarks[i]);
    }
}


void searchStudentByName() {
    if (totalStudents == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    char searchName[NAME_LENGTH];
    int found = 0;

    printf("\nEnter the exact name of the student to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; 

    for (int i = 0; i < totalStudents; i++) {
       
        if (strcmp(studentNames[i], searchName) == 0) {
            if (!found) {
                printf("\nRecord Found:\n");
                printf("%-25s %-10s %-5s\n", "Name", "Roll No.", "Marks");
                printf("---------------------------------------------------\n");
            }
            printf("A%-25s %-10d %-5.2f\n", studentNames[i], studentRolls[i], studentMarks[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("\nStudent matching '%s' not found.\n", searchName);
    }
}


void calculateAverage() {
    if (totalStudents == 0) {
        printf("\nNo student marks data available to compute average.\n");
        return;
    }

    float totalSum = 0;
    for (int i = 0; i < totalStudents; i++) {
        totalSum += studentMarks[i];
    }

    float average = totalSum / totalStudents;
    printf("\nTotal Students: %d", totalStudents);
    printf("\nClass Average Marks: %.2f\n", average);
}
