//wap to count even and odd elements
#include <stdio.h>
int main() {
    int size, i;
    int even_count = 0;
    int odd_count = 0;
    printf("Enter the number of elements:");
    scanf("%d",&size);
    int arr[size];
    printf("Enter %d elements:\n", size);
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < size; i++) {
        if(arr[i] % 2 == 0) {
            even_count++;
        } 
        else {
        odd_count++;
        }
    }
    printf("\nTotal Even elements:%d",even_count);
printf("\nTotal Odd elements:%d\n",odd_count);
    return 0;
}

