#include <stdio.h>
#include <string.h>

void compressString(const char *src, char *dest) {
    int i = 0;
    int j = 0;
    int len = strlen(src);

    while (i < len) {
       
        dest[j++] = src[i];

        
        int count = 1;
        while (i + 1 < len && src[i] == src[i + 1]) {
            count++;
            i++;
        }

       
        j += sprintf(&dest[j], "%d", count);
        
        i++;
    }
    
    
    dest[j] = '\0';
}

int main() {
    char input[100];
    char compressed[200]; 

    printf("Enter a string to compress: ");
    
    scanf("%99[^\n]", input); 

    compressString(input, compressed);

    printf("Original String: %s\n", input);
    printf("Compressed String: %s\n", compressed);

    return 0;
}
