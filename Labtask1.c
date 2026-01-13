#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define Max_Student 100
#define Total_Subject 5

struct Student{
    char id[20];
    char name[50];
    float marks[Total_Subject];
    float Total;
    float percentage;
    char grade[5];
    float cgpa;
};

struct Student Students[Max_Student];
int total_Students=0;

void readFromFile();
int checkID