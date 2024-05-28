#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    int fd[2],n;
    char buffer[100];       //to store char in array,f=0 (read)&f=1(write)
    pid_t p;                //to hold child process in a variable
    pipe(fd);                //
    p=fork();
    if(p>0){
        // close(f[0]);            //close read as parent is writing 
        printf("Passing value to child\n");
        write(fd[1],"Hello guys\n",12);
        wait();
    }
    else{
        // close(f[1]);    //close write as parent is reading
        printf("Child recieved data\n");
        n=read(fd[0],buffer,100); //fd[0] reading end ->file discreptor
        write(1,buffer,n);
    }
    return 0;   
}