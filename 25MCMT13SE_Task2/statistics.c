#include <string.h>
#include "statistics.h"

float calculateAverage(struct Student students[], int count) {
    if (count == 0) return 0.0;
    
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += students[i].percentage;
    }
    
    return total / count;
}

float HighestPercentage(struct Student students[], int count) {
    if (count == 0) return 0.0;
    
    float highest = students[0].percentage;
    for (int i = 1; i < count; i++) {
        if (students[i].percentage > highest) {
            highest = students[i].percentage;
        }
    }
    
    return highest;
}

float LowestPercentage(struct Student students[], int count) {
    if (count == 0) return 0.0;
    
    float lowest = students[0].percentage;
    for (int i = 1; i < count; i++) {
        if (students[i].percentage < lowest) {
            lowest = students[i].percentage;
        }
    }
    
    return lowest;
}

void GradeDistribution(struct Student students[], int count, 
                                 struct GradeStatistics *stats) {
    // Initialize all counts to 0
    stats->gradeO = 0;
    stats->gradeAPlus = 0;
    stats->gradeA = 0;
    stats->gradeBPlus = 0;
    stats->gradeB = 0;
    stats->gradeC = 0;
    stats->gradeD = 0;
    stats->gradeF = 0;
    
    // Count each grade
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].grade, "O") == 0) {
            stats->gradeO++;
        } else if (strcmp(students[i].grade, "A+") == 0) {
            stats->gradeAPlus++;
        } else if (strcmp(students[i].grade, "A") == 0) {
            stats->gradeA++;
        } else if (strcmp(students[i].grade, "B+") == 0) {
            stats->gradeBPlus++;
        } else if (strcmp(students[i].grade, "B") == 0) {
            stats->gradeB++;
        } else if (strcmp(students[i].grade, "C") == 0) {
            stats->gradeC++;
        } else if (strcmp(students[i].grade, "D") == 0) {
            stats->gradeD++;
        } else if (strcmp(students[i].grade, "F") == 0) {
            stats->gradeF++;
        }
    }
}

float PassPercentage(struct Student students[], int count) {
    if (count == 0) return 0.0;
    
    int passedCount = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].passed) {
            passedCount++;
        }
    }
    
    return ((float)passedCount / count) * 100.0;
}