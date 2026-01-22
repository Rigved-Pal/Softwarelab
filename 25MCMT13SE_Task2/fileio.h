#ifndef FILEIO_H
#define FILEIO_H

#include "student.h"

int readStudentsFromFile(const char *filename, struct Student students[], int *count);
int writeStudentsToFile(const char *filename, struct Student students[], int count);
int exportToCSV(const char *filename, struct Student students[], int count);

#endif 