#include <stdio.h>

int main() {
    int decimalNumber;
    int binaryArray[32];
    int index = 0;
    printf("Enter a positive decimal number: ");
    if (scanf("%d", &decimalNumber) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    if (decimalNumber == 0) {
        printf("Binary equivalent: 0\n");
        return 0;
    }

    while (decimalNumber > 0) {
        binaryArray[index] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        index++;
    }
    printf("Binary equivalent: ");
    for (int j = index - 1; j >= 0; j--) {
        printf("%d", binaryArray[j]);
    }
    printf("\n");

    return 0;
}