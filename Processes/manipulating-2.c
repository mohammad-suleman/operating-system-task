#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
int global =0;

int main(){
    int status;
    pid_t pid ; 
    pid = fork ();
    if ( pid == 0 ){
        printf("I am Child process with pid %d and i am not waiting\n", getpid());
        exit(status);
    } 
    else if (pid > 0){
        printf("I am Parent process with pid %d and i am waiting\n", getpid());
        printf ( " parent PID = %d , child pid = %d\n", getpid(), pid);
        pid_t exitedChildId=wait(&status);
        printf("I am Parent process and the child with pid %d is exited\n", exitedChildId);
    }
    else if ( pid < 0){ // if fork() fails 
        printf (" Error in Fork");
    }
    return 0;

}