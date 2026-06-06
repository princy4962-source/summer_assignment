#include <stdio.h>

int main() {
    double base, result = 1.0;
    int exponent, i;
    int is_negative = 0;
    printf("Enter base (x): ");
    scanf("%lf", &base);
    printf("Enter exponent (n): ");
    scanf("%d", &exponent);
    int original_exponent = exponent;
    if (exponent < 0) {
        is_negative = 1;
        exponent = -exponent; 
    }
    for (i = 1; i <= exponent; i++) {
        result *= base;
    }
    if (is_negative) {
        result = 1.0 / result;
    }
    printf("%.2lf^%d = %.6lf\n", base, original_exponent, result);

    return 0;
}