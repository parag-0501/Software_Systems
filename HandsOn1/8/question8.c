#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {

	if(argc != 2) {
		printf("Incorrect arguments");
		return 0;
	}
	int fd_read = open(argv[1], O_RDONLY);

	if(fd_read == -1) {
		printf("Unable to read or open a file");
	}

	char buf;

	while(1) {
		int read_file = read(fd_read, &buf, 1);
		if(read_file == 0)
			break;

		printf("%c",buf);
	}

	int fd_read_close = close(fd_read);

	return 0;
}

