//wap to check symmeetric matrices
#include <stdio.h>

int main() {
    int rows, cols;
    int isSymmetric = 1;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    if (rows != cols) {
        printf("The matrix is not square, so it cannot be symmetric.\n");
        return 0;
    }

    int matrix[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric) {
            break;
    }
    if (isSymmetric) {
        printf("The given matrix is a Symmetric Matrix.\n");
    } else {
        printf("The given matrix is NOT a Symmetric Matrix.\n");
    }

    return 0;
}
