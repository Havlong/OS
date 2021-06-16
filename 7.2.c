#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void alarmHandler(int var) {
    puts("Enter 0 to stop wasting resources");
    int code;
    int count = scanf("%d", &code);
    if (count == 1 && code == 0)
        _exit(0);
    else
        alarm(5);
}

int main() {
    signal(SIGALRM, alarmHandler);
    alarm(5);
    while(1) ;
    return 0;
}