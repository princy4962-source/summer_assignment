#include<stdio.h>
int main(){
    int n, rev=0, d;
    printf("Enter an integer:\n");
    scanf("%d", &n);
    while(n!=0){
        d = n%10;
        rev = rev*10 +d;
        n /= 10;
    }
    printf("Reversed number = %d", rev);
    return 0;
}