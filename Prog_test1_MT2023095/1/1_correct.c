#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main() {
    pid_t pid;
    off_t lastPos = 0; // Store the last read position in the file

    // Create a child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process (writer)

        int fd = open("shared.txt", O_WRONLY | O_CREAT | O_APPEND , 0644);
        if (fd == -1) {
            perror("Failed to open shared.txt for writing");
            exit(EXIT_FAILURE);
        }

        char message[100];
        int bytesRead;

        while (1) {
            // Read a message from the user
            bytesRead = read(STDIN_FILENO, message, sizeof(message));
            if (bytesRead == -1) {
                perror("Failed to read from STDIN");
                exit(EXIT_FAILURE);
            }

            // Write the message to the file
            if (write(fd, message, bytesRead) == -1) {
                perror("Failed to write to shared.txt");
                exit(EXIT_FAILURE);
            }

	    // Check if the user wants to exit
            if (bytesRead == 5 && strncmp(message, "exit\n", 5) == 0) {
                close(fd);
                return 0;
            }

        }

        close(fd);
    } 
    
    else {
        // Parent process (reader)

        while (1) {
            int fd = open("shared.txt", O_RDONLY);
            if (fd == -1) {
                perror("Failed to open shared.txt for reading");
                exit(EXIT_FAILURE);
            }

            // Set the file position indicator to the last known position
            lseek(fd, lastPos, SEEK_SET);

            char message[100];
            ssize_t bytesRead;

            while ((bytesRead = read(fd, message, sizeof(message) - 1)) > 0) {
                message[bytesRead] = '\0';
		
		// Check if the user exited
            	if (bytesRead == 5 && strncmp(message, "exit\n", 5) == 0) {
                	close(fd);
	                return 0;
        	}

                printf("Received: %s", message);
                lastPos += bytesRead; // Update the last known position
            }

            if (bytesRead == -1) {
                perror("Failed to read from shared.txt");
                exit(EXIT_FAILURE);
            }

            close(fd);
        }
    }

    return 0;
}

