/*
============================================================================
Name : 17c.c
Author : Parag Dutt Sharma
Description : Write a program to execute ls -l | wc.
		c. use fcntl
Date: 9th Oct, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int pipe_fd[2];
    pid_t child_pid;

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    if ((child_pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) { // Child process
        // Close the read end of the pipe
        close(pipe_fd[0]);

        // Redirect stdout to the write end of the pipe using fcntl
        int new_stdout = fcntl(pipe_fd[1], F_DUPFD, STDOUT_FILENO);
        if (new_stdout == -1) {
            perror("fcntl");
            exit(EXIT_FAILURE);
        }
        close(pipe_fd[1]);

        // Execute the 'ls -l' command
        execlp("ls", "ls", "-l", NULL);

        // Handle any errors if execlp fails
        perror("execlp");
        exit(EXIT_FAILURE);
    } 
    
    else { // Parent process
        // Close the write end of the pipe
        close(pipe_fd[1]);

        // Redirect stdin to the read end of the pipe using fcntl
        int new_stdin = fcntl(pipe_fd[0], F_DUPFD, STDIN_FILENO);
        if (new_stdin == -1) {
            perror("fcntl");
            exit(EXIT_FAILURE);
        }
        close(pipe_fd[0]);

        // Execute the 'wc' command
        execlp("wc", "wc", NULL);

        // Handle any errors if execlp fails
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    return 0;
}

