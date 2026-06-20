//wap to find column wise sum
#include <stdio.h>

int main() {
    int rows, cols;
    int matrix[100][100];
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("\nEnter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\n--- Column-wise Sum ---\n");
    for (int j = 0; j < cols; j++) {
        int colSum = 0; 
        for (int i = 0; i < rows; i++) {
            colSum += matrix[i][j]; 
        }
        printf("Sum of Column %d = %d\n", j + 1, colSum);
    }

    return 0;
}
