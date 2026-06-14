//wap to second largest element
#include <stdio.h>
#include <limits.h>
int main() {
    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n < 2) {
    printf("Invalid input. At least 2 elements are required.\n");
    return 1;
    }
 int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int largest = INT_MIN;
    int second_largest = INT_MIN;
    for (int i = 0; i < n; i++) {
    if (arr[i] > largest) {
    second_largest = largest;
    largest = arr[i];
     } 
     else if (arr[i] > second_largest && arr[i] != largest) {
    second_largest = arr[i];
    }
    }
    if (second_largest == INT_MIN) {
        printf("There is no distinct second largest element.\n");
    } else 
    {
    printf("The largest element is: %d\n", largest);
    printf("The second largest element is: %d\n", second_largest);
    }
    return 0;
}
