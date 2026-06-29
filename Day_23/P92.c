#include <stdio.h>
#include <string.h>

#define MAX_STATUS 256

int main() {
    char str[100];
    int freq[MAX_STATUS] = {0}; 
    int max_count = 0;
    char max_char = ' ';

    printf("Enter a string: ");
    
    fgets(str, sizeof(str), stdin);

    
    for (int i = 0; str[i] != '\0'; i++) {
        // Skip newline character added by fgets
        if (str[i] == '\n') continue; 
        
        freq[(unsigned char)str[i]]++;
    }

    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\n' && freq[(unsigned char)str[i]] > max_count) {
            max_count = freq[(unsigned char)str[i]];
            max_char = str[i];
        }
    }

    
    if (max_count > 0) {
        printf("Maximum occurring character: '%c' (Repeated %d times)\n", max_char, max_count);
    } else {
        printf("The string is empty.\n");
    }

    return 0;
}
