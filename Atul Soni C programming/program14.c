#include<stdio.h>

int main(){
    int num;
    printf("enter the value:");
    scanf("%d", &num);

    if(num %4==0)
    {
        printf("%d is an even number", &num);
    }
    else
    {
        printf("%d is an odd number", &num);
    }
    return 0;


}