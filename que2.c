// wap to print prime no. in a range
#include<stdio.h>
int main(){

int n,i,count=0;
printf("enetr the range r1-r2:");
scanf("%d",&n);
if(n<=1)
{printf("no. is not prime");
}
for(n=2;i=n/2;i++)
{if(n%i==0)
{count++;
break;
}}
if(count==0)
printf("%d is prime number",n);
else
{
    printf("%d is not prime number");
}
return 0;

}
