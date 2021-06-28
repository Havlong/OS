#include <stdio.h>
#include <unistd.h>
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
    char request[128];
    while (1) {
        int writeFD = open(fifo, O_WRONLY);
        fgets(request, 128, stdin);
        write(writeFD, request, 128);
        close(writeFD);

        int readFD = open(fifo, O_RDONLY);
        read(readFD, request, 128);
        puts(request);
        close(readFD);

        if (equal(request, "STOP\n")) {
            break;
        }
    }
    return 0;
}
