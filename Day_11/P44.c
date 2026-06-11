#include <stdio.h>
unsigned long long findFactorialIterative(int n);

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Error: Factorial of a negative number doesn't exist.\n");
    } else {
        unsigned long long result = findFactorialIterative(num);
        printf("Factorial of %d = %llu\n", num, result);
    }
    return 0;
}
unsigned long long findFactorialIterative(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}