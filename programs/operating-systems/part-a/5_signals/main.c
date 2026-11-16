#include <stdio.h>
#include <stdlib.h>  // exit()
#include <signal.h>  // signal(), SIGINT and other signals
#include <unistd.h>  // alarm(), getpid()

void hy_handler(int sig) {
    if (sig == SIGTERM) {
        printf("Caught a terminate signal to exit\n");
        exit(0);
    }
    if (sig == SIGINT)   printf("Caught an Interrupt signal\n");
    if (sig == SIGHUP)   printf("Caught a terminal hangup\n");
    if (sig == SIGALRM)  printf("Caught alarm signal\n");
    if (sig == SIGUSR1)  printf("Caught user defined signal\n");
}

int main() {
    // signal(SIGINT, hy_handler);
    signal(SIGTERM, hy_handler);
    signal(SIGINT, hy_handler);
    signal(SIGHUP, hy_handler);
    signal(SIGALRM, hy_handler);
    signal(SIGUSR1, hy_handler);

    alarm(4);

    printf("Program running with process id: %d\n", getpid());

    while(1) {
        printf("Waiting for signals...\n");
        sleep(5);
    }

    return 0;
}
