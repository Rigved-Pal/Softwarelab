#ifndef COMPUTATION_H
#define COMPUTATION_H

#include "student.h"
void calculateResults(struct Student *student);
void assignedGrade(struct Student *student);
float CGPAcalculate(float percentage);
int checkPassStatus(struct Student *student);

#endif 