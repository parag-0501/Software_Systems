/*
==========================================================================================================================================
Name  :  25.c
Author  :  Parag Dutt Sharma
Description  :  Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).
Date  :  8th September 2023
==========================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child1_pid, child2_pid, child3_pid;
    int status;

    child1_pid = fork();

    if (child1_pid == -1) {
        perror("Fork failed");
        exit(1);
    }

    if (child1_pid == 0) {
        printf("Child 1 is running...\n");
        sleep(2);
        printf("Child 1 is done.\n");
        exit(1);
    }

    child2_pid = fork();

    if (child2_pid == -1) {
        perror("Fork failed");
        exit(1);
    }

    if (child2_pid == 0) {
        printf("Child 2 is running...\n");
        sleep(3);
        printf("Child 2 is done.\n");
        exit(2);
    }

    child3_pid = fork();

    if (child3_pid == -1) {
        perror("Fork failed");
        exit(1);
    }

    if (child3_pid == 0) {
        printf("Child 3 is running...\n");
        sleep(4);
        printf("Child 3 is done.\n");
        exit(3);
    }

    printf("Parent is waiting for Child 1 (PID %d) to finish...\n", child1_pid);

    if (waitpid(child1_pid, &status, 0) == -1) {
        perror("waitpid");
        exit(1);
    }

    if (WIFEXITED(status)) {
        printf("Child 1 (PID %d) exited with status %d\n", child1_pid, WEXITSTATUS(status));
    }

    printf("Parent is done waiting.\n");

    return 0;
}
