#include <stdio.h>
void moveZerosToEnd(int arr[], int size) {
    int count = 0; 
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[count] = arr[i];
            count++;
        }
    }
    while (count < size) {
        arr[count] = 0;
        count++;
    }
}

int main() {
    int arr[] = {1, 0, 4, 3, 0, 0, 7, 2, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    moveZerosToEnd(arr, size);

    printf("Modified array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}