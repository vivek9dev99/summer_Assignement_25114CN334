//wap to count words in a sentence
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[1000];
    int i = 0;
    int words = 0;
    int in_word = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {
        if (isspace((unsigned char)str[i])) {
            in_word = 0;
        } else if (in_word == 0) {
            in_word = 1;
            words++;
        }
        i++;
    }

    printf("Total number of words: %d\n", words);

    return 0;
}
