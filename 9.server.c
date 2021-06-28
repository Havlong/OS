#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

struct message {
    long type;
    char text[10];
};

int main() {
    struct message buf;
    key_t key = ftok("result.txt", 0);
    int fd = msgget(key, IPC_CREAT | 0644);
    while (1) {
        fd = msgrcv(fd, &buf, 10, 1, 0);
        int limit;
        sscanf(buf.text, "%d", &limit);
        system("who | wc -l > result.txt");
        FILE *file = fopen("result.txt", "r");
        int result;
        fscanf(file, "%d", &result);
        fclose(file);
        if (result > limit) {
            printf("Users amount has exceeded the %d users limit\n", limit);
        }
    }
}
