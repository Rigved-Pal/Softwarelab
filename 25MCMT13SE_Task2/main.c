#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "validation.h"
#include "computation.h"
#include "fileio.h"
#include "display.h"
#include "statistics.h"

// Function prototypes
void processResults();
void interactiveMode();
struct Student* searchStudentByID(struct Student students[], int count, const char *id);

// Global student array (can be optimized using dynamic allocation)
struct Student students[MAX_STUDENTS];
int studentCount = 0;

int main(int argc, char *argv[]) {
    printf("\n========== Student Result Processing System ==========\n");
    printf("Software Engineering Lab - Task 2\n");
    printf("Modular Design with Quality Characteristics\n");
    printf("======================================================\n\n");
    
    // Command line argument support for batch processing (Interoperability)
    if (argc > 1) {
        printf("Batch mode: Reading from '%s'\n", argv[1]);
        if (readStudentsFromFile(argv[1], students, &studentCount) == 0) {
            printf("Successfully processed %d student(s)\n", studentCount);
            displayStudentReport(students, studentCount);
            displayStatistics(students, studentCount);
        }
        return 0;
    }
    
    // Default file processing
    processResults();
    
    // Interactive menu (Usability)
    interactiveMode();
    
    return 0;
}

void processResults() {
    const char *filename = "students.txt";
    
    printf("Reading student data from '%s'...\n", filename);
    
    if (readStudentsFromFile(filename, students, &studentCount) != 0) {
        printf("Error reading file. Please ensure 'students.txt' exists.\n");
        printf("Creating sample file format...\n");
        
        FILE *sample = fopen("sample_format.txt", "w");
        if (sample) {
            fprintf(sample, "# Student data format\n");
            fprintf(sample, "# ID Name Mark1 Mark2 Mark3 Mark4 Mark5\n");
            fprintf(sample, "ST001 RahulSharma 85 90 78 88 92\n");
            fprintf(sample, "ST002 PriyaGupta 92 88 95 90 93\n");
            fclose(sample);
            printf("Sample format created in 'sample_format.txt'\n");
        }
        return;
    }
    
    if (studentCount == 0) {
        printf("No valid student records found.\n");
        return;
    }
    
    printf("Successfully processed %d student(s)\n\n", studentCount);
}

void interactiveMode() {
    if (studentCount == 0) {
        printf("No student data available. Exiting...\n");
        return;
    }
    
    int choice;
    char searchID[MAX_ID_LEN];
    
    while (1) {
        displayMenu();
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                displayStudentReport(students, studentCount);
                break;
                
            case 2:
                displayStatistics(students, studentCount);
                break;
                
            case 3:
                exportToCSV("results.csv", students, studentCount);
                printf("CSV export complete. File can be opened in Excel/Spreadsheet.\n");
                break;
                
            case 4:
                writeStudentsToFile("results.txt", students, studentCount);
                printf("Report saved successfully.\n");
                break;
                
            case 5:
                printf("Enter Student ID to search: ");
                scanf("%s", searchID);
                struct Student *found = searchStudentByID(students, studentCount, searchID);
                if (found) {
                    displayStudentDetails(found);
                } else {
                    printf("Student with ID '%s' not found.\n", searchID);
                }
                break;
                
            case 6:
                printf("Exiting... Thank you!\n");
                return;
                
            default:
                printf("Invalid choice. Please select 1-6.\n");
        }
        
        printf("\nPress Enter to continue...");
        while (getchar() != '\n');
        getchar();
    }
}

struct Student* searchStudentByID(struct Student students[], int count, const char *id) {
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            return &students[i];
        }
    }
    return NULL;
}