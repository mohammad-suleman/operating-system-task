#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

// Semaphore for water dispenser access (initial value 3)
sem_t water_dispenser_semaphore;

// Function representing a person trying to take water
void* take_water(void* person_id) {
    int person = *(int*)person_id;

    // Wait for the water dispenser to be available
    sem_wait(&water_dispenser_semaphore);

    // Critical section: taking water
    printf("Person %d is taking water...\n", person);

    // Simulate the time it takes to fill a cup with water
    sleep(2);

    // Release the water dispenser
    sem_post(&water_dispenser_semaphore);

    // Person has finished taking water
    printf("Person %d finished taking water.\n", person);

    pthread_exit(NULL);
}

int main() {
    // Initialize semaphore with initial value 3
    sem_init(&water_dispenser_semaphore, 0, 3);

    // Number of people (threads)
    const int num_people = 5;
    pthread_t people[num_people];
    int person_ids[num_people];

    // Create threads for people
    for (int i = 0; i < num_people; ++i) {
        person_ids[i] = i + 1;
        pthread_create(&people[i], NULL, take_water, &person_ids[i]);
    }

    // Join threads
    for (int i = 0; i < num_people; ++i) {
        pthread_join(people[i], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&water_dispenser_semaphore);

    return 0;
}
