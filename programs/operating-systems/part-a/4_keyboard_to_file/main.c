#include <stdio.h>   // ssize_t
#include <fcntl.h>   // open and its flags
#include <unistd.h>  // read, close

int main() {
    char file_name[100];
    char buffer[1000];

    printf("Enter a filename: ");
    scanf("%s", file_name);

    int fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0664);

    if (fd == -1) {
        perror("open error");
        return 1;
    }

    printf("Enter the contenet to be written:\n");

    while(1) {
        ssize_t n = read(0, buffer, sizeof(buffer));

        if (n > 0)   write(fd, buffer, n);
        if (n == 0)  break;

        if (n == -1) {
            perror("read error");
            close(fd);
            return 1;
        }
    }

    close(fd);
    printf("Content writtten to %s\n", file_name);

    return 0;
}
