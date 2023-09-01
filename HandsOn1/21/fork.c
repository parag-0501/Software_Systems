#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    // Create a child process using fork
    child_pid = fork();

    if (child_pid < 0) {
        perror("fork");
        return 1;
    } 
    
    else if (child_pid == 0) {
        // This is the child process
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } 
    
    else {
        // This is the parent process
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), child_pid);
    }

    return 0;
}

