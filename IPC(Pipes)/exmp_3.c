#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
    int f1,f2;
    //create a pipe with name " pipe_one " and set permissions to 6606
    f1 = mkfifo("pipe_one", 0666);
    //check if mkfifo call was successful
    if (f1<0)
        printf(" Pipe one is not created.\n");
    else
        printf("Pipe one is created...\n");
    f2 = mkfifo("pipe_two", 0666);
    if (f2<0)
        printf(" Pipe two is not created.\n");
    else
        printf("Pipe two is created...\n");
    
    return 0;
}