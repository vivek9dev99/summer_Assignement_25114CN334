//wap to Find sum of didgit of number
#include<stdio.h>
int main()
{
    int n, sum=0,r;
    printf("enetr the number");
    scanf("%d",&n);
    while(n>0)
    {
    r=n%10;
    sum=sum+r;
    n=n/10;}

printf("the  sum of digit is %d",sum);
return 0;


}
