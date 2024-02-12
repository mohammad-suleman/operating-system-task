#include <signal.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    // kill(49302,SIGKILL);
    printf("1030602 is killed by Signal/n");
    while(1)
    {
        kill(41846, SIGKILL);
        printf("Hello Dears %d\n",getpid());
        sleep(1);
        kill(getpid(),SIGKILL)
    }
    return 0;
}