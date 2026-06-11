//wap to print armstrong number in a range
#include <stdio.h>
#include <math.h>

int main() {
    int start, end, i, temp, remainder, digits;
    double sum;
    printf("Enter the starting and ending numbers of the range: ");
    scanf("%d %d", &start, &end);
    if (start > end) {
        temp = start;
        start = end;
        end = temp;
    }
    printf("Armstrong numbers between %d and %d are:\n", start, end);
    for (i = start; i <= end; i++) {
        if (i < 0) {
            continue;
        }

        temp = i;
        digits = 0;
        sum = 0.0;
        while (temp != 0) {
            temp /= 10;
            digits++;
        }
        temp = i;
        while (temp != 0) {
            remainder = temp % 10;
            sum += round(pow(remainder, digits)); 
            temp /= 10;
        }
        if ((int)sum == i) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
