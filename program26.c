#include<stdio.h>

int main()
{
    int n;
    printf("enter the number:\n");
    scanf("%d", &n);

    if(n%97==0)
    {
        printf("the given number is divible by 97");
    }
    else
    {
        printf("not divisible");
    }
    return 0;

    
}