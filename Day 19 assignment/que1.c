//wap to add matrices
#include <stdio.h>

int main() {
    int r, c, i, j, m1[10][10], m2[10][10], sum[10][10];
    printf("Enter rows and columns (max 10): ");
    scanf("%d %d", &r, &c);

    printf("\nEnter 1st matrix elements:\n");
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            scanf("%d", &m1[i][j]);

    printf("Enter 2nd matrix elements:\n");
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            scanf("%d", &m2[i][j]);
    printf("\nSum:\n");
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            sum[i][j] = m1[i][j] + m2[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}

