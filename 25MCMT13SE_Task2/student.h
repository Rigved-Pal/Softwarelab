#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50
#define MAX_ID_LEN 20
#define NUM_SUBJECTS 5
#define PASSING_PERCENTAGE 50.0
struct Student {
    char id[MAX_ID_LEN];
    char name[MAX_NAME_LEN];
    float marks[NUM_SUBJECTS];
    float total;
    float percentage;
    char grade[5];
    float cgpa;
    int passed;
};
struct GradeStatistics {
    int gradeO;
    int gradeAPlus;
    int gradeA;
    int gradeBPlus;
    int gradeB;
    int gradeC;
    int gradeD;
    int gradeF;
};

#endif 