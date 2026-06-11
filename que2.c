// wap to print multiplication table of given number
#include<stdio.h>
int main()
{
    int n ,i;
    printf("enetr the number");
    scanf("%d",&n);
    printf("\nmultiplication table of %d:\n",n);

    for(i=1;i<=10;i++)
    {
        printf("%d*%d=%d",n,i,n*i);
    }
return 0;
}










