#include <stdio.h>
#include <unistd.h>    // fork, getpid, pid_t (sys/types also)
#include <sys/wait.h>  // wait
#include <stdlib.h>    // exit

int main() {

    printf("Parent Process ID: %d\n", getpid());
    printf("--------------------------------\n");

    for (int i = 0; i < 5; i++) {
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork failed");
            return 1;
        }

        // clild process
        if (pid == 0) {
            printf("child: %d | PID: %d | Parent PID: %d\n",
                   i + 1, getpid(), getppid());
            exit(0);
        }
    }

    // parent wait for all 5 children
    for (int i = 0; i < 5; i++) {
        wait(NULL);
    }

    printf("--------------------------------\n");
    printf("Parent: All children have terminated.\n");

    return 0;
}
