#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int equal(const char *a, const char *b) {
    int i = 0;
    for (; a[i] != '\0' && b[i] != '\0'; ++i) {
        if (a[i] != b[i])
            return 0;
    }
    return a[i] == b[i];
}

int main() {
    char *fifo = "/tmp/HavlongApp";
    unlink(fifo);
    int result = mkfifo(fifo, S_IRWXU | S_IRWXG);
    if (result == -1)
        return -1;
    char request[128];
    while (1) {
        int readFD = open(fifo, O_RDONLY);
        read(readFD, request, 128);
        puts(request);
        close(readFD);


        int writeFD = open(fifo, O_WRONLY);
        fgets(request, 128, stdin);
        write(writeFD, request, 128);
        close(writeFD);

        if (equal(request, "STOP\n")) {
            break;
        }
    }
    unlink(fifo);
    return 0;
}
