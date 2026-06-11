//wap to check atmstrong number
  #include<stdio.h>
  #include<math.h>
  int main()
  {
    int n,sum=0,r,count=0;
    int temp1, temp2;
    printf("enter a no.");
    scanf("%d",&n);
    temp1=n;
    temp2=n;
    while(temp1>0)
    {
        temp1=temp1/10;
        count++;

    }
    while(temp2>0)
    {
        r=temp2%10;
        sum=sum+round(pow(r,count));
        temp2=temp2/10;
    }
    if(sum==n)
    {printf("%d is armstrong number.\n",n);}
    else
    {printf("%d is not armstrong number.\n",n);}
    return 0;
  }
