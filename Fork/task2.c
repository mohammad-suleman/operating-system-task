#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork(); // Create a child process

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // This is the child process
        printf("Child process is running (PID=%d)\n", getpid());
        sleep(120); // Sleep for 120 seconds
        printf("Child process is done\n");
    } else {
        // This is the parent process
        printf("Parent process is running (PID=%d)\n", getpid());
        sleep(120); // Sleep for 120 seconds
        printf("Parent process is done\n");
    }

    return 0;
}

