#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int glob_data = 5;
pthread_mutex_t myMutex;
void *kidfunc(void *p)
{ 
    pthread_mutex_lock(&myMutex);
    printf ("Kid here:- Global data was %d.\n", glob_data);
    glob_data = 15;
    printf ("Kid Again:- Global data was now %d.\n", glob_data);
    pthread_mutex_unlock(&myMutex);
}

void *kidfunc2(void *p)
{
    pthread_mutex_lock(&myMutex);
    printf ("Kid2 here:- Global data was %d.\n", glob_data);
    glob_data += 12;
    printf ("Kid2 Again:- Global data was now %d.\n", glob_data);
    pthread_mutex_unlock(&myMutex);
}

int main()
{
    pthread_t kid, kid2;
    pthread_create (&kid, NULL, kidfunc, NULL);
    pthread_create (&kid2, NULL, kidfunc2, NULL);
    printf ("Parent at Start:- Global data = %d\n", glob_data);
    pthread_join(kid, NULL);
    pthread_join(kid2, NULL);
    glob_data = 10;
    printf ("End of program.\nGlobal data = %d\n", glob_data);
    return 0;
}


