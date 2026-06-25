//wap to find common character in string 
#include <stdio.h>
#include <string.h>

void findCommonCharacters(char str1[], char str2[]) {
  
    int presentInStr1[256] = {0};
    int printed[256] = {0};
    int found = 0;

    for (int i = 0; str1[i] != '\0'; i++) {
        presentInStr1[(unsigned char)str1[i]] = 1;
    }

    printf("Common characters: ");

    for (int i = 0; str2[i] != '\0'; i++) {
        unsigned char ch = str2[i];
        
        if (presentInStr1[ch] == 1 && printed[ch] == 0) {
            printf("%c ", ch);
            printed[ch] = 1; 
            found = 1;
        }
    }

    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    char str1[100];
    char str2[100];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
  
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    findCommonCharacters(str1, str2);

    return 0;
}
