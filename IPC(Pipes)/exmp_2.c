#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
    int fd[2];
    pid_t childpid; 
    char msg [] = "Hello from child\n";
    char readbuffer[80];
    int result = pipe(fd);
    if(result<0){
        printf("Error while creating file");
        exit(1) ;
    }
    childpid = fork();
    if(childpid == -1){
        printf("Error in fork...");
        exit(1);
    }
    if(childpid == 0){ // Child process writing to the pipe
        close(fd[0]);
        printf("Child writing to the pipe \n"); 
        write(fd[1], msg, sizeof(msg)); 

        read(fd[0] , readbuffer, sizeof(readbuffer));
        printf("2) Received string :%s \n",readbuffer);

        printf("Written to a Pipe \n");
        exit(0);
    } 
    else { // Parent process waiting for child to write on Pipe and then read from Pipe
        close(fd[1]);
        wait(NULL);
        printf("Parent reading from the pipe \n");
        read(fd[0] , readbuffer, sizeof(readbuffer));
        printf("Received string :%s \n",readbuffer);
        
        // write(fd[1], msg, sizeof(msg)); 

        // read(fd[0] , readbuffer, sizeof(readbuffer));
        // printf("2) Received string :%s \n",readbuffer);

        exit(0);
    }
    return 0;
}