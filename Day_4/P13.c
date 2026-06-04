#include<stdio.h>
int terms;
unsigned long long first = 0, second = 1, next;
int main()
{
    printf("Enter the number of terms:");
    scanf("%d", &terms);
    printf("Fibonacci series:");
    for (int i = 1; i<=terms; ++i){
        printf("%llu ", first);
        next = first + second;
        first = second;
        second = next;
    }
    printf("\n");
    return 0;
}