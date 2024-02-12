#include <stdio.h>
#include <pthread.h>

#define MAX_RECTANGLES 3

struct Dimensions {
    double length;
    double width;
};

struct Results {
    double area;
    double perimeter;
    pthread_t threadID;
};

void *computeRectangle(void *arg) {
    struct Dimensions *rectangle = (struct Dimensions *)arg;
    struct Results result;

    result.area = rectangle->length * rectangle->width;
    result.perimeter = 2 * (rectangle->length + rectangle->width);

    result.threadID = pthread_self();

    printf("Thread ID %lu: Rectangle Area=%.2f, Perimeter=%.2f\n", result.threadID, result.area, result.perimeter);

    pthread_exit((void *)&result);
}

int main() {
    pthread_t threads[MAX_RECTANGLES];
    struct Dimensions rectangles[MAX_RECTANGLES] = {
        {5.0, 3.5},
        {7.2, 4.8},
        {2.5, 6.0}
    };

    struct Results results[MAX_RECTANGLES];

    for (int i = 0; i < MAX_RECTANGLES; ++i) {
        pthread_create(&threads[i], NULL, computeRectangle, (void *)&rectangles[i]);
    }

    for (int i = 0; i < MAX_RECTANGLES; ++i) {
        pthread_join(threads[i], (void **)&results[i]);
    }

    return 0;
}

