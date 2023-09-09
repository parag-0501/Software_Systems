/*
=====================================================================================================================================
Name  :  15.c
Author  :  Parag Dutt Sharma
Description  :  Write a program to display the environmental variable of the user (use environ).
Date  :  8th September 2023
=====================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int check(char *a){
	return a[0]=='U' && a[1]=='S' && a[4]=='=';
}


int main() {
    for (int i = 0; environ[i] != NULL; i++)
        if(check(environ[i]))
	    printf("%s\n", environ[i]);
    

    return 0;
}
