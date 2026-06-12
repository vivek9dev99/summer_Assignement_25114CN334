//wap to write function for fibonacci
#include <stdio.h>
void printFibonacci(int n) {
    int first = 0, second = 1, next;

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
     if (i <= 1) {
         next = i;
        } else {
      next = first + second;
      first = second;
      second = next;}
 printf("%d ", next);
}
 printf("\n");
}
int main() {
    int terms = 10;
    printFibonacci(terms);
    return 0;
}
