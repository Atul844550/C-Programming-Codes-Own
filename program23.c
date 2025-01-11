#include<stdio.h>

int main(){
    int a, b, c ;
    int  average;
    printf("enter the value of a:");
    scanf("%d", &a);
    printf("enter the value of b:");
    scanf("%d", &b);
    printf("enter the value of c:");
    scanf("%d", &c);
    average= (a+b+c)/3 ;
   printf("average is %d", average);
    return 0;
}