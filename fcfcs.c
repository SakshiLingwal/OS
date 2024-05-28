//FCFS: first come first serve 
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    int n,sum,sumo;
    float avg,avgt;
    printf("Enter no. of process :");
    scanf("%d",&n);
    int a[10],bt[10],wt[10],tat[10];
    printf("Enter arrival time :");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter burst time :");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
    }
    printf("Process\tArrival time\tBurst time\tWaiting time\tTurn Around time\n");
    for(int i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        sum+=wt[i];
        sumo+=tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,a[i],bt[i],wt[i],tat[i]);
    }
    avg=sum/n;
    avgt=sumo/n;
    printf("Avg of wt=%f\n",avg);
    printf("Avg of tat=%f\n",avgt);
    return 0;
}
 