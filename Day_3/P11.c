#include<stdio.h>
int GCD(inta, intb){
    int a, b;
    while(b!=0){
        int temp=b;
        b = a%b;
        a=temp;
    }
    return a;
}
int main(){
    int num1=48, num2=18;
    printf("The GCD of %D and %d is:%d\n", num1,num2,GCD(num1,num2));
    return 0;
}