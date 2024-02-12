#include <pthread.h>
#include <stdio.h>
struct thread_data
{
    int x, y,z;
};
struct thread_data somedata;
void *print(void *threadArg)
{
    struct thread_data *my_data;
    my_data = (struct thread_data *) threadArg; // type casting from void to thread_data
    printf("X: %d,\nY: %d,\nZ: %d\n",my_data->x, my_data->y, my_data->z);
    // update some va;lue
    my_data->x = 100;
}
int main()
{
    pthread_t tid;
    somedata.x = 10;
    somedata.y = 20;
    somedata.z = somedata.x + somedata.y;
    pthread_create(&tid, NULL, print, (void *) &somedata);
    pthread_join(tid, NULL );
    // print here
    printf("Exiting main.\n");
    printf("X: %d,\nY: %d,\nZ: %d\n",somedata.x, somedata.y, somedata.z);
    return 0;
}