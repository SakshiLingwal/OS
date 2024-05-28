#include<stdio.h>       // Standard I/O functions
#include <unistd.h>    // Provides access to the POSIX operating system API
#include <sys/types.h> // Defines various data types used in system calls
int main(){
    pid_t p;            //This data type is used to represent process IDs 
    printf("Before fork\n");
    p=fork();
    if(p==0){                                            //In the child process, p will be set to 0.
        printf("Child having id %d\n",getpid());           // Print the child's PID
        printf("Parent having id %d\n",getppid());         // Print the parent's PID (which is the child's parent)
    }
    else{
        wait(NULL);                         // Wait for the child process to finish.
        printf("Child is %d\n",p);          // Print the child's PID (received from fork)
        printf("Parent is %d\n",getppid()); // Print the parent's PID (which is the original process's PID)
    }
    return 0;
}