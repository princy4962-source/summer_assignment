#include <stdio.h>
int countSetBits(unsigned int num) {
    int count = 0;
    
    while (num > 0) {
        num &= (num - 1); 
        count++;
    }
    
    return count;
}

int main() {
    unsigned int number;
    printf("Enter an unsigned integer: ");
    if (scanf("%u", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    int result = countSetBits(number);
    printf("The number of set bits in %u is: %d\n", number, result);

    return 0;
}