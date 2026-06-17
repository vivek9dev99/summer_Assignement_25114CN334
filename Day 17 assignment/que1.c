//wap to merge array
#include <stdio.h>

int main() {
    int n1, n2, n3;
    int arr1[100], arr2[100], mergedArr[200];
    int i, j;
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    printf("Enter %d elements for the first array:\n", n1);
    for (i = 0; i < n1; i++) {
    scanf("%d", &arr1[i]);
    }
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    printf("Enter %d elements for the second array:\n", n2);
    for (i = 0; i < n2; i++) {
     scanf("%d", &arr2[i]);
    }
    for (i = 0; i < n1; i++) {
    mergedArr[i] = arr1[i];
    }
    n3 = n1 + n2; 
    for (i = 0, j = n1; j < n3 && i < n2; i++, j++) {
     mergedArr[j] = arr2[i];
    }
    printf("\nThe merged array elements are:\n");
    for (i = 0; i < n3; i++) {
     printf("%d ", mergedArr[i]);
    }
    printf("\n");
    return 0;
}
