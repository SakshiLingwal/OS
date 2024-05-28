//Orphan process:process having no parent.An orphan process is a process that is created by a parent process, but the parent process
//  terminates before the child process. When the parent process terminates, the child process is adopted by the init process 
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h> 
int main()
{ 
    pid_t pid;
    pid=fork();
    if(pid==0) {
        sleep(5);
        printf("I'm child.My PID=%d\n",pid);
    }
    else if(pid>0) { 
        printf("I'm parent.My child PID= %d\tand my PID=%d\n",getpid(),pid);
    }
    return 0;
}
  