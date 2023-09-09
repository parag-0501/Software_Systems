/*
=====================================================================================================================================
Name : 1c.c
Author : Parag Dutt Sharma
Description : Create the following types of a files using (i) shell command (ii) system call
                c. FIFO (mkfifo Library Function or mknod system call)
Date : 8th September 2023
=====================================================================================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    const char* fifo_path = "./fifo_example.txt";
    mode_t mode = 0666; // Permissions for the FIFO

    int result = mkfifo(fifo_path, mode);
    if (result == -1) {
        perror("Failed FIFO");
        return 1;
    }

    return 0;
}
