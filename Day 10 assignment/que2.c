//wap  to Print reverse pyramid.
#include <stdio.h>

int main() {
    int rows = 5;
    int i, j;
    for (i = rows; i >= 1; i--) {
        for (j = 0; j < rows - i; j++) {
            printf(" ");
        }
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
