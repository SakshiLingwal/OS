//Demonstrate the working of wait() system call
#include<stdio.h>
#include<unistd.h> 
#include<sys/wait.h>
int main() 
{
    int i;
    pid_t pid;
    pid=fork();
    if(pid==0){
        for(i=0;i<3;i++)
            printf("Child Process\n");
    }
    else if(pid>0){
        printf("Helo\n");
        wait(NULL);             //wait for child process to complete its execution
        for(i=0;i<3;i++)
            printf("Parent Process\n");
    }
    return 0;
}