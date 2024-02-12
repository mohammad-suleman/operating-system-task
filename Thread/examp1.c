#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *kidfunc(void *p){
    printf("Kid ID is ---> %d\n", getpid());
}
int main(){
    pthread_t kid ;
    pthread_create(&kid, NULL, kidfunc, NULL);
    printf("Parent ID is ---> %d\n", getpid());
    printf("No more kid!\n") ;
    pthread_join(kid, NULL) ; // waiting kidFunction

    return 0;
}