//wap to union of array
#include <stdio.h>
void printArray(int arr[], int size) {
 for (int i = 0; i < size; i++) {
 printf("%d ", arr[i]);
    }
 printf("\n");
}
int main() {
 int arr1[] = {1, 2, 3, 4, 6};
 int arr2[] = {1, 2, 5, 6, 7};
 int size1 = sizeof(arr1) / sizeof(arr1[0]);
 int size2 = sizeof(arr2) / sizeof(arr2[0]);
 int unionArr[size1 + size2]; 
 int unionSize = 0;
    for (int i = 0; i < size1; i++) {
      int isDuplicate = 0;
     for (int j = 0; j < unionSize; j++) {
      if (unionArr[j] == arr1[i]) {
     isDuplicate = 1;
     break;
         }
     }
     if (!isDuplicate) {
     unionArr[unionSize] = arr1[i];
     unionSize++;
        }
    }
    for (int i = 0; i < size2; i++) {
    int isDuplicate = 0;
    for (int j = 0; j < unionSize; j++) {
     if (unionArr[j] == arr2[i]) {
     isDuplicate = 1;
      break;
            }
        }
        if (!isDuplicate) {
            unionArr[unionSize] = arr2[i];
         unionSize++;
        }
    }
 
    printf("Array 1: ");
    printArray(arr1, size1);
    printf("Array 2: ");
    printArray(arr2, size2);
    printf("Union of both arrays: ");
    printArray(unionArr, unionSize);
    
    return 0;
}

