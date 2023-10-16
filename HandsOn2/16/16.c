/*
============================================================================
Name : 16.c
Author : Parag Dutt Sharma
Description : Write a program to send and receive data from parent to child vice versa. Use two way communication. 
Date: 9th Oct, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_fd[2];
    pid_t child_pid;

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Child process

        close(pipe_fd[1]); // Close the write end of the pipe

        char buffer[100];
        ssize_t nbytes;

        // Read data from the parent
        nbytes = read(pipe_fd[0], buffer, sizeof(buffer));
        if (nbytes == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Child received: %s\n", buffer);

        // Close the read end of the pipe
        close(pipe_fd[0]);

    } else {
        // Parent process

        close(pipe_fd[0]); // Close the read end of the pipe

        char message[] = "Hello from parent!";
        ssize_t nbytes;

        // Write data to the child
        nbytes = write(pipe_fd[1], message, sizeof(message));
        if (nbytes == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Close the write end of the pipe
        close(pipe_fd[1]);

        // Wait for the child to finish
        wait(NULL);
    }

    return 0;
}

