
#include <stdio.h>
#include <math.h>
int isArmstrong(int number) {
    int originalNumber, remainder, totalDigits = 0, totalSum = 0;
    originalNumber = number;
    while (originalNumber != 0) {
        originalNumber /= 10;
        totalDigits++;
    }
    originalNumber = number;
    while (originalNumber != 0) {
        remainder = originalNumber % 10;
        totalSum += round(pow(remainder, totalDigits)); 
        originalNumber /= 10;
    }
    if (totalSum == number)
        return 1;
    else
        return 0; 
}

int main() {
    int num = 153;
    if (isArmstrong(num)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }
    return 0;
}
