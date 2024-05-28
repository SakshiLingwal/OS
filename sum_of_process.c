//Parent Process Computes the Sum of Even Numbers and Child Process computes the sum of Odd Numbers using Fork()
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    int pid,n,sum_even=0,sum_odd=0,i,status;
    printf("Enter The Size of Array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter The Array : ");
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    pid=fork();
    if(pid==0)                  //child process
    {
        for(i=0;i<n;i++){
            if (a[i]%2!=0)
                sum_odd+=a[i];//sum of odd process
        }
        printf("Sum of odd numbers = %d\n", sum_odd);
    }
    else{
        for(i=0;i<n;i++){
            if(a[i]%2==0)
                sum_even+=a[i]; //sum of even parent process
        }
        printf("Sum of even numbers = %d\n", sum_even); 
        wait(&status);
    }
    return 0;
}