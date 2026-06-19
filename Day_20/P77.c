#include <stdio.h>

#define ROW1 2  
#define COL1 3  
#define COL2 2  

int main() {
    int i, j, k;
    int mat1[ROW1][COL1] = { {1, 2, 3}, {4, 5, 6} };
    int mat2[COL1][COL2] = { {7, 8}, {9, 10}, {11, 12} };
    int result[ROW1][COL2] = {0}; 

    for (i = 0; i < ROW1; i++) {
        for (j = 0; j < COL2; j++) {
            for (k = 0; k < COL1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printf("Resultant Matrix:\n");
    for (i = 0; i < ROW1; i++) {
        for (j = 0; j < COL2; j++) {
            printf("%d \t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}