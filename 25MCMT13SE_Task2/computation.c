/*
 * computation.c
 * Implementation of computation module
 */

#include <string.h>
#include "computation.h"

void calculateStudentResults(struct Student *student) {
    // Calculate total marks
    student->total = 0.0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        student->total += student->marks[i];
    }
    
    // Calculate percentage
    student->percentage = (student->total / (NUM_SUBJECTS * 100.0)) * 100.0;
    
    // Check passing status
    student->passed = checkPassingStatus(student);
    
    // Assign grade
    assignGrade(student);
    
    // Calculate CGPA
    student->cgpa = calculateCGPA(student->percentage);
}

void assignGrade(struct Student *student) {
    float per = student->percentage;
    
    // If failed in any subject, grade is F
    if (!student->passed) {
        strcpy(student->grade, "F");
        student->cgpa = 0.0;
        return;
    }
    
    // Assign grade based on percentage
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

float calculateCGPA(float percentage) {
    return percentage / 10.0;
}

int checkPassingStatus(struct Student *student) {
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        if (student->marks[i] < PASSING_PERCENTAGE) {
            return 0;  // Failed in at least one subject
        }
    }
    return 1;  // Passed all subjects
}