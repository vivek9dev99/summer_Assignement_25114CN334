//wap to check strong number
#include<stdio.h>
 int main()
 {
    int n,i, temp,rem;
    int sum=0, fact=1;
    printf("enetr the number");
    scanf("%d",&n);
    temp=n;
    while(temp>0){
rem=temp%10;
fact=1;
for(int i=1;i<=rem;i++){
    fact=fact*i;

}
    
    sum=sum+fact;
    temp=temp/10;}

    if(sum==n){
        printf("%d is strong number",sum);}    
        else
    printf("%d is not strong number");
    return 0;








    

















 }