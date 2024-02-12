#include <stdio.h>
#include <pthread.h>

#define NUM_ROWS 3
#define NUM_COLS 3

// New matrix and mutex initialization
int myMatrix[NUM_ROWS][NUM_COLS] = {
    {10, 20, 30},
    {40, 50, 60},
    {70, 80, 90}
};
int columnSums[NUM_COLS] = {0};
pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;

// New thread function to calculate the cumulative sum of a column
void *computeColumnSum(void *arg) {
    int col = *((int *)arg);

    // Calculate the sum of the assigned column
    int sum = 0;
    for (int i = 0; i < NUM_ROWS; ++i) {
        sum += myMatrix[i][col];
    }

    // Update the global result array with the column sum using a mutex for synchronization
    pthread_mutex_lock(&myMutex);
    columnSums[col] += sum;
    pthread_mutex_unlock(&myMutex);

    pthread_exit(NULL);
}

int main() {
    // New thread and index arrays
    pthread_t myThreads[NUM_COLS];
    int colIndices[NUM_COLS];

    // Create threads, each calculating the sum for its assigned column
    for (int i = 0; i < NUM_COLS; ++i) {
        colIndices[i] = i;
        pthread_create(&myThreads[i], NULL, computeColumnSum, (void *)&colIndices[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_COLS; ++i) {
        pthread_join(myThreads[i], NULL);
    }

    // Display the cumulative sums of each column
    printf("Updated Cumulative Sums for Each Column:\n");
    for (int i = 0; i < NUM_COLS; ++i) {
        printf("Column %d: %d\n", i, columnSums[i]);
    }

    return 0;
}

