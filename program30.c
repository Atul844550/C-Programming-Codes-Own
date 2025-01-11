#include<stdio.h>

int main()
{
    int n, i, a;
    printf("enter the table number:");
    scanf("%d", &n);

    for(i=1; i<=10; i++)
    {
         a=(n*i);
        printf("%d \n", a);
        
    }
    return 0;


}