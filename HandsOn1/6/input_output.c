#include <stdio.h>
#include <unistd.h>

int main() {
    char buffer[1024];  // Buffer to hold input

    size_t bytesRead;
    while ( (bytesRead = read( STDIN_FILENO, buffer, sizeof(buffer) )) > 1 ) {
        // Write the contents of the buffer to STDOUT
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    if (bytesRead == -1) {
        perror("Error reading from STDIN");
        return 1;
    }

    return 0;
}
