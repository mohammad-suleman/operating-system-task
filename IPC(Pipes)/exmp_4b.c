// COMMUNICATION BETWEEN DIFFERENT ANCESTRY PROCESSES
#include<unistd.h>
#include<string.h>
#include<fcntl.h> 
#include<stdio.h>
int main(){
    char str[256] = "" ;
    //open "pipe_one" with READ only mode  and return its file descriptor
    int fifo_read = open("pipe_one", O_RDONLY) ;
    //check if open call was successful
    if (fifo_read < 0){
        printf(" Error in opening file \n");
    }
    else {
        while(strcmp(str, "ImDone") != 0){ 
            printf(" Enter text: \n");
            scanf("%s",&str); //input from user
            write (fifo_read , str , sizeof(str));
            printf("* %s *\n",str);
            // Reading text from Opend pipe

            read(fifo_read, str, sizeof(str));
            // Printing text which is read from the PIPE
            printf("** Text: %s \n",str);
        }
        close(fifo_read);
    }
    return 0;
}