#include <stdio.h>
int main() {
    int rows, cols, i, j;
    int isSymmetric = 1; 

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows != cols) {
        printf("The matrix is not a square matrix, so it cannot be symmetric.\n");
        return 0; 
    }

    int matrix[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }


    for (i = 0; i < rows; i++) {
        for (j = 0; j < i; j++) { 
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric) {
            break; 
        }
    }
    if (isSymmetric == 1) {
        printf("\nThe given matrix is a Symmetric Matrix.\n");
    } else {
        printf("\nThe given matrix is NOT a Symmetric Matrix.\n");
    }

    return 0;
}
