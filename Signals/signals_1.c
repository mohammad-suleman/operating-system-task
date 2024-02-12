#include <signal.h>
#include <stdio.h>
#include <unistd.h>
int sigCounter = 0;
void sigHandler(int sigNum)
{
    printf("Signal received is %d\n", sigNum);
    ++sigCounter;
    printf("*****************  Signals received %d *********************\n", sigCounter);
    // if(sigCounter == 3){
    //     exit(0);
    // }
}
int main()
{
    signal(SIGINT, sigHandler);
    while(1)
    {
        printf("Hello Dears\n");
        printf("Hello Dears %d\n",getpid());
        sleep(1);
    }
    return 0;
}