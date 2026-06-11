//wap to check the number is prime or  not 
#include<stdio.h>
int main()
{
    int n,i, count=0;
    printf("enter the number:");
    scanf("%d",&n);
    if(n<=1);
    printf("no. is not prime");
    for(n=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            count++;
            break;
        }
    }
    if (count==0)
printf("%d is a prime number",n);
else
printf("%d is not prime number");
return 0;


}
