/*
=====================================================================================================================================
Name : 1a.c
Author : Parag Dutt Sharma
Description : Create the following types of a files using (i) shell command (ii) system call
		a. soft link (symlink system call)
Date : 8th September 2023
=====================================================================================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main() {
    const char* source_path = "./example.txt";
    const char* symlink_path = "./SoftLinkSysCall";

    int result = symlink(source_path, symlink_path);
    if (result == -1) {
        perror("Can't creat soft link...");
        return 1;
    }

    return 0;
}

