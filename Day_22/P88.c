#include <stdio.h>

void removeSpaces(char *str) {
    int readIndex = 0;
    int writeIndex = 0;

    
    while (str[readIndex] != '\0') {
    
        if (str[readIndex] != ' ') {
            str[writeIndex] = str[readIndex];
            writeIndex++;
        }
        readIndex++;
    }
    
    
    str[writeIndex] = '\0';
}

int main() {
    char text[100];

    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '\n') {
            text[i] = '\0';
            break;
        }
    }

    printf("Original string: [%s]\n", text);
    

    removeSpaces(text);

    printf("Resulting string: [%s]\n", text);

    return 0;
}
