#ifndef DISPLAY_H
#define DISPLAY_H

#include "student.h"
void displayReport(struct Student students[], int count);
void displayStats(struct Student students[], int count);
void displayDesk();

void displayDetails(struct Student *student);

#endif 