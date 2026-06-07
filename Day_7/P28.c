#include <stdio.h>
int reverse_recursive(int num, int accumulated) {
    if (num == 0) {
        return accumulated;
    }
    int last_digit = num % 10;
    accumulated = (accumulated * 10) + last_digit;
    return reverse_recursive(num / 10, accumulated);
}
int reverse(int num) {
    return reverse_recursive(num, 0);
}

int main() {
    int number;
    
    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    
    int result = reverse(number);
    printf("Reversed number: %d\n", result);
    
    return 0;
}