/*
=====================================================================================================================================
Name  :  8.c
Author  :  Parag Dutt Sharma
Description  :  Write a program to open a file in read only mode, read line by line and display each line as it is read.
		Close the file when end of file is reached.
Date  :  8th September 2023
=====================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE_SIZE 1024

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Incorrect arguments\n");
        return 1;
    }

    int fd_read = open(argv[1], O_RDONLY);
    if (fd_read == -1) {
        perror("Unable to open the file");
        return 1;
    }

    char buf[MAX_LINE_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(fd_read, buf, MAX_LINE_SIZE)) > 0) {
	write(0, buf, bytes_read);
    }

    if (bytes_read == -1) {
        perror("Error reading the file");
    }

    close(fd_read);

    return 0;
}
