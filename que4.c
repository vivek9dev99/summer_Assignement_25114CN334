//wap to move zeroes to end 
#include <stdio.h>
void moveZeroesToEnd(int arr[], int size) {
    int nonZeroIndex = 0;
    for (int i = 0; i < size; i++) {
    if (arr[i] != 0) {
     arr[nonZeroIndex] = arr[i];
    nonZeroIndex++; }
    }
    while (nonZeroIndex < size) {
     arr[nonZeroIndex] = 0;
     nonZeroIndex++;}
}
void printArray(int arr[], int size) {
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
 }
 printf("\n");
}
int main() {
    int arr[] = {1, 0, 4, 3, 0, 0, 9, 8, 0, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, size);

    moveZeroesToEnd(arr, size);

    printf("Modified array: \n");
    printArray(arr, size);

    return 0;
}
