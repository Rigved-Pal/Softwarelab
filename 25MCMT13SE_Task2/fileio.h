#ifndef FILEIO_H
#define FILEIO_H

#include "student.h"

int readFromFile(const char *filename, struct Student students[], int *count);
int writeToFile(const char *filename, struct Student students[], int count);
int exportCSV(const char *filename, struct Student students[], int count);

#endif 