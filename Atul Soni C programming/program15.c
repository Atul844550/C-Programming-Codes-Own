#include<stdio.h>

int main(){
    
    int number;
    printf("enter the number:");
    scanf("%d",&number );

    if(number>=0)
    {
        printf("%d is an positive number", &number);

    }
    else{
        printf("%d is an negative number", &number);

    }
    return 0;
}