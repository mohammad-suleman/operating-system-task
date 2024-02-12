#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *PrintHello(void *threadid)
{
    printf("\n%d: Hello World!\n", threadid);
    pthread_exit(NULL);
}
int main()
{
    pthread_t threads[3];
    int rc; int t;
    for(t=0; t<3; t++)
    {
        printf("In main: creating thread\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
        if(rc){ // other than 0 return value
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    for(t=0; t<3; t++)
    {
    pthread_join(threads[t], NULL );
    }
    printf("Exiting main\n");
    pthread_exit(NULL);
}