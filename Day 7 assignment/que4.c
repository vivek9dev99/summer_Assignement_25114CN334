//wap to recursive reverse number
#include <stdio.h>
int reverse_number(int num, int reversed) {
    if (num == 0) {
        return reversed;
    }
    reversed = (reversed * 10) + (num % 10);
    return reverse_number(num / 10, reversed);
}
int main() {
    int num, result;

    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    result = reverse_number(num, 0);

    printf("Reversed number: %d\n", result);

    return 0;
}
