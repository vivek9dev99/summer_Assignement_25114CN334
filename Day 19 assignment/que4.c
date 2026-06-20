//wap to find diagonal sum
#include <stdio.h>

int main() {
    int n, i, j;
    int primary_sum = 0, secondary_sum = 0;
    int matrix[10][10];

    printf("Enter the size of the square matrix (max 10): ");
    scanf("%d", &n);

    printf("Enter elements of the matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
  
      primary_sum += matrix[i][i];
    }
    if (n % 2 == 1) {
        int center_val = matrix[n / 2][n / 2];
        printf("Center element is counted twice, adjusting...\n");
        primary_sum -= center_val; 
        secondary_sum -= center_val; 
    }

    int total_diagonal_sum = primary_sum + secondary_sum;

    printf("Primary Diagonal Sum: %d\n", primary_sum);
    printf("Secondary Diagonal Sum: %d\n", secondary_sum);
    printf("Total Unique Diagonal Sum: %d\n", total_diagonal_sum);

    return 0;
}
