#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    const char* fifo_path = "./fifo_example.txt";
    mode_t mode = 0666; // Permissions for the FIFO

    int result = mkfifo(fifo_path, mode);
    if (result == -1) {
        perror("Failed FIFO");
        return 1;
    }

    return 0;
}
