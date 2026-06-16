#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void findPairTwoPointer(int arr[], int size, int targetSum) {
    qsort(arr, size, sizeof(int), compare);

    int left = 0;
    int right = size - 1;
    int found = 0;
    while (left < right) {
        int currentSum = arr[left] + arr[right];

        if (currentSum == targetSum) {
            printf("Pair found: %d and %d\n", arr[left], arr[right]);
            found = 1;
            left++;  
            right--;
        } 
        else if (currentSum < targetSum) {
            left++;  
        } 
        else {
            right--;  
        }
    }

    if (!found) {
        printf("No pair found with the given sum.\n");
    }
}

int main() {
    int arr[] = {8, 7, 2, 5, 3, 1};
    int targetSum = 10;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Searching using Two-Pointer Approach:\n");
    findPairTwoPointer(arr, size, targetSum);

    return 0;
}
