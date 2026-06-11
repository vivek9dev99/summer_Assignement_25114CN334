// wap to find product of digits
#include<stdio.h>
int main ()
{
    int n, rem=1,k;
    printf("enter the number");
    scanf("%d",&n);
    while(n>0){
        k=n%10;
        rem=rem*k;
        n=n/10;

    }
    printf("product of digit is %d",rem);
    return 0;
}
