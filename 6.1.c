#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void readString(char *buffer, int maxSize, int fd) {
    for(int i = 0; i < maxSize - 1; ++i) {
        read(fd, buffer + i, 1);
        if (buffer[i] == '\n' || buffer[i] == -1){
            buffer[i] = '\0';
            return;
        }
    }
    buffer[maxSize - 1] = '\0';
}

const int bufferSize = 40;

int main() {
    int fd = open("students.txt", O_WRONLY | O_CREAT, 0777);
    if (fd == -1) {
        perror("Couldn't obtain students.txt write file desc");
        return 0;
    }
    int studentsAmount;
    scanf("%d\n", &studentsAmount);
    char studentInfo[bufferSize];
    for (int i = 0; i < studentsAmount; ++i) {
        fgets(studentInfo, bufferSize, stdin);
        write(fd, studentInfo, strlen(studentInfo));
    }
    close(fd);

    fd = open("students.txt", O_RDONLY | O_CREAT, 0777);
    if (fd == -1) {
        perror("Couldn't obtain students.txt read file desc");
        return 0;
    }
    int wfd = open("xStudents.txt", O_WRONLY | O_CREAT, 0777);
    if (wfd == -1) {
        perror("Couldn't obtain xStudents.txt write file desc");
        return 0;
    }

    char lastName[bufferSize];
    for(int i = 0; i < studentsAmount; ++i) {
        readString(studentInfo, bufferSize, fd);
        int grade;
        sscanf(studentInfo, "%s%d", lastName, &grade);
        if (grade == 5) {
            write(wfd, lastName, strlen(lastName));
            write(fd, "\n", strlen("\n"));
        }
    }
    close(fd);
    close(wfd);
    return 0;
}
