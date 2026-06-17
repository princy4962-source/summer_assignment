#include <stdio.h>

int isDuplicate(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1; 
        }
    }
    return 0; 
}

int main() {

    int arr1[] = {1, 3, 5, 7, 9, 3};
    int arr2[] = {2, 3, 5, 6, 8, 9, 10};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int unionArr[size1 + size2];
    int unionSize = 0;

    for (int i = 0; i < size1; i++) {
        if (!isDuplicate(unionArr, unionSize, arr1[i])) {
            unionArr[unionSize] = arr1[i];
            unionSize++;
        }
    }

    for (int i = 0; i < size2; i++) {
        if (!isDuplicate(unionArr, unionSize, arr2[i])) {
            unionArr[unionSize] = arr2[i];
            unionSize++;
        }
    }

    printf("Union of the two arrays: ");
    for (int i = 0; i < unionSize; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");

    return 0;
}
