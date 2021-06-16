#include <stdio.h>


int main() {
    FILE *studentsOutput = fopen("students.txt", "w");
    int studentsAmount;
    scanf("%d\n", &studentsAmount);
    char studentInfo[40];
    for (int i = 0; i < studentsAmount; ++i) {
        fgets(studentInfo, 40, stdin);
        fputs(studentInfo, studentsOutput);
    }
    fclose(studentsOutput);

    FILE *studentsInput = fopen("students.txt", "r");
    FILE *excOutput = fopen("xStudents.txt", "w");
    for (int i = 0; i < studentsAmount; ++i) {
        int grade;
        fscanf(studentsInput, "%40s%d\n", studentInfo, &grade);
        if (grade == 5)
            fputs(studentInfo, excOutput);
    }
    fclose(studentsInput);
    fclose(excOutput);
    return 0;
}
