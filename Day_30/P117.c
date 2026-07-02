#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50


struct Student {
    int roll_no;
    char name[NAME_LENGTH]; 
    float marks;
};

// Function prototypes
void addStudents(struct Student studentArray[], int *count);
void displayStudents(const struct Student studentArray[], int count);
void searchStudent(const struct Student studentArray[], int count);

int main() {
    struct Student recordSystem[MAX_STUDENTS]; 
    int studentCount = 0;
    int choice;

    do {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add New Student(s)\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudents(recordSystem, &studentCount);
                break;
            case 2:
                displayStudents(recordSystem, studentCount);
                break;
            case 3:
                searchStudent(recordSystem, studentCount);
                break;
            case 4:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please select between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}


void addStudents(struct Student studentArray[], int *count) {
    int num, i;
    printf("\nHow many students do you want to add? ");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        if (*count >= MAX_STUDENTS) {
            printf("Database full! Cannot add more students.\n");
            return;
        }

        printf("\nEnter details for Student %d:\n", *count + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &studentArray[*count].roll_no);
        
        
        getchar(); 
        
        printf("Enter Name: ");
        fgets(studentArray[*count].name, NAME_LENGTH, stdin);
        
        studentArray[*count].name[strcspn(studentArray[*count].name, "\n")] = '\0';

        printf("Enter Marks: ");
        scanf("%f", &studentArray[*count].marks);

        (*count)++; 
    }
    printf("\nRecords added successfully!\n");
}


void displayStudents(const struct Student studentArray[], int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n-------------------------------------------------\n");
    printf("%-10s %-25s %-10s\n", "Roll No", "Name", "Marks");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-10.2f\n", 
               studentArray[i].roll_no, 
               studentArray[i].name, 
               studentArray[i].marks);
    }
    printf("-------------------------------------------------\n");
}


void searchStudent(const struct Student studentArray[], int count) {
    if (count == 0) {
        printf("\nNo student records available to search.\n");
        return;
    }

    int targetRoll, found = 0;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &targetRoll);

    for (int i = 0; i < count; i++) {
        if (studentArray[i].roll_no == targetRoll) {
            printf("\nStudent Found!\n");
            printf("Roll Number: %d\n", studentArray[i].roll_no);
            printf("Name       : %s\n", studentArray[i].name);
            printf("Marks      : %.2f\n", studentArray[i].marks);
            found = 1;
            break; 
    }

    if (!found) {
        printf("\nStudent with Roll Number %d not found.\n", targetRoll);
    }
}
