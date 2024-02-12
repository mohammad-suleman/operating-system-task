#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
// Using semaphore as a Binary lock for IPC/Syncronization
sem_t sem ; 
void *f1 ( void *arg ){ 
    sem_wait(&sem); // 1 to 0  (we are locking it) lock 1->0 Lock
        printf("Thread with ID:%ld got lock\n" , pthread_self());
        sleep(5);
    sem_post(&sem);// notifying other threads or processes 0 -> 1 ( Unlock)
    pthread_exit (NULL) ;
}

int main(){
    pthread_t tid1 , tid2; 
    sem_init(&sem , 0 , 1 );
    printf("Statring threads...\n");
    pthread_create(&tid1 ,NULL, f1 ,NULL);
    pthread_create(&tid2 ,NULL, f1 ,NULL);

    pthread_exit (NULL);
}