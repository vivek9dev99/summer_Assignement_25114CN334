//wap to multiply matrices
#include <stdio.h>

int main() {
    int r1, c1, r2, c2;

    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("\nError: Columns of first matrix must equal rows of second.\n");
        return 1;
    }

    int first[r1][c1], second[r2][c2], result[r1][c2];

    printf("\nEnter elements of matrix 1:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++) scanf("%d", &first[i][j]);

    printf("\nEnter elements of matrix 2:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++) scanf("%d", &second[i][j]);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }

    printf("\nResultant Matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) printf("%d\t", result[i][j]);
        printf("\n");
    }
    return 0;
}
