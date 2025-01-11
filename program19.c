#include<stdio.h>

int main(){
    int fahrenheit, celsius;
    printf("enter the value of celsius in degree:");
    scanf("%d", &celsius);
    int fahrenheit= 9/5*celsius+32;
    printf("temperature in fahrenheit is %d", fahrenheit);
    return 0;
}