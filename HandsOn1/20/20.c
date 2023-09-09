/*
=====================================================================================================================================
Name  :  20.c
Author  :  Parag Dutt Sharma
Description  :  Find out the priority of your running program. Modify the priority with nice command.
Date  :  8th September 2023
=====================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    int priority;
    pid_t pid = getpid(); // Get the process ID of the current program

    // Get the current priority of the process
    priority = getpriority(PRIO_PROCESS, pid);
    if (priority == -1) {
        perror("getpriority");
        return 1;
    }

    printf("Current priority of the process (PID %d): %d\n", pid, priority);

    // Change the priority using the nice command
    int new_priority;
    scanf("%d" , &new_priority); // Change this to the desired priority value
    if (nice(new_priority) == -1) {
        perror("nice");
        return 1;
    }

    // Get the updated priority after using nice
    priority = getpriority(PRIO_PROCESS, pid);
    if (priority == -1) {
        perror("getpriority");
        return 1;
    }

    printf("Updated priority of the process (PID %d): %d\n", pid, priority);

    return 0;
}

