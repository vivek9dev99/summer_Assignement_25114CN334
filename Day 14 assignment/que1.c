//wap to find duplicate in array
#include <stdio.h>
int main() {
 int arr[100];
int size;
int is_duplicate;
    printf("Enter size of the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
     printf("Invalid size.\n");
    return 1;
    }
    printf("Enter %d elements in the array:\n", size);
    for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
    }
    printf("\nDuplicate elements in the array are:\n");
    for (int i = 0; i < size; i++) {
     is_duplicate = 0;
    for (int k = 0; k < i; k++) {
    if (arr[i] == arr[k]) {
    is_duplicate = 1;
     break;
    }
        }
    if (!is_duplicate) {
     for (int j = i + 1; j < size; j++) {
    if (arr[i] == arr[j]) {
   printf("%d ", arr[i]);
 break;
     }
    }
    }
    }
    printf("\n");
    return 0;
}
