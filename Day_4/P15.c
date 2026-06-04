#include<stdio.h>
int main(){
    int n, originalNum, remainder, digits = 0;
    double result = 0.0;
    printf("Enter an integer: ");
    scanf("%d", &n);
    originalNum = n;
    while (originalNum != 0) {
        originalNum /= 10;
        ++digits;
    }
    originalNum = n;
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, digits);
        originalNum /= 10;
    }
    if ((int)result == n)
        printf("%d is an Armstrong number.", n);
    else
        printf("%d is not an Armstrong number.", n);
    return 0;
}