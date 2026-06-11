//wap to Reverse a number
#include<stdio.h>
int main()
{
    int n,r, reverse=0;
    printf("enter the number");
    scanf("%d",&n);
    while(n>0)
{
    r=n%10;
    reverse=reverse*10+r;
    n=n/10;
}
printf("reverse=%d\n",reverse);
return 0;
}