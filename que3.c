//wap to find pair with given sum
#include <stdio.h>
void findPairsWithSum(int arr[], int size, int targetSum) {
int found = 0;
    printf("Pairs with sum %d are:\n", targetSum);
    for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
    if (arr[i] + arr[j] == targetSum) {
    printf("(%d, %d)\n", arr[i], arr[j]);
    found = 1;
            }
        }
    }
    if (!found) {
     printf("No pairs found with the given sum.\n");
    }
}
int main() {
    int arr[] = {1, 5, 7, -1, 5, 3, 3};
    int C = 6;
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Array: ");
    for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
    }
    printf("\nTarget Sum (C): %d\n\n", C);
    findPairsWithSum(arr, size, C);
    return 0;
}
