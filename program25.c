#include<stdio.h>

int main()
{
    float celcius;
    printf("enter the degree of celcius:");
    scanf("%f", &celcius);
    float fah= (1.8*celcius)+32;

    printf("the degree in fah is %f", fah);

    return 0;

    
}