#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

void timer_handler(int signo) {
    printf("ITIMER_VIRTUAL Timer Expired\n");
}

int main() {
    struct itimerval timer;
    
    // Set the timer to expire after 10 seconds and 10 microseconds
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    
    // Set the interval for repeating the timer
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;
    
    // Register the timer handler function
    signal(SIGVTALRM, timer_handler);
    
    // Start the timer
    if(setitimer(ITIMER_VIRTUAL, &timer, NULL)==-1) {
	    perror("Error in setting timer");
	    exit(1);
    }
    
    // Wait for the timer to expire
    while (1) {
    }
    
    return 0;
}

