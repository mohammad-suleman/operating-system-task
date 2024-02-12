/*
    PASSING A RGUMENTS TO THREADS
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *print_message(void* ptr){
    int message;
    message = (int*) ptr;
    printf("\t%d \n", message);
}
int main()
{
    pthread_t thread1, thread2;
    int x=4;
    int y=5;
    int return_value1, return_value2;
    return_value1 = pthread_create(&thread1,NULL,print_message, (void*) x);
    return_value2 = pthread_create(&thread2,NULL, print_message, (void*) y);
    pthread_join(thread1, NULL );
    pthread_join(thread2, NULL );
    printf("Ending the main process.\n");
    exit(0);
}