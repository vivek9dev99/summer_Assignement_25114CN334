// wap to write function for palidrone 
#include<stdio.h>
int palindrome(int n)
{
    int rev=0,rem,temp=n;
    while(temp>0)
    {
        rem=temp%10;
        rev=rev*10+rem;
        temp=temp/10;}

        if(rev==n)
        return 1;
        else
        return 0;
}
    int main()
    {
        int num;
        printf("enter a number:");
        scanf("%d",&num);

        if(palindrome(num))
        printf("palindrome number");
        else
        printf("not a pallindrome number");
        return 0;
    }
