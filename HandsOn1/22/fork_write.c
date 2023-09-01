#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>

int main() {
    int fd;
    pid_t child_pid;

    fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        return 1;
    } 
    
    else if (child_pid == 0) {
        const char *child_message = "Hello from the child process!\n";
        write(fd, child_message, strlen(child_message));
    } 
    
    else {
        const char *parent_message = "Hello from the parent process!\n";
        write(fd, parent_message, strlen(parent_message));

        wait(0);
    }

    close(fd);

    return 0;
}

