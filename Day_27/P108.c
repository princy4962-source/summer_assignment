#include <stdio.h>
#include <string.h>


struct Student {
    int rollNo;
    char name[50];
    float marks[5];
    float total;
    float percentage;
    char division[20];
};

int main() {
    struct Student s;

    
    printf("--- Student Marksheet Generator ---\n");
    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);
    
    
    while (getchar() != '\n'); 

    printf("Enter Student Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    
    s.total = 0.0;
    for (int i = 0; i < 5; i++) {
        while (1) {
            printf("Enter marks for Subject %d (0-100): ", i + 1);
            scanf("%f", &s.marks[i]);
            if (s.marks[i] >= 0 && s.marks[i] <= 100) {
                s.total += s.marks[i];
                break;
            } else {
                printf("Invalid input! Marks must be between 0 and 100.\n");
            }
        }
    }

    
    s.percentage = (s.total / 500.0) * 100.0;

   
    if (s.percentage >= 60.0) {
        strcpy(s.division, "First Division");
    } else if (s.percentage >= 50.0) {
        strcpy(s.division, "Second Division");
    } else if (s.percentage >= 40.0) {
        strcpy(s.division, "Third Division");
    } else {
        strcpy(s.division, "Fail");
    }

    
    printf("\n\n========================================\n");
    printf("             STUDENT MARKSHAKE           \n");
    printf("========================================\n");
    printf("Roll No    : %d\n", s.rollNo);
    printf("Name       : %s\n", s.name);
    printf("----------------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d  : %.2f\n", i + 1, s.marks[i]);
    }
    printf("----------------------------------------\n");
    printf("Total      : %.2f / 500.00\n", s.total);
    printf("Percentage : %.2f%%\n", s.percentage);
    printf("Division   : %s\n", s.division);
    printf("========================================\n");

    return 0;
}
