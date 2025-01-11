/*
#include<stdio.h>

void main()
{
    add();

    return 0;

}

int add()
{
    int x=5, y=5;
    int z=x+y;
    printf("%d", z);
}
*/

#include<stdio.h>

int sum(int x, int y);
int sub();
int  main()
{
    
    int s=sum(5,2);
    
    sub();

    return 0;
}

int sum(int x, int y)
{
    int z;
     
    z=x+y;

    printf("%d \n", z);
    

    return 0;
}

int sub()
{
    int x=5, y=7;
    int z= y-x;
    printf("%d \n", z);

    return 0;


}


      





    

