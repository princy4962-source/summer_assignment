#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void removeDuplicates(char* str) {
    
    bool seen[256] = { false };
    
    int writeIndex = 0;
    int readIndex = 0;
    
    
    while (str[readIndex] != '\0') {
        unsigned char ch = str[readIndex];
        
        
        if (!seen[ch]) {
            seen[ch] = true;       
            str[writeIndex] = ch; 
            writeIndex++;         
        }
        readIndex++; 
    }
    
   
    str[writeIndex] = '\0';
}

int main() {
    
    char str[100];
    
    printf("Enter a string: ");
    
    scanf("%[^\n]", str);
    
    removeDuplicates(str);
    
    printf("String after removing duplicates: %s\n", str);
    
    return 0;
}
