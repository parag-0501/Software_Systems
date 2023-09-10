#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	pid_t fdFile = open("shared.txt" , O_RDWR);
	int len=0;

	if(fdFile==-1) {
		perror("Error opening the file.\n");
		exit(1);
	}

	pid_t fdFork = fork();

	if(fdFork == -1) {
		perror("Error creating Child Process.\n");
                exit(1);
	}

	//In child
	if(fdFork == 0) { 
		char buff[1024];
		lseek(fdFile , SEEK_END , 1);
		
		size_t r = read(0 , &buff , sizeof(buff));
		if(r != sizeof(buff))
			perror("Read in child");
		
		size_t w = write(fdFile , &buff , sizeof(buff));
		if(w != sizeof(buff))
                        perror("Write in child");
		
		len += sizeof(buff);
	}

	//In parent
	else {
		lseek(fdFile , SEEK_SET , len);
		char buff[1024];
                
		size_t r = read(fdFile , &buff , sizeof(buff));
		if(r != sizeof(buff))
                        perror("Read in parent");
		
		size_t w = write(1 , &buff , sizeof(buff));
		if(w != sizeof(buff))
                        perror("Write in parent");
	}

	return 0;
}
