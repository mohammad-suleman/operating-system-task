#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printProcessInfo(char processName, int processID, int parentID) {
    printf("Process %c: PID = %d, Parent PID = %d\n", processName, processID, parentID);
}

int main() {
    printProcessInfo('0', getpid(), getppid());

    pid_t pid1 = fork();

    if (pid1 == 0) {
        // Child process 1 (P1)
        printProcessInfo('1', getpid(), getppid());

        pid_t pid2 = fork();

        if (pid2 == 0) {
            // Child process 2 (P2)
            printProcessInfo('2', getpid(), getppid());
        } else {
            pid_t pid3 = fork();

            if (pid3 == 0) {
                // Child process 3 (P3)
                printProcessInfo('3', getpid(), getppid());
            }
        }
    } else {
        // Parent process (P0)
        wait(NULL);  // Wait for child process 1 to finish

        pid_t pid4 = fork();

        if (pid4 == 0) 
        {
            // Child process 4 (P4)
            printProcessInfo('4', getpid(), getppid());
        }
        else {
            wait(NULL);  // Wait for child process 4 to finish
        }

            pid_t pid5 = fork();

            if (pid5 == 0) {
                // Child process 5 (P5)
                printProcessInfo('5', getpid(), getppid());
            } else {
                pid_t pid6 = fork();

                if (pid6 == 0) {
                    // Child process 6 (P6)
                    printProcessInfo('6', getpid(), getppid());
                } else {
                    pid_t pid7 = fork();

                    if (pid7 == 0) {
                        // Child process 7 (P7)
                        printProcessInfo('7', getpid(), getppid());
                    }
                }
            }
        
        else {
            wait(NULL);  // Wait for child process 4 to finish
        }
    }

    return 0;
}
