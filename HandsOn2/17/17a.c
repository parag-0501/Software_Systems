//dup

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        
        close(pipe_fd[0]);

        int stdout_copy = dup(STDOUT_FILENO);
        if (stdout_copy == -1) {
            perror("dup");
            exit(EXIT_FAILURE);
        }

        close(STDOUT_FILENO);

        dup(pipe_fd[1]);
        close(pipe_fd[1]);

        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        close(pipe_fd[1]);

        close(STDIN_FILENO);
        dup(pipe_fd[0]);
        close(pipe_fd[0]);

        execlp("wc", "wc", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    return 0;
}
