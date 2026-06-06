#include<stdio.h>
long long get_largest_prime_factor(long long n) {
    long long max_prime = -1;
    while (n % 2 == 0) {
        max_prime = 2;
        n /= 2;
    }
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            max_prime = i;
            n /= i;
        }
    }
    if (n > 2) {
        max_prime = n;
    }
    return max_prime;
}
int main() {
    long long n;
    printf("Enter a positive integer: ");
    if (scanf("%lld", &n) != 1 || n <= 1) {
        printf("please enter a valid integer greater than 1.\n");
        return 1;
    }
    long long result = get_largest_prime_factor(n);
    printf("The largest prime factor of %lld is: %lld\n", n, result);
    return 0;
}