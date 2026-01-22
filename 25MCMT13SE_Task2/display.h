#ifndef DISPLAY_H
#define DISPLAY_H

#include "student.h"
void displayStudentReport(struct Student students[], int count);
void displayStatistics(struct Student students[], int count);
void displayMenu();

void displayStudentDetails(struct Student *student);

#endif 