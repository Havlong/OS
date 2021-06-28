#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();
    if (pid == 0)
        execl("/bin/sh","/bin/sh", "-c", "ps > processes.txt", NULL);
    else if (pid > 0) {
        sleep(1);
        execl("/bin/sh", "/bin/sh", "-c", "ps >> processes.txt", NULL);
    } else {
        perror("Fork error");
        return -1;
    }
    return 0;
}
