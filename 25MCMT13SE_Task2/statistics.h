#ifndef STATISTICS_H
#define STATISTICS_H

#include "student.h"
float calculateClassAverage(struct Student students[], int count);
float findHighestPercentage(struct Student students[], int count);
float findLowestPercentage(struct Student students[], int count);
void calculateGradeDistribution(struct Student students[], int count, struct GradeStatistics *stats);
float calculatePassPercentage(struct Student students[], int count);

#endif