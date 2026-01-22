#include "computation.h"
#include <string.h>


void calculateResults(struct Student *student) {
    student->total = 0.0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        student->total += student->marks[i];
    }
    
    // Calculate Student percentage
    student->percentage = (student->total / (NUM_SUBJECTS * 100.0)) * 100.0;
    
    // Check Student passing status
    student->passed = checkPassStatus(student);
    
    // CGPA Calculation
    student->cgpa = CGPAcalculate(student->percentage);

    // Assigned grade
    assignedGrade(student);
    
}

void assignedGrade(struct Student *student) {
    float per = student->percentage;
    
    // If grade is F
    if (!student->passed) {
        strcpy(student->grade, "F");
        student->cgpa = 0.0;
        return;
    }
    
    if (per >= 90.0) {
        strcpy(student->grade, "O");
    } else if (per >= 85.0) {
        strcpy(student->grade, "A+");
    } else if (per >= 75.0) {
        strcpy(student->grade, "A");
    } else if (per >= 65.0) {
        strcpy(student->grade, "B+");
    } else if (per >= 60.0) {
        strcpy(student->grade, "B");
    } else if (per >= 55.0) {
        strcpy(student->grade, "C");
    } else if (per >= 50.0) {
        strcpy(student->grade, "D");
    } else {
        strcpy(student->grade, "F");
    }
}

float CGPAcalculate(float percentage) {
    return percentage / 10.0;
}

int checkPassStatus(struct Student *student) {
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        if (student->marks[i] < PASSING_PERCENTAGE) {
            return 0;  
        }
    }
    return 1; 
}