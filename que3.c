//wap to remove duplicate character
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void removeDuplicates(char *str) {
   
    bool seen[256] = {false};
    
    int readIndex = 0;
    int writeIndex = 0;

    
    while (str[readIndex] != '\0') {
        unsigned char ch = str[readIndex];

        if (!seen[ch]) {
            seen[ch] = true;
            str[writeIndex] = str[readIndex];
            writeIndex++;
        }
        readIndex++;
    }

    str[writeIndex] = '\0';
}

int main() {
 
    char str[] = "programming"; 
    
    printf("Original string: %s\n", str);
    
    removeDuplicates(str);
    
    printf("String after removing duplicates: %s\n", str);
    
    return 0;
}
