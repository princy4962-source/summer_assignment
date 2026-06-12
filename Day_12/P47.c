#include <stdio.h>
int getFibonacciRecursive(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return getFibonacciRecursive(n - 1) + getFibonacciRecursive(n - 2);
}

int main() {
    int terms;

    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    if (terms <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("Fibonacci Series: ");
        for (int i = 0; i < terms; i++) {
            printf("%d ", getFibonacciRecursive(i));
        }
        printf("\n");
    }

    return 0;
}