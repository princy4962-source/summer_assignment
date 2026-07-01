#include <stdio.h>
#include <string.h>

int main() {
   
    char words[5][20] = {"Elephant", "Cat", "Banana", "Dog", "Hi"};
    int n = 5;
    char temp[20];

    printf("Original words:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", words[i]);
    }
    printf("\n\n");

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
           
            if (strlen(words[j]) > strlen(words[j + 1])) {
                
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    printf("Words sorted by length:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;