/*
=====================================================================================================================================
Name : 1b.c
Author : Parag Dutt Sharma
Description : Create the following types of a files using (i) shell command (ii) system call
                b. hard link (link system call)
Date : 8th September 2023
=====================================================================================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main() {
    const char* source_path = "./example.txt";
    const char* hardlink_path = "./HardLinkSysCall";
    
    int result = link(source_path, hardlink_path);
    if (result == -1) {
        perror("Can't create hard link...");
        return 1;
    }
    
    return 0;
}


