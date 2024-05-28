//fork()- system call is used to create a new process (child process)
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    printf("This is demo of fork system call\n");
    fork();
    fork();
    printf("Hello\n");
    return 0;
}