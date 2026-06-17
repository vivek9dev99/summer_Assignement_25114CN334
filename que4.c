//wap to find common element
#include <stdio.h>

int main() {
    int size1, size2;
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &size1);
    int arr1[size1];
    printf("Enter %d elements for the first array:\n", size1);
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &size2);
    int arr2[size2];
    printf("Enter %d elements for the second array:\n", size2);
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }
    printf("\nCommon elements are: ");
    int foundCommon = 0;
    for (int i = 0; i < size1; i++) {
     for (int j = 0; j < size2; j++) {
     if (arr1[i] == arr2[j]) {
            
 int isDuplicate = 0;
for (int k = 0; k < i; k++) {
if (arr1[i] == arr1[k]) {
 isDuplicate = 1;
 break;
     }
        }
         if (!isDuplicate) {
      printf("%d ", arr1[i]);
     foundCommon = 1;
                }
                break; 
            }
        }
    }
    if (!foundCommon) {
        printf("None");
    }
    printf("\n");
    return 0;
}

