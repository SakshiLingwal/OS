//Zombie Process :Zombie process voh h jiski execution hogi h per Abhi phi process memory me htaya nhi hota 
#include<stdio.h>
#include<unistd.h>
int main() {
  int pid=fork();
  if(pid==0) {
    exit(0);
  }
  else if(pid>0){
    sleep(6);
    printf("\nParent Process %d \n",getpid());
  }
  return 0;
}
//getpid()-own process id
//getppid()-parent's process id
