#include <stdio.h>
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    int visited[n]; 
    printf("Enter %d elements in the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; 
    }
    printf("Duplicate elements are: ");
    int found_duplicate = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) {
            continue;
        }
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1; 
            }
        }
        if (count > 1) {
            printf("%d ", arr[i]);
            found_duplicate = 1;
        }
    }

    if (!found_duplicate) {
        printf("None");
    }
    printf("\n");

    return 0;
}
