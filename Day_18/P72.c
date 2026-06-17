#include <stdio.h>
int main() {
    int arr[100];
    int size, i, j, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
    
            if (arr[j] < arr[j + 1]) {
        
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nArray sorted in descending order:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}