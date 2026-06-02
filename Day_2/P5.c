#include<stdio.h>
int main(){
    int n, d, sum=0;
    printf("Enter the value of n:");
    scanf("%d",&n);
    int temp=n;
    while(n!=0){
        d=n%10;
        sum +=d;
        n /=10;
    }
    printf("The sum of the digits of %d = %d\n", temp, sum);
    return 0;
}