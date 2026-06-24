//wap to check string rotations
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool areRotations(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2) {
        return false;
    }

    char *temp = (char *)malloc(sizeof(char) * (len1 * 2 + 1));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return false;
    }
    strcpy(temp, str1);
    strcat(temp, str1);
    bool result = (strstr(temp, str2) != NULL);

    free(temp);

    return result;
}

int main() {
    char str1[] = "ABCD";
    char str2[] = "CDAB";

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);

    if (areRotations(str1, str2)) {
        printf("Result: Yes, the strings are rotations of each other.\n");
    } else {
        printf("Result: No, the strings are not rotations of each other.\n");
    }

    return 0;
}

