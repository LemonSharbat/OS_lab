#include <stdio.h>
#include <fcntl.h>    // open()
#include <unistd.h>   // read()

int main() {
    char file_name[100];

    printf("Enter file name: ");
    scanf("%s", file_name);

    int fd = open(file_name, O_RDONLY);

    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    char buffer[1000];
    ssize_t fsize = read(fd, buffer, sizeof(buffer) - 1);   // leave a space for null termination...

    if (fsize == -1) {
        perror("Error reading the file");
        close(fd);
        return 1;
    }

    buffer[fsize] = '\0';

    printf("File contents are: \n%s\n", buffer);
    close(fd);

    return 0;
}
