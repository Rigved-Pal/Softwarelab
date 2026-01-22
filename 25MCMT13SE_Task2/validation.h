#ifndef VALIDATION_H
#define VALIDATION_H

#include "student.h"
int StudentIDvalidation(const char *id, struct Student students[], int count);
int validateStudentName(const char *name);
int validateStudentMarks(float mark);
int Isalphanum(const char *str);
int isAlphabet(const char *str);

#endif 