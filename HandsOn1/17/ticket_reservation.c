#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
	struct{
		int ticket_no;
	} db;
	struct flock lock;
	int fd;
	fd = open ("db", O_RDWR); 
	read (fd, &db, sizeof (db));
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0; 
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("Before entering into critical section\n"); 
	fcntl(fd, F_SETLKW, &lock);
	printf("Current ticket number: %d\n", db.ticket_no);
	db.ticket_no++;    //updating ticket value
	lseek (fd, 0L, SEEK_SET); 
	printf("Inside the critical section....\n");
	printf("Enter to unlock..\n"); 
	write (fd, &db, sizeof(db)); //updating db
	getchar();
	lock.l_type = F_UNLCK; 
	printf("Unlocked\n");
	fcntl(fd, F_SETLK, &lock);
	printf("Finish\n");
}
