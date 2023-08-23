#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
        int v = symlink("example.txt","SoftLinkSysCall");
        if(v<0) {
                perror("Failed Soft Link"); 
                return 1; 
        }
        int f = link("example.txt","HardLinkSysCall");
        if(f<0) {
                perror("Failed Hard Link"); 
                return 1;
        }
        int e = mknod("destFIFO",S_IFIFO,0);
        
        if(e<0) perror("Failed FIFO");
        
        return 0;
}

