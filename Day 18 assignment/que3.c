//wap to binary search
#include <stdio.h>

int binarySearch(int array[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == target) {
            return mid; 
        }

        if (array[mid] < target) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    return -1;
}
int main() {
    int n, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter %d integers (in sorted ascending order):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the value to search for: ");
    scanf("%d", &target);

    int result = binarySearch(array, n, target);

    if (result == -1) {
        printf("Element %d is not present in the array.\n", target);
    } else {
        printf("Element %d found at index position %d.\n", target, result);
    }

    return 0;
}

