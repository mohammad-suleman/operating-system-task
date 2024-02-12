#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int meowmeow = 0;
pthread_mutex_t my_mutex;
void *Heart_Rate_function(void *arg)
{
    pthread_mutex_lock(&my_mutex);
    printf("Lights are starting...\n");
    sleep(2);
    meowmeow += 2;
    pthread_mutex_unlock(&my_mutex);
    pthread_exit(NULL);
}
void *Oxygen_Monitor_function(void *arg)
{
    pthread_mutex_lock(&my_mutex);
    printf("Thermostat is starting...\n");
    sleep(5);
    meowmeow += 5;
    pthread_mutex_unlock(&my_mutex);
    pthread_exit(NULL);
}
void *Blood_Pressure_function(void *arg)
{
    pthread_mutex_lock(&my_mutex);
    printf("SecuritySystem are starting...\n");
    sleep(10);
    meowmeow += 10;
    pthread_mutex_unlock(&my_mutex);
    pthread_exit(NULL);
}
void *Glucose_Monitor_function(void *arg)
{
    pthread_mutex_lock(&my_mutex);
    printf("Appliance is starting...\n");
    sleep(3);
    meowmeow += 3;
    pthread_mutex_unlock(&my_mutex);
    pthread_exit(NULL);
}
void *Respiratory_Mointor_function(void *arg)
{
    pthread_mutex_lock(&my_mutex);
    printf("Security Camera is starting...\n");
    sleep(4);
    meowmeow += 4;
    pthread_mutex_unlock(&my_mutex);
    pthread_exit(NULL);
}
int main()
{
    
    pthread_t Heart_Rate, Oxygen_Monitor, Blood_Pressure, Glucose_Monitor, Respiratory_Mointor
    printf("The main house security function is starting... \n ");

    pthread_create(&Heart_Rate, NULL, Heart_Rate_function, NULL);
    pthread_create(&Oxygen_Monitor, NULL, Oxygen_Monitor_function, NULL);
    pthread_create(&Blood_Pressure, NULL, Blood_Pressure_function, NULL);
    pthread_create(&Glucose_Monitor, NULL, Glucose_Monitor_function, NULL);
    pthread_create(&Respiratory_Mointor, NULL, Respiratory_Mointor_function, NULL);

    pthread_join(lights, NULL);
    pthread_join(thermostats, NULL);
    pthread_join(security_system, NULL);
    pthread_join(appliances, NULL);
    pthread_join(security_camera, NULL);

    printf("The total time taking is  %d .", meowmeow);

    exit(0);
    return 0;
}