//wap to Find LCM of two numbers
#include<stdio.h>
int main()
{
    int a,b,max;
    printf("enter two numbers:");
    scanf("%d%d",&a,&b);
    max=(a<b)?a:b;
    while(1){
    if (max %a == 0 && max % b == 0)
{
    printf("lcm=%d",max);
    break;

}
max++;
}
return 0;
}
