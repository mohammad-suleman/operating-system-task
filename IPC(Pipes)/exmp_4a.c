// COMMUNICATION BETWEEN DIFFERENT ANCESTRY PROCESSES
#include<unistd.h>
#include<string.h>
#include<fcntl.h> 
#include<stdio.h>
int main(){
    char str[256] = "hello from other side...";
    int fifo_write ;
    
    //open " pipe_one " with WRITE only mode // and return its file descriptor 
    fifo_write = open("pipe_one",O_WRONLY); 
    //check if open call was successful
    if (fifo_write < 0){
        printf(" Error opening file \n");
    }
    else {
        while(strcmp(str, "ImDone") != 0){ 
            printf(" Enter text: \n");
            scanf("%s",&str); //input from user
            write (fifo_write , str , sizeof(str));
            printf("* %s *\n",str);

             read(fifo_write, str, sizeof(str));
            // Printing text which is read from the PIPE
            printf("** Text: %s \n",str);
        }
        close(fifo_write);
    }
    return 0;
}