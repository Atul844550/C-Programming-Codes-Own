#include<stdio.h>

int main()
{
    int income1;
    int income2;
    int income3;
    float amount1;
    float amount2;
    float amount3;

    printf("enter income1:");
    scanf("%d", &income1);

    printf("enter income2:");
    scanf("%d", &income2);

     printf("enter income3:");
    scanf("%d", &income3);

    amount1=income1*0.05;
    amount2=income2*0.2;
    amount3=income3*0.3;

    if((income1>250000) && (income1<5000000))
    {
        printf("%f", amount1);
    }
    else if((income2>500000) && (income2<1000000))
    {
        printf("%f", amount2);
    }
    else if((income3>100000))
    {
        printf("%f", amount3);

    }

    return 0;

    
}