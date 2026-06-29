#include <stdio.h>
#include <string.h>
#include <ctype.h>

void find_longest_word(const char *sentence, char *longest_word) {
    int max_len = 0;
    int current_len = 0;
    int start_index = 0;
    int max_start_index = 0;
    
    for (int i = 0; sentence[i] != '\0'; i++) {
        
        if (!isspace((unsigned char)sentence[i]) && !ispunct((unsigned char)sentence[i])) {
            if (current_len == 0) {
                start_index = i; 
            }
            current_len++;
        } else {
            
            if (current_len > max_len) {
                max_len = current_len;
                max_start_index = start_index;
            }
            current_len = 0; 
        }
    }
    
    
    if (current_len > max_len) {
        max_len = current_len;
        max_start_index = start_index;
    }
    
    
    strncpy(longest_word, &sentence[max_start_index], max_len);
    longest_word[max_len] = '\0'; 
}

int main() {
    char sentence[256];
    char longest_word[256] = "";

    printf("Enter a sentence: ");
    
    if (fgets(sentence, sizeof(sentence), stdin)) {
        sentence[strcspn(sentence, "\n")] = '\0'; 

        find_longest_word(sentence, longest_word);

        if (strlen(longest_word) > 0) {
            printf("The longest word is: \"%s\"\n", longest_word);
            printf("Length: %lu\n", strlen(longest_word));
        } else {
            printf("No valid words found.\n");
        }
    }

    return 0;
}
