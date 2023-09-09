/*
=====================================================================================================================================
Name  :  14.c
Author  :  Parag Dutt Sharma
Description  :  Write a program to find the type of a file.
		a. Input should be taken from command line.
		b. Program should be able to identify any type of a file.
Date  :  8th September 2023
=====================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    struct stat fileStat;

    if (stat(filename, &fileStat) == -1) {
        printf("Error getting file information.\n");
        return 1;
    }

    if (S_ISREG(fileStat.st_mode)) {
        printf("%s: Regular file\n", filename);
    } 
    else if (S_ISDIR(fileStat.st_mode)) {
        printf("%s: Directory\n", filename);
    } 
    else if (S_ISLNK(fileStat.st_mode)) {
        printf("%s: Symbolic link\n", filename);
    } 
    else if (S_ISFIFO(fileStat.st_mode)) {
        printf("%s: FIFO (named pipe)\n", filename);
    } 
    else if (S_ISCHR(fileStat.st_mode)) {
        printf("%s: Character special file\n", filename);
    } 
    else if (S_ISBLK(fileStat.st_mode)) {
        printf("%s: Block special file\n", filename);
    } 
    else {
        printf("%s: Unknown file type\n", filename);
    }

    return 0;
}
