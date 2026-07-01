#include<stdio.h>
#include<string.h>
int main(){
    int i, j, n;
    char names[20][50];
    char temp[50];
printf("Enter the number of names: ");
    scanf("%d", &n);
    getchar();
    printf("Enter the names:\n", n);
    for(i=0; i<n; i++){
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = 0; 
    }
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(strcmp(names[j], names[j+1]) > 0){
                strcpy(temp, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], temp);
            }
        }
    }
    printf("Sorted names:\n");
    for(i=0; i<n; i++){
        printf("%s\n", names[i]);
    }
    return 0;
}