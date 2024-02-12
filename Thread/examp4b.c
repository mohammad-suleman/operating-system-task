/*
    PASSING A RGUMENTS TO THREADS
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *inc_x( void *arg) { /* increment x to 100 */ 
    printf("Thread : Process Id is %d and Thread Id is %ld\n" , getpid(), pthread_self());
    int *input;
    input =( int *) arg ; 
    while (++(*input) < 100);
    printf ( "x increment finished\n");
    /* the function must return something − NULL will do */ 
    pthread_exit(NULL);
}
int main(){
    // main Thread
    int x = 0, y = 0;
    printf("x : %d , y : %d\n", x ,y); // show initials values
    printf("main :Process Id is %d and Thread Id is %ld\n", getpid(), pthread_self());
    //this variable is our reference to the second thread 
    pthread_t thread_2;
    // create a second thread which executes inc_x(&x )
    pthread_create(&thread_2 , NULL, inc_x , &x);
    // increment y to 100 in the f i r s t thread 
    while(++y < 100);
    printf("y increment finished\n");
    printf("x : %d , y : %d\n" , x ,y );
    /* wait for the second thread to finish */
    pthread_join(thread_2 , NULL);
    printf("x : %d , y : %d\n" , x ,y );

    pthread_exit (NULL);
}