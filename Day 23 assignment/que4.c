//wap to find maximum occuring character
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100 
#define ASCII_SIZE 256 

int main() {
    char str[MAX_SIZE];
    int freq[ASCII_SIZE] = {0}; 
    int i, max_index;

    printf("Enter any string: ");
    fgets(str, sizeof(str), stdin);

    
    str[strcspn(str, "\n")] = '\0';
    for (i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
    max_index = 0;
    for (i = 0; i < ASCII_SIZE; i++) {

        if (freq[i] > freq[max_index]) {
            max_index = i;
        }
    }
    if (freq[max_index] > 0) {
        printf("The maximum occurring character is '%c' and it appears %d times.\n", max_index, freq[max_index]);
    } else {
        printf("The string is empty.\n");
    }

    return 0;
}
