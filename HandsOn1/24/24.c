/*
=====================================================================================================================================
Name  :  24.c
Author  :  Parag Dutt Sharma
Description  :  Write a program to create an orphan process.
Date  :  8th September 2023
=====================================================================================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{	
	int pid = fork();

	if (pid) {
		printf("In parent process\nPlease wait for child process to get executed\nIt is an orphan now...\n");
	}

	else {
		sleep(10);
		printf("In child process\n");
	}

	return 0;
}
