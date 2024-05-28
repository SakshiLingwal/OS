#include <stdio.h>
#include <stdbool.h> // Added for using 'bool' type
#include <unistd.h>
#include <stdlib.h>
int main() {
    int a[10],b[10],n,wt[10]={0},tat[10]={0},tq,i,rem[10],total_wt=0,total_tat=0;
    float avg_wt,avg_tat;
    printf("Enter the no. of processes: ");
    scanf("%d", &n);
    printf("Enter the arrival time of processes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the burst time of processes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        rem[i] = b[i];
    }
    printf("Enter the time quantum: ");
    scanf("%d", &tq);
    int t = 0;              //current time
    while (1) {
        bool done = true; // assume all are done
        for (i = 0; i < n; i++) {
            if (rem[i] > 0) { // There is a pending process
                done = false;
                if (rem[i] > tq) {
                    t += tq;
                    rem[i] -= tq;
                } else {
                    t += rem[i];
                    wt[i] = t - b[i] - a[i]; // Updated waiting time calculation
                    rem[i] = 0; // Mark the process as done
                }
            }
        }
        if (done == true)
            break;
    }
    for (i = 0; i < n; i++) {
        tat[i] = b[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("Processes | Burst time | Waiting time | Turn around time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", i + 1, b[i], wt[i], tat[i]);
    }
    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;
    printf("Average waiting time = %f\n", avg_wt);
    printf("Average turn around time = %f\n", avg_tat);
    return 0;
}
 