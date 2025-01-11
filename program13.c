#include<stdio.h>

int main(){
    int a, b;
    printf("enter the value of a and b:");
    scanf("%d, %d", &a, &b);

    if(a>b)
    {
        printf("a is greater then b");
    }
    else
    {
        printf("invalid");
        
    }
    return 0;
}