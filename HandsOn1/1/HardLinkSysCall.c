#include <unistd.h>
#include <stdio.h>

int main() {
    const char* source_path = "./example.txt";
    const char* hardlink_path = "./HardLinkSysCall";
    
    int result = link(source_path, hardlink_path);
    if (result == -1) {
        perror("Can't create hard link...");
        return 1;
    }
    
    return 0;
}


