#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileio.h"
#include "validation.h"
#include "computation.h"

int readFromFile(const char *filename, struct Student students[], int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file '%s'\n", filename);
        return -1;
    }
    
    char line[256];
    int lineNum = 0;
    *count = 0;
    
    while (fgets(line, sizeof(line), file) && *count < MAX_STUDENTS) {
        lineNum++;
        
        // Skip comments and empty lines
        if (line[0] == '#' || line[0] == '\n' || line[0] == '\r') {
            continue;
        }
        
        struct Student temp;
        char tempID[MAX_ID_LEN], tempName[MAX_NAME_LEN];
        float m1, m2, m3, m4, m5;
        
        // Parse line
        int result = sscanf(line, "%s %s %f %f %f %f %f", 
                           tempID, tempName, &m1, &m2, &m3, &m4, &m5);
        
        if (result != 7) {
            printf("Line %d: Incomplete data - skipped\n", lineNum);
            continue;
        }
        
        // Validate ID
        if (!StudentIDvalidation(tempID, students, *count)) {
            printf("Line %d: Invalid/Duplicate ID '%s' - rejected\n", lineNum, tempID);
            continue;
        }
        
        // Validate name
        if (!validateStudentName(tempName)) {
            printf("Line %d: Invalid name '%s' - rejected\n", lineNum, tempName);
            continue;
        }
        
        // Store and validate marks
        float marks[NUM_SUBJECTS] = {m1, m2, m3, m4, m5};
        int validMarks = 1;
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            if (!validateStudentMarks(marks[i])) {
                printf("Line %d: Invalid marks %.2f - rejected\n", lineNum, marks[i]);
                validMarks = 0;
                break;
            }
            temp.marks[i] = marks[i];
        }
        
        if (!validMarks) {
            continue;
        }
        
        // Copy validated data
        strcpy(temp.id, tempID);
        strcpy(temp.name, tempName);
        
        // Calculate results
        calculateResults(&temp);
        
        // Add to array
        students[*count] = temp;
        (*count)++;
    }
    
    fclose(file);
    return 0;
}

int writeToFile(const char *filename, struct Student students[], int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Cannot create file '%s'\n", filename);
        return -1;
    }
    
    fprintf(file, "Student Result Report\n");
    fprintf(file, "=====================\n\n");
    
    fprintf(file, "%-10s %-15s %-8s %-8s %-10s %-6s %-6s\n",
            "ID", "Name", "Total", "Percent", "Grade", "CGPA", "Status");
    fprintf(file, "-------------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%-10s %-15s %-8.2f %-8.2f %-10s %-6.2f %-6s\n",
                students[i].id,
                students[i].name,
                students[i].total,
                students[i].percentage,
                students[i].grade,
                students[i].cgpa,
                students[i].passed ? "PASS" : "FAIL");
    }
    
    fclose(file);
    printf("Results saved to '%s'\n", filename);
    return 0;
}

int exportCSV(const char *filename, struct Student students[], int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Cannot create CSV file '%s'\n", filename);
        return -1;
    }
    
    // Write CSV header
    fprintf(file, "ID,Name,Sub1,Sub2,Sub3,Sub4,Sub5,Total,Percentage,Grade,CGPA,Status\n");
    
    // Write student data
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%s,%.2f,%s\n",
                students[i].id,
                students[i].name,
                students[i].marks[0],
                students[i].marks[1],
                students[i].marks[2],
                students[i].marks[3],
                students[i].marks[4],
                students[i].total,
                students[i].percentage,
                students[i].grade,
                students[i].cgpa,
                students[i].passed ? "PASS" : "FAIL");
    }
    
    fclose(file);
    printf("CSV exported to '%s'\n", filename);
    return 0;
}