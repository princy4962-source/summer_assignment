#include<stdio.h>
int main(){
    int n, rev=0, d,temp;
    printf("Enter an integer:");
    scanf("%d", &n);
    temp=n;
    while(n!=0){
        d = n%10;
        rev = rev*10+d;
        n /=10;
    }
    if(temp==rev){
        printf("%d is a plaindrome.\n", temp);
    }
        else{
        printf("%d is not a plaindrome.\n", temp);
        }
        return 0;
    
}