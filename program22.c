#include<stdio.h>

int main(){
    int a=1;

    do{
        printf("%d", a);
        ++a;
    }
    while(a<=10);
    {
        printf("%d\n", a);
        ++a;
    }
        
    
    return 0;
}