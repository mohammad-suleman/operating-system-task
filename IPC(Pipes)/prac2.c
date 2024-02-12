#include <stdio.h>
#include <unistd.h>
#include <string.h>

// Function declarations
void P1();
void P2();
void P3();
void P4();

int main() {
    // Create pipes for communication
    int pipe1[2], pipe2[2], pipe3[2];

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1 || pipe(pipe3) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    // Fork processes
    pid_t pid1 = fork();

    if (pid1 == 0) {
        // Child process 1 (P1)
        close(pipe1[0]);  // Close unused read end
        P1(pipe1[1]);
    } 
    else 
    {
        pid_t pid2 = fork();

        if (pid2 == 0) {
            // Child process 2 (P2)
            close(pipe1[1]);  // Close unused write end
            close(pipe2[0]);  // Close unused read end
            P2(pipe1[0], pipe2[1]);
        } 
        else 
        {
            pid_t pid3 = fork();

            if (pid3 == 0) {
                // Child process 3 (P3)
                close(pipe2[1]);  // Close unused write end
                close(pipe3[0]);  // Close unused read end
                P3(pipe2[0], pipe3[1]);
            } 
            else 
            {
                // Parent process (P4)
                close(pipe3[1]);  // Close unused write end
                P4(pipe3[0]);
            }
        }
    }

    return 0;
}

void P1(int writePipe) {
    // P1 logic for reading input and passing to P2
    // ...

    // Example: writing data to pipe
    char imageName[] = "Video Processing File";
    write(writePipe, imageName, strlen(imageName) + 1);

    // Close write end of the pipe
    close(writePipe);
}

void P2(int readPipe, int writePipe) {
    // P2 logic for preprocessing and passing to P3
    // ...

    // Example: reading data from pipe
    char imageName[256];
    read(readPipe, imageName, sizeof(imageName));

    // Preprocessing logic (appending 'resized')
    strcat(imageName, "transcoded");

    // Example: writing processed data to pipe
    write(writePipe, imageName, strlen(imageName) + 1);

    // Close read and write ends of the pipes
    close(readPipe);
    close(writePipe);
}

void P3(int readPipe, int writePipe) {
    // P3 logic for analysis and passing to P4
    // ...

    // Example: reading preprocessed data from pipe
    char imageName[256];
    read(readPipe, imageName, sizeof(imageName));

    // Analysis logic (appending 'analyzed')
    strcat(imageName, "QC_Passed");

    // Example: writing analysis results to pipe
    write(writePipe, imageName, strlen(imageName) + 1);

    // Close read and write ends of the pipes
    close(readPipe);
    close(writePipe);
}

void P4(int readPipe) {
    // P4 logic for final processing and printing
    // ...

    // Example: reading analysis results from pipe
    char imageName[256];
    read(readPipe, imageName, sizeof(imageName));

    // Final processing logic
    printf("Final output: %s\n", imageName);

    // Close read end of the pipe
    close(readPipe);
}