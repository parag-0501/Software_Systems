#include <unistd.h>
#include <stdio.h>

int main() {
    const char* source_path = "./example.txt";
    const char* symlink_path = "./SoftLinkSysCall";

    int result = symlink(source_path, symlink_path);
    if (result == -1) {
        perror("Can't creat soft link...");
        return 1;
    }

    return 0;
}

