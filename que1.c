//wap to genrate fibonacci series 
#include<stdio.h>
int main()
{
    int i,n ,firstnum=0,secondnum=1,next;
    printf("enter the number of terms:");
    scanf("%d",&n);
    
    for(i=1;i<=n;i++)
    {
        printf("%d", firstnum);
        next=firstnum+secondnum;
        firstnum=secondnum;
        secondnum=next;

    }
    return 0;

}