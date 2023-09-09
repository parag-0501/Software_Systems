/*
=====================================================================================================================================
Name  :  16a.c
Author  :  Parag Dutt Sharma
Description  :  Write a program to perform mandatory locking.
		a. Implement write lock
Date  :  8th September 2023
=====================================================================================================================================
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	struct flock lock;
	int fd;
	fd = open("db" , O_RDWR);
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("Before Entering Critical Section...\n");
	if(fcntl(fd, F_SETLKW, &lock)==-1) {
		close(fd);
		return 0;
	}
	printf("Inside the critical section...\n");
	printf("Enter to unlock...\n");
	getchar();
	printf("Unlocked...\n");
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("Finished...\n");
}
