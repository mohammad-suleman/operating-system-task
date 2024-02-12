#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main() {
    int TEST_VALUE = 10;

    pid_t childpid = fork();

    if (childpid == 0) {
        printf("I am a child process with pid = %d\n", getpid());
        printf("The next statement is execv, and ls will run\n");

        char* argv[] = {"ls", "-l", "/usr", NULL};
        execlp("ls", "ls", "-l", "/usr", NULL);

        // This line will not be reached if execlp succeeds
        perror("Execv failed");
    } else if (childpid > 0) {
        wait(NULL);
        printf("\nI am the parent process with pid = %d and finished waiting\n", getpid());
    }

    printf("Before Fork! TEST_VALUE=%d\n", TEST_VALUE);

    pid_t id = fork();

    if (id == 0) {
        int local_value = TEST_VALUE + 10;
        printf("In child Fork! local_value=%d\n", local_value);
        printf("In ppid Fork! TEST_VALUE=%d\n", TEST_VALUE);
    } else {
        int i;
        for (i = 0; i < 5; ++i) {
            printf("In my id Fork! TEST_VALUE=%d\n", TEST_VALUE);
            TEST_VALUE = TEST_VALUE + 5;
            printf("In parent Fork! TEST_VALUE=%d\n", TEST_VALUE);
            if (i == 2) {
                break; // Break out of the loop after a certain condition
            }
        }
    }

    return 0;
}
