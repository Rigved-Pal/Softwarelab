/*
 Name- Rigved Pal
 Registration number- 25MCMT13
 Software Engineering Lab - Task 1
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define Total_Subjects 5
#define MAX_STUDENTS 100

// Student structure
struct Student {
    char id[20];
    char name[50];
    float marks[Total_Subjects];
    float total;
    float percentage;
    char grade[5];
    float cgpa;
};

// Global variables
struct Student students[MAX_STUDENTS];
int totalStudents = 0;

// Function declarations
void readFromFile();
int checkID(char id[]);
int checkName(char name[]);
int checkMarks(float mark);
void calculateTotal(int index);
void assignGrade(int index);
void displayTable();
void showStats();

int main() {
    printf("\n========== Student Result Processing System ==========\n\n");
    
    readFromFile();
    
    if(totalStudents == 0) {
        printf("No valid records found!\n");
        return 0;
    }
    
    printf("Total students processed: %d\n\n", totalStudents);
    
    displayTable();
    showStats();
    
    return 0;
}

// Read student data from file
void readFromFile() {
    FILE *fp;
    fp = fopen("students.txt", "r");
    
    if(fp == NULL) {
        printf("Error! Could not open students.txt\n");
        printf("Please create students.txt file with student data\n");
        printf("Format: ID Name Mark1 Mark2 Mark3 Mark4 Mark5\n");
        return;
    }
    
    char line[200];
    int lineNo = 0;
    
    while(fgets(line, sizeof(line), fp) != NULL) {
        lineNo++;
        
        // skip comments and empty lines
        if(line[0] == '#' || line[0] == '\n') {
            continue;
        }
        
        char tempID[20], tempName[50];
        float m1, m2, m3, m4, m5;
        
        // read data from line
        int result = sscanf(line, "%s %s %f %f %f %f %f", 
                           tempID, tempName, &m1, &m2, &m3, &m4, &m5);
        
        if(result != 7) {
            printf("Line %d: Incomplete data - skipped\n", lineNo);
            continue;
        }
        
        // validate ID
        if(!checkID(tempID)) {
            printf("Line %d: Invalid ID '%s' - rejected\n", lineNo, tempID);
            continue;
        }
        
        // check for duplicate ID
        int duplicate = 0;
        for(int i = 0; i < totalStudents; i++) {
            if(strcmp(students[i].id, tempID) == 0) {
                duplicate = 1;
                break;
            }
        }
        if(duplicate) {
            printf("Line %d: Duplicate ID '%s' - rejected\n", lineNo, tempID);
            continue;
        }
        
        // validate name
        if(!checkName(tempName)) {
            printf("Line %d: Invalid name '%s' - rejected\n", lineNo, tempName);
            continue;
        }
        
        // validate marks
        float tempMarks[5] = {m1, m2, m3, m4, m5};
        int validMarks = 1;
        for(int i = 0; i < 5; i++) {
            if(!checkMarks(tempMarks[i])) {
                printf("Line %d: Invalid marks %.2f - rejected\n", lineNo, tempMarks[i]);
                validMarks = 0;
                break;
            }
        }
        
        if(!validMarks) {
            continue;
        }
        
        // all validations passed, add student
        strcpy(students[totalStudents].id, tempID);
        strcpy(students[totalStudents].name, tempName);
        for(int i = 0; i < 5; i++) {
            students[totalStudents].marks[i] = tempMarks[i];
        }
        
        calculateTotal(totalStudents);
        assignGrade(totalStudents);
        
        totalStudents++;
        
        if(totalStudents >= MAX_STUDENTS) {
            printf("Maximum student limit reached!\n");
            break;
        }
    }
    
    fclose(fp);
}

// Check if ID is valid (alphanumeric only)
int checkID(char id[]) {
    int len = strlen(id);
    if(len == 0) return 0;
    
    for(int i = 0; i < len; i++) {
        if(!isalnum(id[i])) {
            return 0;
        }
    }
    return 1;
}

// Check if name is valid (alphabets only)
int checkName(char name[]) {
    int len = strlen(name);
    if(len == 0) return 0;
    
    for(int i = 0; i < len; i++) {
        if(!isalpha(name[i])) {
            return 0;
        }
    }
    return 1;
}

// Check if marks are in valid range
int checkMarks(float mark) {
    if(mark >= 0 && mark <= 100) {
        return 1;
    }
    return 0;
}

// Calculate total and percentage
void calculateTotal(int index) {
    float sum = 0;
    for(int i = 0; i < Total_Subjects; i++) {
        sum += students[index].marks[i];
    }
    students[index].total = sum;
    students[index].percentage = (sum / 500.0) * 100.0;
}

// Assign grade based on percentage
void assignGrade(int index) {
    float per = students[index].percentage;
    
    // check if passed in all subjects (50% required)
    int failed = 0;
    for(int i = 0; i < Total_Subjects; i++) {
        if(students[index].marks[i] < 50) {
            failed = 1;
            break;
        }
    }
    
    if(failed) {
        strcpy(students[index].grade, "F");
        students[index].cgpa = 0.0;
    }
    else if(per >= 90) {
        strcpy(students[index].grade, "O");
        students[index].cgpa = per / 10.0;
    }
    else if(per >= 85) {
        strcpy(students[index].grade, "A+");
        students[index].cgpa = per / 10.0;
    }
    else if(per >= 75) {
        strcpy(students[index].grade, "A");
        students[index].cgpa = per / 10.0;
    }
    else if(per >= 65) {
        strcpy(students[index].grade, "B+");
        students[index].cgpa = per / 10.0;
    }
    else if(per >= 60) {
        strcpy(students[index].grade, "B");
        students[index].cgpa = per / 10.0;
    }
    else if(per >= 55) {
        strcpy(students[index].grade, "C");
        students[index].cgpa = per / 10.0;
    }
    else if(per >= 50) {
        strcpy(students[index].grade, "D");
        students[index].cgpa = per / 10.0;
    }
    else {
        strcpy(students[index].grade, "F");
        students[index].cgpa = 0.0;
    }
}

// Display results in table format
void displayTable() {
    printf("\n===================== STUDENT RESULTS =====================\n\n");
    
    printf("%-10s %-15s ", "ID", "Name");
    for(int i = 1; i <= Total_Subjects; i++) {
        printf("Sub%d   ", i);
    }
    printf("Total   Percent  Grade  CGPA\n");
    
    printf("---------------------------------------------------------------");
    printf("------------------\n");
    
    for(int i = 0; i < totalStudents; i++) {
        printf("%-10s %-15s ", students[i].id, students[i].name);
        
        for(int j = 0; j < Total_Subjects; j++) {
            printf("%-7.2f ", students[i].marks[j]);
        }
        
        printf("%-7.2f %-8.2f %-6s %.2f\n", 
               students[i].total, 
               students[i].percentage,
               students[i].grade,
               students[i].cgpa);
    }
    
    printf("==============================================================");
    printf("===================\n");
}

// Calculate and display statistics
void showStats() {
    if(totalStudents == 0) return;
    
    float totalPercentage = 0;
    float highest = students[0].percentage;
    float lowest = students[0].percentage;
    
    // counters for grades
    int countO = 0, countAplus = 0, countA = 0;
    int countBplus = 0, countB = 0, countC = 0;
    int countD = 0, countF = 0;
    
    for(int i = 0; i < totalStudents; i++) {
        totalPercentage += students[i].percentage;
        
        if(students[i].percentage > highest) {
            highest = students[i].percentage;
        }
        if(students[i].percentage < lowest) {
            lowest = students[i].percentage;
        }
        
        // count grades
        if(strcmp(students[i].grade, "O") == 0) countO++;
        else if(strcmp(students[i].grade, "A+") == 0) countAplus++;
        else if(strcmp(students[i].grade, "A") == 0) countA++;
        else if(strcmp(students[i].grade, "B+") == 0) countBplus++;
        else if(strcmp(students[i].grade, "B") == 0) countB++;
        else if(strcmp(students[i].grade, "C") == 0) countC++;
        else if(strcmp(students[i].grade, "D") == 0) countD++;
        else if(strcmp(students[i].grade, "F") == 0) countF++;
    }
    
    float avgPercentage = totalPercentage / totalStudents;
    
    printf("\n\n================== CLASS STATISTICS ==================\n\n");
    printf("Class Average Percentage : %.2f%%\n", avgPercentage);
    printf("Highest Percentage       : %.2f%%\n", highest);
    printf("Lowest Percentage        : %.2f%%\n", lowest);
    
    printf("\n--- Grade Distribution ---\n");
    printf("O  (>= 90%%)  : %d\n", countO);
    printf("A+ (85-90%%) : %d\n", countAplus);
    printf("A  (75-85%%) : %d\n", countA);
    printf("B+ (65-75%%) : %d\n", countBplus);
    printf("B  (60-65%%) : %d\n", countB);
    printf("C  (55-60%%) : %d\n", countC);
    printf("D  (50-55%%) : %d\n", countD);
    printf("F  (< 50%%)  : %d\n", countF);
    printf("======================================================\n\n");
}
