//wap to check the number is palidrome or not 
#include<stdio.h>
int main()
{
    int n,r, reverse=0,original;
    printf("enter the number");
    scanf("%d",&n);
    original=n;
    while(n>0)
{
    r=n%10;
    reverse=reverse*10+r;
    n=n/10;
}
printf("reverse=%d\n",reverse);
if(original==reverse)
printf("number is pallidrome");
else
printf("number is not pallidrome");
return 0;
}
