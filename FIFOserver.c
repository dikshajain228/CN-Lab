#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define INPUT "fifo1"
#define OUTPUT "fifo2"
#define PERMISSION 0666

char fileName[256];

int main(int argc, char const *argv[])
{
    ssize_t n;
    char buffer[512];
    int readfd, writefd, fd;
    if ((mkfifo(INPUT, PERMISSION)) < 0)
        printf("Cannot create input FIFO.\n");
    if ((mkfifo(OUTPUT, PERMISSION)) < 0)
        printf("Cannot create output FIFO.\n");
    printf("Waiting for connection request.\n");
    readfd = open(INPUT, O_RDONLY, 0);
    writefd = open(OUTPUT, O_WRONLY, 0);
    printf("Connection Established.\n");
    read(readfd, fileName, 255);
    printf("Client requested file %s.\n", fileName);
    if ((fd = open(fileName, O_RDONLY)) < 0)
    {
        strcpy(buffer, "File does not exist.\n");
        write(writefd, buffer, strlen(buffer));
    }
    else
    {
        while ((n = read(fd, buffer, 512)) > 0)
            write(writefd, buffer, n);
    }
    close(readfd);
    close(writefd);
    return 0;
}
