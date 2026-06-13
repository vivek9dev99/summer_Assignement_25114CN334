//wap to input and display arry 
#include <stdio.h>
int main() {
    int arr[100];
    int size, i;
    printf("Enter the number of elements you want to store (max 100): ");
    scanf("%d", &size);
    printf("Enter %d elements:\n", size);
    for(i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nThe elements in your array are:\n");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
