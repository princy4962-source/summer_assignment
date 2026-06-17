#include <stdio.h>

int isDuplicate(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1; // Found a duplicate
        }
    }
    return 0; 
}

int findIntersection(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int k = 0; 
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                
                if (!isDuplicate(result, k, arr1[i])) {
                    result[k] = arr1[i];
                    k++;
                }
                break; 
            }
        }
    }
    return k;
}

int main() {
    int arr1[] = {4, 9, 5, 4};
    int arr2[] = {9, 4, 9, 8, 4};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int minSize = (size1 < size2) ? size1 : size2;
    int result[minSize];

    int intersectionSize = findIntersection(arr1, size1, arr2, size2, result);

    printf("Intersection of the two arrays: ");
    if (intersectionSize == 0) {
        printf("No common elements found.");
    } else {
        for (int i = 0; i < intersectionSize; i++) {
            printf("%d ", result[i]);
        }
    }
    printf("\n");

    return 0;
}
