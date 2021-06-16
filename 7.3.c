#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <malloc.h>

int main() {
    sigset_t *set = malloc(sizeof(sigset_t));
    sigprocmask(0, NULL, set);
    if (!sigismember(set, SIGINT))
        sigaddset(set, SIGINT);
    else
        sigdelset(set, SIGINT);
    return 0;
}