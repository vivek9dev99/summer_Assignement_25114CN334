//wap to remove space from string 
#include <stdio.h>

void remove_spaces(char *str) {
    int i = 0;
    int j = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char str[] = "Hello World From C";
    remove_spaces(str);
    printf("%s\n", str);
    return 0;
}
