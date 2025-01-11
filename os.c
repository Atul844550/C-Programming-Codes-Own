// W.A.P to create project in c using priorty with premption.

#include<stdio.h>
struct process
{
    int WT,AT,BT,TAT,PT;
};

struct process a[10];

int main()
{
    int n,temp[10],t,count=0,short_p; // short_p is a shortlist process
    float total_WT=0,total_TAT=0,Avg_WT,Avg_TAT;
    printf("Enter the number of the process\n");
    scanf("%d",&n);
    printf("Enter the arrival time , burst time and priority of the process\n");
    printf("AT BT PT\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i].AT,&a[i].BT,&a[i].PT);
        
       
        temp[i]=a[i].BT;
    }
    
    
    a[9].PT=10000; // is used for as a starvation of a process.which can be handle by a technique aging.
    
    for(t=0;count!=n;t++) // t is used for as a ghantt chart for particular process.
    {
        short_p=9;
        for(int i=0;i<n;i++)
        {
            if(a[short_p].PT>a[i].PT && a[i].AT<=t && a[i].BT>0)
            {
                short_p=i;
            }
        }
        
        a[short_p].BT=a[short_p].BT-1;
        
        if(a[short_p].BT==0)
        {
            
            count++;
            a[short_p].WT=t+1-a[short_p].AT-temp[short_p];
            a[short_p].TAT=t+1-a[short_p].AT;
            
            
            total_WT=total_WT+a[short_p].WT;
            total_TAT=total_TAT+a[short_p].TAT;
            
        }
    }
    
    Avg_WT=total_WT/n;
    Avg_TAT=total_TAT/n;
    
    
    printf("ID WT TAT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d %d\t%d\n",i+1,a[i].WT,a[i].TAT);
    }
    
    printf("Avg waiting time of the process  is %f\n",Avg_WT);
    printf("Avg turn around time of the process is %f\n",Avg_TAT);
    
    return 0;
}

/* Let say p1=2, p2=0, p3=3, p4=1, p5=4 process are there in the system.Having arival time, 
burst time and priorty number of each process.Considering lower the number higher is the priorty of a process.
So in priorty based scheduling (Premption) process start excuting in the gantt chart at 0.So if a process p1 start execute 
for 1 unit then after 1 unit we had to check if there any process which come at 1.If YES then the respective process come in 
the ready queue with the currently execute process.Now we compare that which process had to execute according to the given
 priorty number.If NO then the current process will be executed 1 more unit then check i.e at 2 if there any process which come 
 at 2 or not.And if the process is having the same priorty then,
the problem will be solved by the  Arival time (AT) i.e who comes first that would be considered i.e (FCFS), 
And if the Arival time is also same then the problem will be solved by the process ID i.e whose ever  having its least 
process ID that would be considered first.This whole cycle will be continue until all process has completed the task i.e upto 
the complete burst time.At last we are able to find the average waiting time by using the formula WT= TAT- BT, TAT= CT-AT and
 average completion time.*/
/*
 First we copy the burst time of the process in a new array temp[] because in the further calculation we will be going to decrease the Burst time of the process but we will have to need the real burst time of the process in the calculation of the waiting time .(If you confused then don't worry you will be able understand after going through code)
we initialize the priority of a process with the maximum (you can take any maximum value). and we will use 9th process because we assumed that there will not be more than 10 process but you can use any number.
In this code we are going to use a loop which executed until all the processes are completed. for checking how many processes are completed we use count .Initially it's value is 0 (i.e no processes are completed yet).
In each  cycle we will find the process which have highest priority(lowest priority number like 1 have high priority than 2) and arrived at time t and burst time of the process is not equal to zero.
After doing this we will decrease the burst time of the process by 1 in each cycle of the time.
And if the process will be complete (Burst time =0) then we will increase the value of the count by 1 (i.e one process is completed)
*/

/*
Major problem with priority scheduling is problem of starvation.
Solution of the problem of the starvation is aging ,where aging is a technique of gradually increasing the priority of the processes that wait in the system from long time.

*/
