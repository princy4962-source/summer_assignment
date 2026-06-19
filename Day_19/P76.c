#include <stdio.h>

int main() {
    int size;
    int primary_sum = 0;
    int secondary_sum = 0;

    printf("Enter the size of the square matrix (N x N): ");
    scanf("%d", &size);

    int matrix[size][size];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < size; i++) {
        primary_sum += matrix[i][i];                 
        secondary_sum += matrix[i][size - i - 1];    
    }
    printf("\n--- Result ---\n");
    printf("Sum of Primary Diagonal: %d\n", primary_sum);
    printf("Sum of Secondary Diagonal: %d\n", secondary_sum);

    return 0;
}