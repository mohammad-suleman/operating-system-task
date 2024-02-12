#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_EXPRESSION_LENGTH 100

int main() {
    int parent_to_child[2];
    int child_to_parent[2];

    // Create pipes
    if (pipe(parent_to_child) == -1 || pipe(child_to_parent) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Parent process

        // Close unnecessary pipe ends
        close(parent_to_child[0]);
        close(child_to_parent[1]);

        // Get mathematical expression from the user
        char expression[MAX_EXPRESSION_LENGTH];
        printf("Enter a mathematical expression: ");
        fgets(expression, sizeof(expression), stdin);
        expression[strcspn(expression, "\n")] = '\0';  // Remove newline character

        // Send mathematical expression to the child process
        printf("Parent sending expression to child: %s\n", expression);
        write(parent_to_child[1], expression, strlen(expression) + 1);

        // Close the writing end in the parent for parent-to-child communication
        close(parent_to_child[1]);

        // Read the result from the child
        int result;
        read(child_to_parent[0], &result, sizeof(result));
        printf("Parent received result from child: %d\n", result);

        // Close the remaining pipe ends
        close(child_to_parent[0]);

        // Wait for the child to finish
        wait(NULL);
    } else {
        // Child process

        // Close unnecessary pipe ends
        close(parent_to_child[1]);
        close(child_to_parent[0]);

        // Read the mathematical expression from the parent
        char expression[MAX_EXPRESSION_LENGTH];
        read(parent_to_child[0], expression, sizeof(expression));
        printf("Child received expression from parent: %s\n", expression);

        // Parse and evaluate the expression (a simple example)
        int result;
        sscanf(expression, "%d", &result);

        // Modify the result (add 3) and send it back to the parent
        result += 3;
        write(child_to_parent[1], &result, sizeof(result));

        // Close the remaining pipe ends
        close(parent_to_child[0]);
        close(child_to_parent[1]);

        // Exit the child process
        exit(EXIT_SUCCESS);
    }

    return 0;
}
