#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define OUTPUT "fifo1"
#define INPUT "fifo2"

char fileName[256];

int main(int argc, char const *argv[])
{
    ssize_t n;
    char buffer[512];
    int readfd, writefd;
    printf("Trying to Connect to Server.\n");
    writefd = open(OUTPUT, O_WRONLY, 0);
    readfd = open(INPUT, O_RDONLY, 0);
    printf("Connected.\n");
    printf("Enter filename: ");
    scanf("%s", fileName);
    write(writefd, fileName, strlen(fileName));
    printf("Waiting for Server to reply.\n");
    while ((n = read(readfd, buffer, 512)) > 0)
        write(1, buffer, n);
    close(readfd);
    close(writefd);
    return 0;
}
