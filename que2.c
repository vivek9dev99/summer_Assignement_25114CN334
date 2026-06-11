
#include<stdio.h>
int main()
{
    int i,n ,firstnum=0,secondnum=1,next;
    printf("enter the number of terms:");
    scanf("%d",&n);
    
    for(i=1;i<n;i++)
    {
        
        next=firstnum+secondnum;
        firstnum=secondnum;
        secondnum=next;


    }
    printf("Nth term=%d",firstnum);
    return 0;

}