//wap to substract matrices
#include <stdio.h>

int main() {
    int r, c, i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int a[r][c], b[r][c], res[r][c];

    printf("Enter matrix A:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) scanf("%d", &a[i][j]);

    printf("Enter matrix B:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) scanf("%d", &b[i][j]);
    printf("\nResultant Matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            res[i][j] = a[i][j] - b[i][j];
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
