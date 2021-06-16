#include <stdio.h>
#include <dirent.h>

int main() {
    char dirName[100];
    scanf("%100s", dirName);
    FILE *file = fopen("files.txt", "w");
    DIR *dir = opendir(dirName);
    struct dirent* curEntry;
    while ((curEntry = readdir(dir)) != NULL) {
        fprintf(file, "%s\n", curEntry->d_name);
    }
    closedir(dir);
    return 0;
}
