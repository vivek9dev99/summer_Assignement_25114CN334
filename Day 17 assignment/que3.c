//wap to intersection of array
#include <stdio.h>
int isDuplicate(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1; 
        }
    }
    return 0; 
}
int main() {
    int size1, size2;
    int arr1[100], arr2[100], intersection[100];
    int k = 0;
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &size1);
    printf("Enter %d elements for the first array:\n", size1);
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &size2);
    printf("Enter %d elements for the second array:\n", size2);
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }
    for (int i = 0; i < size1; i++) {
      for (int j = 0; j < size2; j++) {
     if (arr1[i] == arr2[j]) {
    if (!isDuplicate(intersection, k, arr1[i])) {
     intersection[k] = arr1[i];
     k++;
             }
    break;
            }
        }
    }
    if (k > 0) {
        printf("\nIntersection of the two arrays is: ");
        for (int i = 0; i < k; i++) {
            printf("%d ", intersection[i]);
        }
        printf("\n");
    } else {
        printf("\nNo common elements found (Intersection is empty).\n");
    }

    return 0;
}
