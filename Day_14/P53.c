#include <stdio.h>
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; 
}
int main() {
    int n, key, result;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n]; 
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &key);
    result = linearSearch(arr, n, key);
    if (result != -1) {
        printf("Element %d found at index %d (Position %d).\n", key, result, result + 1);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
