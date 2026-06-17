#include <stdio.h>

int isDuplicate(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1; 
        }
    }
    return 0;
}

int main() {
    int arr1[] = {1, 2, 4, 5, 6, 2};
    int arr2[] = {2, 3, 5, 7, 2, 9};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    
    int common[size1]; 
    int k = 0; 

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {

            if (arr1[i] == arr2[j]) {
            
                if (!isDuplicate(common, k, arr1[i])) {
                    common[k] = arr1[i];
                    k++;
                }
                break; 
            }
        }
    }

    if (k > 0) {
        printf("Common elements are: ");
        for (int i = 0; i < k; i++) {
            printf("%d ", common[i]);
        }
        printf("\n");
    } else {
        printf("No common elements found.\n");
    }

    return 0;
}
