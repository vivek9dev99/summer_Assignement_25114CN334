//wap to findsum of first n naturak number
#include<stdio.h>
int main()
{
    int n, sum=0,i;
    printf("enter the number");
    scanf("%d",&n);
    for( i=1;i<=n;i++)
    {
        sum+=i;
    }
    printf("sum of first %d natural number=%d\n",n,sum);
    return 0;
}
 
