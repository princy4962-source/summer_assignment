#include <stdio.h>
int main() {
    int arr[] = {2, 3, 2, 5, 3, 2, 8, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int visited[n]; 
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int max_element = arr[0];
    int max_count = 0;
    for(int i = 0; i < n; i++) {
        if(visited[i] == 1) {
            continue; 
        }

        int count = 1;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                visited[j] = 1; 
            }
        }
        if(count > max_count) {
            max_count = count;
            max_element = arr[i];
        }
    }
    printf("Element with maximum frequency: %d\n", max_element);
    printf("Frequency: %d times\n", max_count);

    return 0;
}
