#ifndef STATISTICS_H
#define STATISTICS_H

#include "student.h"
float calculateAverage(struct Student students[], int count);
float HighestPercentage(struct Student students[], int count);
float LowestPercentage(struct Student students[], int count);
void GradeDistribution(struct Student students[], int count, struct GradeStatistics *stats);
float PassPercentage(struct Student students[], int count);

#endif