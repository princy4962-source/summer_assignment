#include <stdio.h>
int findSum(int num1, int num2);
int main() {
    int number1, number2, totalSum;
    printf("Enter first number: ");
    scanf("%d", &number1);
    printf("Enter second number: ");
    scanf("%d", &number2);
    totalSum = findSum(number1, number2);
    printf("The sum of %d and %d is: %d\n", number1, number2, totalSum);
    return 0;
}
int findSum(int num1, int num2) {
    return num1 + num2;
}