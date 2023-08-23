#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	const char *file_name = "file_desc.txt";
	int file_descriptor1 = creat(file_name, 0644);
	int file_descriptor2 = creat(file_name, 0644);
	int file_descriptor3 = creat(file_name, 0644);


	if(file_descriptor1 == -1) {
		perror("Creat Failed");
		return 1;
	}

	printf("File '%s' is created with file descriptor: %d\n", file_name, file_descriptor1);
	printf("File '%s' is created with file descriptor: %d\n", file_name, file_descriptor2);
	printf("File '%s' is created with file descriptor: %d\n", file_name, file_descriptor3);

        close(file_descriptor2);
	close(file_descriptor3);

	if(close(file_descriptor1) == -1) {
		perror("Close Failed");
		return 1;
	}

	return 0;
}
