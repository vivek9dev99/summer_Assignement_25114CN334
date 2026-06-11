//wap to convert binary to decimal
#include <stdio.h>
int main() {
    long long binary;
    int decimal = 0, base = 1, rem;
    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    long long temp = binary;
    while (temp > 0) {
        rem = temp % 10;       
        decimal += rem * base; 
        base = base * 2;       
        temp = temp / 10;      
    }
    printf("%lld in binary = %d in decimal\n", binary, decimal);
    return 0;
}
