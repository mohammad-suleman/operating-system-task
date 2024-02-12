#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_fd[2];
    
    if (pipe(pipe_fd) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) { // Child process (Evaluator)
        close(pipe_fd[1]);  // Close write end in child

        char expression[100]; // buffer
        read(pipe_fd[0], expression, sizeof(expression));

        // Simple expression evaluation (for demonstration purposes)
        int result = 0;
        sscanf(expression, "%d+%d", &result);

        printf("Child Process: Evaluation result: %d\n", result);

        // Send success message to parent
        write(pipe_fd[1], "Expression evaluated successfully.", sizeof("Expression evaluated successfully."));

        close(pipe_fd[0]);
        close(pipe_fd[1]);
        exit(EXIT_SUCCESS);
    } else { // Parent process (Expression Sender)
        close(pipe_fd[0]);  // Close read end in parent

        char expression_to_send[100];
        printf("Enter a mathematical expression (e.g., 2+3): ");
        scanf("%s", expression_to_send);

        write(pipe_fd[1], expression_to_send, sizeof(expression_to_send));

        // Wait for child's response
        char response[100];
        read(pipe_fd[0], response, sizeof(response));

        printf("Parent Process: %s\n", response);

        close(pipe_fd[0]);
        close(pipe_fd[1]);
    }

    return 0;
}
