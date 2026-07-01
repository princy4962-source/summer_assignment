#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Student {
    int roll_no;
    char name[50];
    char course[50];
    float gpa;
};


void add_student();
void display_students();
void search_student();
void delete_student();

const char *FILE_NAME = "students.txt";

int main() {
    int choice;

    while (1) {
        printf("\n========================================\n");
        printf("    STUDENT RECORD MANAGEMENT SYSTEM    \n");
        printf("========================================\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Delete Student Record\n");
        printf("5. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                delete_student();
                break;
            case 5:
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}


void add_student() {
    FILE *file = fopen(FILE_NAME, "a"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Student s;
    
    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll_no);
    getchar(); 

    printf("Enter Full Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; 
    printf("Enter Course: ");
    fgets(s.course, sizeof(s.course), stdin);
    s.course[strcspn(s.course, "\n")] = '\0';

    printf("Enter GPA: ");
    scanf("%f", &s.gpa);

    
    fprintf(file, "%d|%s|%s|%.2f\n", s.roll_no, s.name, s.course, s.gpa);
    fclose(file);

    printf("\nStudent record added successfully!\n");
}

void display_students() {
    FILE *file = fopen(FILE_NAME, "r"); 
    if (file == NULL) {
        printf("\nNo records found! Add a student first.\n");
        return;
    }

    struct Student s;
    char line[200];
    int count = 0;

    printf("\n%-10s %-25s %-20s %-5s\n", "Roll No", "Name", "Course", "GPA");
    printf("-------------------------------------------------------------------\n");

    
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d|%[^|]|%[^|]|%f", &s.roll_no, s.name, s.course, &s.gpa);
        printf("%-10d %-25s %-20s %-5.2f\n", s.roll_no, s.name, s.course, s.gpa);
        count++;
    }

    fclose(file);
    if (count == 0) {
        printf("No records available to show.\n");
    }
}

void search_student() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    int search_roll, found = 0;
    struct Student s;
    char line[200];

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &search_roll);

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d|%[^|]|%[^|]|%f", &s.roll_no, s.name, s.course, &s.gpa);
        if (s.roll_no == search_roll) {
            printf("\nRecord Found!\n");
            printf("----------------------------------------\n");
            printf("Roll Number : %d\n", s.roll_no);
            printf("Name        : %s\n", s.name);
            printf("Course      : %s\n", s.course);
            printf("GPA         : %.2f\n", s.gpa);
            printf("----------------------------------------\n");
            found = 1;
            break;
        }
    }

    fclose(file);
    if (!found) {
        printf("\nStudent with Roll Number %d not found.\n", search_roll);
    }
}


void delete_student() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    int delete_roll, found = 0;
    struct Student s;
    char line[200];

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &delete_roll);

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d|%[^|]|%[^|]|%f", &s.roll_no, s.name, s.course, &s.gpa);
        
        if (s.roll_no != delete_roll) {
            fprintf(temp_file, "%d|%s|%s|%.2f\n", s.roll_no, s.name, s.course, s.gpa);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp_file);

    
    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("\nRecord deleted successfully!\n");
    } else {
        remove("temp.txt"); 
        printf("\nStudent with Roll Number %d not found.\n", delete_roll);
    }
}
