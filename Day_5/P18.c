#include<stdio.h>
int main()
{
    int n, originalNum, lastDigit, sum = 0;
    long long fact;
    printf("Enter any number to check:");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1; 
    }
    originalNum = n;

    if (n <= 0) {
        printf("%d is Not a Strong Number.\n", originalNum);
        return 0;
    }
    while (n > 0){
        lastDigit = n % 10;
        fact = 1;
        for (int i = 1; i <= lastDigit; i++) {
            fact *= i;
        }
        sum += fact;
        n /= 10;
    }
    if (sum == originalNum){
        printf("%d is a Strong Number.\n", originalNum);
    }
    else{
        printf("%d is Not a Strong Number.\n", originalNum);
    }
    return 0;
}