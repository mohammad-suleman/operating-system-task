#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *thr_fn1(void *arg ){
    printf("Thread 1 exiting\n");
    void *status="Success";
    pthread_exit((void *)status);
}
void *thr_fn2(void *arg){
    printf("Thread 2 exiting\n");
    pthread_exit((void *)10);
}
int main(){
    pthread_t a , tid2 ; 
    pthread_create(&a, NULL, thr_fn1, NULL) ; 
    pthread_create(&tid2 , NULL, thr_fn2 , NULL);

    void *tret1; 
    void *tret2 ;
    pthread_join(a, &tret1); 
    pthread_join(tid2, &tret2);

    printf("Okay thats alright\n");

    // casting tret1 to char∗
    printf("Thread 1 exit code is : %s\n",( char *) tret1) ; 
    printf("Thread 2 exit code is : %ld\n",(long) tret2 );
    exit(0);
    return 0;
}