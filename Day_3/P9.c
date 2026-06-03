#include<stdio.h>
int isPrime(int n){
    if(n<=1){
        return 0;
    }
    for(int i =2; i*i<=n; i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int beg, end;
     printf("Enter the starting number:");
     scanf("%d", &beg);
     printf("Enter the ending number:");
     scanf("%d", &end);
     printf("Prime numbers between %d are:\n", beg, end);
     for(int i=beg; i<=end; i++){
        if(isPrime(i)) {
            printf("%d", i);
        }
     }
     printf("\n");
     return 0;
}