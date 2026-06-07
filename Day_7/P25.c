#include <stdio.h>
unsigned long long factorial(int n);

int main() {
    int num;
    unsigned long long result;
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    if (num < 0) {
        printf("Error: Factorial of a negative number is not defined.\n");
    } else {
        result = factorial(num);
        printf("Factorial of %d = %llu\n", num, result);
    }

    return 0;
}
unsigned long long factorial(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}