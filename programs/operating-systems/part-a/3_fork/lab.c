#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>   // for wait()

int main() {
    int pid;
    pid = fork();

    if (pid < 0) {
        printf("fork error\n");
        return 1;
    }
    else if (pid == 0) {
        // child process
        printf("forked child process running with process id = %d\n", getpid());
        sleep(5);
    }
    else {
        // parent process
        printf("parent process executing, waiting for child to finish...\n");
        wait(NULL);  // wait for any child process to terminate
        printf("child process finished, parent continues.\n");
    }
    return 0;
}
