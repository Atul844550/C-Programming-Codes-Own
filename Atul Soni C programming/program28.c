#include<stdio.h>

int main()
{
    int english, hindi, maths;
    float total;
    printf("enter the marks of english:");
    scanf("%d", &english);

     printf("enter the marks of hindi:");
    scanf("%d", &hindi);

     printf("enter the marks of maths:");
    scanf("%d", &maths);

    total=(english+ hindi+ maths)/3;

    if((total>=40) && (english>=33) && (hindi>=33) && (maths>=33) )
    {
        printf("your total is %f you are pass", total );
    }
    else
    {
        printf("your total is %f you are fail", total);

    }
    return 0;
}