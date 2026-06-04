#include<stdio.h>
int main(){
    int start, end, i, temp, d, digits;
    double sum;
    printf("Enter the start and end of the range: ");
    if (scanf("%d %d", &start, &end) != 2) {
        printf("Invalid input. Please enter two integers.\n");
        return 1;
    }
    if (start > end) {
        temp = start;
        start = end;
        end = temp;
    }
    printf("Armstrong numbers between %d and %d are:\n", start, end);
    for (i = start; i <= end; i++) {
        temp = i;
        digits = 0;
        sum = 0.0;
        if (temp == 0) {
            digits = 1;
        } 
        while (temp != 0) {
            digits++;
            temp /= 10;
        }
        temp = i;
        while (temp != 0) {
            d = temp % 10;
            sum += pow(d, digits);
            temp /= 10;
        }
        if ((int)sum == i) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}