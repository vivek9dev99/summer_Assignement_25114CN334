//wap to find x^n without pow()
#include <stdio.h>
int main() {
    double base, result = 1.0;
    int exp, i;
    printf("Enter base (x): ");
    scanf("%lf", &base);
    printf("Enter exponent (n): ");
    scanf("%d", &exp);

    int original_exp = exp;
    int positive_exp = (exp < 0) ? -exp : exp;
    for (i = 0; i < positive_exp; i++) {
        result *= base;
    }
    if (original_exp < 0) {
        result = 1.0 / result;
    }
    printf("%.2lf raised to the power of %d is: %.6lf\n", base, original_exp, result);

    return 0;
}

