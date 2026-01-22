#include <stdio.h>
#include "display.h"
#include "statistics.h"

void displayReport(struct Student students[], int count) {
    printf("\n==================== STUDENT RESULT REPORT ====================\n\n");
    
    printf("%-10s %-15s %-7s %-7s %-7s %-7s %-7s %-8s %-9s %-6s %-6s\n",
           "ID", "Name", "Sub1", "Sub2", "Sub3", "Sub4", "Sub5", 
           "Total", "Percent", "Grade", "CGPA");
    
    printf("------------------------------------------------------------------------");
    printf("----------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-10s %-15s ", students[i].id, students[i].name);
        
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("%-7.2f ", students[i].marks[j]);
        }
        
        printf("%-8.2f %-9.2f %-6s %-6.2f\n",
               students[i].total,
               students[i].percentage,
               students[i].grade,
               students[i].cgpa);
    }
    
    printf("========================================================================");
    printf("==========\n");
}

void displayStats(struct Student students[], int count) {
    if (count == 0) {
        printf("No students to display statistics.\n");
        return;
    }
    
    // Calculate statistics
    float avgPercentage = calculateAverage(students, count);
    float highest = HighestPercentage(students, count);
    float lowest = LowestPercentage(students, count);
    float passPercent = PassPercentage(students, count);
    
    struct GradeStatistics stats;
    GradeDistribution(students, count, &stats);
    
    printf("\n==================== CLASS STATISTICS ====================\n\n");
    printf("Total Students           : %d\n", count);
    printf("Class Average Percentage : %.2f%%\n", avgPercentage);
    printf("Highest Percentage       : %.2f%%\n", highest);
    printf("Lowest Percentage        : %.2f%%\n", lowest);
    printf("Pass Percentage          : %.2f%%\n", passPercent);
    
    printf("\n--- Grade Distribution ---\n");
    printf("Grade O  (>= 90%%)  : %d student(s)\n", stats.gradeO);
    printf("Grade A+ (85-90%%) : %d student(s)\n", stats.gradeAPlus);
    printf("Grade A  (75-85%%) : %d student(s)\n", stats.gradeA);
    printf("Grade B+ (65-75%%) : %d student(s)\n", stats.gradeBPlus);
    printf("Grade B  (60-65%%) : %d student(s)\n", stats.gradeB);
    printf("Grade C  (55-60%%) : %d student(s)\n", stats.gradeC);
    printf("Grade D  (50-55%%) : %d student(s)\n", stats.gradeD);
    printf("Grade F  (< 50%%)  : %d student(s)\n", stats.gradeF);
    printf("==========================================================\n");
}

void displayDesk() {
    printf("\n========== Student Result Processing System ==========\n");
    printf("1. Display Student Report\n");
    printf("2. Display Statistics\n");
    printf("3. Export to CSV\n");
    printf("4. Save Report to File\n");
    printf("5. Search Student by ID\n");
    printf("6. Exit\n");
    printf("======================================================\n");
    printf("Enter your choice: ");
}

void displayDetails(struct Student *student) {
    printf("\n----- Student Details -----\n");
    printf("ID         : %s\n", student->id);
    printf("Name       : %s\n", student->name);
    printf("Marks      : ");
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("%.2f ", student->marks[i]);
    }
    printf("\nTotal      : %.2f\n", student->total);
    printf("Percentage : %.2f%%\n", student->percentage);
    printf("Grade      : %s\n", student->grade);
    printf("CGPA       : %.2f\n", student->cgpa);
    printf("Status     : %s\n", student->passed ? "PASS" : "FAIL");
    printf("---------------------------\n");
}