//wap to check to compress a string 
#include <stdio.h>
#include <string.h>

// Function to compress the string
void compressString(const char *src, char *dest) {
    int srcLen = strlen(src);
    
    // If the input string is empty, create an empty destination string
    if (srcLen == 0) {
        dest[0] = '\0';
        return;
    }

    int destIdx = 0; // Pointer index for destination string

    for (int i = 0; i < srcLen; i++) {
        int count = 1;

        // Count consecutive occurrences of the same character
        while (i + 1 < srcLen && src[i] == src[i + 1]) {
            count++;
            i++;
        }

        // Write character to destination
        dest[destIdx++] = src[i];

        // Convert the integer count into characters and append them
        // sprintf handles counts with multiple digits (e.g., 10 -> '1', '0')
        destIdx += sprintf(&dest[destIdx], "%d", count);
    }

    // Null-terminate the compressed string
    dest[destIdx] = '\0';
}

int main() {
    char inputString[100];
    
    printf("Enter a string to compress (no spaces): ");
    // Safely read the string from user input
    scanf("%99s", inputString);

    // Create a destination buffer twice the size to prevent any potential overflow
    char compressedString[200]; 

    // Compress the string
    compressString(inputString, compressedString);

    // Print result
    printf("Original String  : %s\n", inputString);
    printf("Compressed String: %s\n", compressedString);

    return 0;
}
