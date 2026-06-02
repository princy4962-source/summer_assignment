#include<stdio.h>
int main(){
    int n, d;
    long long prod =1;
    printf("Enter any integer:");
    scanf("%d", &n);
    if(n==0) {
        prod = 0;
    }
    if(n<0) {
        n = -n;
    }
    while(n>0){
        d = d%10;
        prod *=d;
        n /=10;
    }
    printf("Product of digits = %d\n", prod);
    return 0;
}