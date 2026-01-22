#ifndef VALIDATION_H
#define VALIDATION_H

#include "student.h"
int validateStudentID(const char *id, struct Student students[], int count);
int validateName(const char *name);
int validateMarks(float mark);
int isAlphanumeric(const char *str);
int isAlphabetic(const char *str);

#endif 