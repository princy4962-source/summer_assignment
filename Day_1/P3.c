#include<stdio.h>
int main(){
    int n, i, fact = 1;
    printf("Enter the value of n:\n");
    scanf("%d", &n);
    if(n<0) {
        printf("Factorial is not possible");
    }
    else{
        for(i=1; i<=n; i++){
            fact *= i;
        }
        printf("The value of factorial %d = %d",n , fact);
    }
    return 0;
}