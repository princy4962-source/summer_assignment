#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char str1[100], str2[100], temp[100];
    int choice;

    while (1) {
        // Display Menu System
        printf("\n=================================");
        printf("\n   STRING OPERATIONS SYSTEM Menu  ");
        printf("\n=================================");
        printf("\n1. Find Length of a String");
        printf("\n2. Copy a String");
        printf("\n3. Concatenate Two Strings");
        printf("\n4. Compare Two Strings");
        printf("\n5. Reverse a String");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid numeric format!\n");
            clearBuffer();
            continue;
        }
        clearBuffer(); 
        switch (choice) {
            case 1:
                printf("\nEnter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0'; 
                
                printf("Length of the string: %lu\n", strlen(str1));
                break;

            case 2:
                printf("\nEnter the source string to copy: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                
                strcpy(str2, str1);
                printf("Successfully copied! Target String: %s\n", str2);
                break;

            case 3:
                printf("\nEnter the first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                
                printf("Enter the second string to append: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';
                
                
                if (strlen(str1) + strlen(str2) < sizeof(str1)) {
                    strcat(str1, str2);
                    printf("Concatenated string result: %s\n", str1);
                } else {
                    printf("Error: Combined size exceeds memory limits!\n");
                }
                break;

            case 4:
                printf("\nEnter the first string to compare: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                
                printf("Enter the second string to compare: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';
                
                int compResult = strcmp(str1, str2);
                if (compResult == 0) {
                    printf("The strings match perfectly.\n");
                } else if (compResult > 0) {
                    printf("String 1 is lexicographically greater than String 2.\n");
                } else {
                    printf("String 2 is lexicographically greater than String 1.\n");
                }
                break;

            case 5:
                printf("\nEnter a string to reverse: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                
                int len = strlen(str1);
                for (int i = 0; i < len; i++) {
                    temp[i] = str1[len - 1 - i];
                }
                temp[len] = '\0'; 
                
                printf("Reversed string output: %s\n", temp);
                break;

            case 6:
                printf("\nExiting System. Have a great day!\n");
                exit(0);

            default:
                printf("\nInvalid option entry! Choose a digit between 1 and 6.\n");
        }
    }
    return 0;
}
