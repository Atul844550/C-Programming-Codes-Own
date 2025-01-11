#include<stdio.h>

int main(){
    int marks;
    printf("enter marks:");
    scanf("%d", &marks);

    if(marks>=33)
    {
        printf("student pass");
        
    }
    else if(marks==100)
    {
        printf("first position in the class");
    }
    if(marks==90)
    {
        printf("second position in the class");
    }
    else if(marks==75)
    {
        printf("third position in the class");
    }
    else (marks<=33);
    {
      printf("fail");
    }
    return 0;
}