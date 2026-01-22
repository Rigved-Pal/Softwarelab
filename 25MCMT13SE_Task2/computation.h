#ifndef COMPUTATION_H
#define COMPUTATION_H

#include "student.h"
void calculateStudentResults(struct Student *student);
void assignGrade(struct Student *student);
float calculateCGPA(float percentage);
int checkPassingStatus(struct Student *student);

#endif 