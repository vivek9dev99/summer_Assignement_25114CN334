//wap to find missing number in array
#include <stdio.h>
int findMissingNumber(int arr[], int size) {
    int xor_elements = 0;
    int xor_all = 0;
    for (int i = 0; i < size; i++) {
        xor_elements ^= arr[i];
    }
    for (int i = 1; i <= size + 1; i++) {
     xor_all ^= i;
    }
    return xor_elements ^ xor_all;
}
int main() {
    int arr[] = {1, 2, 6, 3, 5}; 
    int size = sizeof(arr) / sizeof(arr[0]);
    int missing = findMissingNumber(arr, size);
    printf("The missing number is: %d\n", missing);
    return 0;
}


