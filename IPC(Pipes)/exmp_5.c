#include<unistd.h>
#include<string.h>
#include<fcntl.h> 
#include<stdio.h>
int main(){
    int f1,f2;
    char str[256] = "hello world" ;
    //create a pipe with name " pipe_one " and set permissions to 0666
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
    //removing pipes 
    unlink("pipe_one"); //remove pipe_one 
    unlink ("pipe_two"); //removing pipe_two
    printf("Pipe ONE and Pipe TWO is Deleted....\n");
    return 0;
}