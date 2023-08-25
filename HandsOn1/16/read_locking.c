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
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("Before Entering Critical Section...\n");
	fcntl(fd, F_SETLKW, &lock);
	printf("Inside the critical section...\n");
	printf("Enter to unlock...\n");
	getchar();
	printf("Unlocked...\n");
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("Finished...\n");
}
