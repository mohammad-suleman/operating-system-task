#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
int global =0;

int main(){
    int status ;
    pid_t child_pid ; 
    int local =0;
    child_pid = fork ();
    if ( child_pid ==0 ){
        printf("child process !\n");
        local ++;
        global ++;
        printf(" child PID = %d , parent pid = %d\n" , getpid(), getppid());
        printf("\n child ’ s local = %d , child ’ s global = %d\n" ,local, global);
    } 
    else{
        printf("parent process !\n");
        printf ( " parent PID = %d , child pid = %d\n", getpid(), child_pid);
        int w = wait(&status);
        //The change in local and global variable //in child process should not rflect //here in parent process .
        printf("\nParent’z local = %d , parent's global = %d\n", local, global);
        printf("Parent says bye!\n"); 
        exit(0);
    }
    return 0;

}