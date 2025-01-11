#include<stdio.h>

int main(){
    int x, y;
    printf("enter he value of x and y: \n");
    scanf("%d, %d", &x, &y);

    if(x>y)
    {
        printf("hello sir");
    }
    else if(y>x)
    {
        printf("no sir");
    }
    if(y==x)
    {
        printf("thank you sir");
    }
    return 0;
}