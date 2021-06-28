#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message {
    long type;
    char text[10];
};

int main() {
    int limit;
    scanf("%d", &limit);

    struct message buf;
    buf.type = 1;
    sprintf(buf.text, "%d", limit);

    key_t key = ftok("result.txt", 0);
    int fd = msgget(key, IPC_CREAT | 0644);
    int len = strlen(buf.text);
    fd = msgsnd(fd, &buf, len, 0);
    if (fd != -1)
        puts("Request sent");
    return 0;
}
