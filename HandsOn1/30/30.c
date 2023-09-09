/*
=====================================================================================================================================
Name  :  30.c
Author  :  Parag Dutt Sharma
Description  :  Write a program to run a script at a specific time using a Daemon process.
Date  :  8th September 2023
=====================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

int main(int argc , char *argv[]) {
	if(argc!=3) {
		printf("Incomplete Argumrnts : Provide hour and minute as well in hh(0-23) mm(0-59) formate\n");
		exit(0);
	}
	int pid = fork();
	if(pid == 0) {
		printf("PID : %d -- ",getpid());
		while(1) {
			time_t curr = time(NULL);
			struct tm *tm_struct = localtime(&curr);
			int h = tm_struct->tm_hour;
			int m = tm_struct->tm_min;

			int inputTime = atoi(argv[1]);
			int inputMinute = atoi(argv[2]);
			if(inputTime == h && inputMinute == m) {
				printf("Hello! This is Daemon Process!\n");
				exit(0);
				break;
			}
		}
	}
	else exit(0);
	return 0;
}
