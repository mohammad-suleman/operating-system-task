#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 100

int main() {
    // File path for storing the educational qualifications
    const char *file_path = "education_info.txt";

    // Create pipes
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process
        close(pipe_fd[0]); // Close reading end in parent

        // Get user input
        char user_input[MAX_LENGTH];
        printf("Enter your educational qualifications: ");
        fgets(user_input, MAX_LENGTH, stdin);

        // Write to the pipe
        write(pipe_fd[1], user_input, MAX_LENGTH);

        // Close writing end in parent
        close(pipe_fd[1]);

        // Wait for the child process to finish
        wait(NULL);
    } else { // Child process
        close(pipe_fd[1]); // Close writing end in child

        // Read from the pipe
        char qualifications_read[MAX_LENGTH];
        read(pipe_fd[0], qualifications_read, MAX_LENGTH);

        // Close reading end in child
        close(pipe_fd[0]);

        // Open the file for writing
        FILE *file = fopen(file_path, "w");
        if (file == NULL) {
            perror("File opening failed");
            exit(EXIT_FAILURE);
        }

        // Write the educational qualifications to the file
        fprintf(file, "Educational Qualifications: %s", qualifications_read);

        // Close the file
        fclose(file);

        // Display the stored information
        printf("Educational qualifications stored in %s\n", file_path);
        
        // Exit the child process
        exit(EXIT_SUCCESS);
    }

    return 0;
}
