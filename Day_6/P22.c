#include <stdio.h>

int main() {
    long long binary;
    int decimal = 0, base = 1, remainder;
    printf("Enter a binary number (e.g., 1101): ");
    scanf("%lld", &binary);

    long long temp = binary;

    // Conversion process loop
    while (binary > 0) {
        remainder = binary % 10;   
        decimal += remainder * base; 
        base = base * 2;           
        binary = binary / 10;      
    }
    printf("%lld in binary = %d in decimal\n", temp, decimal);

    return 0;
}