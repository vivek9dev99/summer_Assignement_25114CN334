//wap to remove duplicate character 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void find_longest_word(const char *str) {
    int max_len = 0;
    int current_len = 0;
    int max_start_index = 0;
    int current_start_index = 0;
    int i = 0;

    while (str[i] != '\0') {
  
        if (isalnum((unsigned char)str[i])) {
            if (current_len == 0) {
                current_start_index = i;
            }
            current_len++;
        } else {
            if (current_len > max_len) {
                max_len = current_len;
                max_start_index = current_start_index;
            }
            current_len = 0; 
        }
        i++;
    }
    if (current_len > max_len) {
        max_len = current_len;
        max_start_index = current_start_index;
    }

   
    if (max_len > 0) {
        printf("Longest word: ");
        for (int j = 0; j < max_len; j++) {
            putchar(str[max_start_index + j]);
        }
        printf("\nLength: %d\n", max_len);
    } else {
        printf("No valid words found.\n");
    }
}

int main() {
    char sentence[256];

    printf("Enter a sentence: ");
   
    if (fgets(sentence, sizeof(sentence), stdin) != NULL) {
    
        sentence[strcspn(sentence, "\n")] = '\0';
        
        find_longest_word(sentence);
    }

    return 0;
}
