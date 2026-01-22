# Module Specifications
## Student Result Processing System - Task 2

**Course:** Software Engineering Lab  
**Program:** M.Tech (CS) 2025-26  
**Date:** 20-1-2026

---

## Table of Contents
1. [Student Module](#student-module)
2. [Validation Module](#validation-module)
3. [Computation Module](#computation-module)
4. [File I/O Module](#fileio-module)
5. [Display Module](#display-module)
6. [Statistics Module](#statistics-module)

---

## 1. Student Module

### Module Name: `student.h`

### Purpose
Defines core data structures and constants used across all modules.

### Module Characteristics
- **Cohesion**: High - Contains only data structure definitions
- **Coupling**: Low - No dependencies on other modules
- **Reusability**: High - Can be used in any student management system

### Data Structures

#### Structure: Student
```c
struct Student {
    char id[20];              // Unique student identifier
    char name[50];            // Student name
    float marks[5];           // Marks for 5 subjects
    float total;              // Total marks
    float percentage;         // Overall percentage
    char grade[5];            // Grade (O, A+, A, B+, B, C, D, F)
    float cgpa;               // CGPA (10-point scale)
    int passed;               // Pass/Fail status
};
```

#### Structure: GradeStatistics
```c
struct GradeStatistics {
    int gradeO, gradeAPlus, gradeA;
    int gradeBPlus, gradeB, gradeC;
    int gradeD, gradeF;
};
```

### Constants
- `MAX_STUDENTS = 100` - Maximum students
- `MAX_NAME_LEN = 50` - Maximum name length
- `MAX_ID_LEN = 20` - Maximum ID length
- `NUM_SUBJECTS = 5` - Number of subjects
- `PASSING_PERCENTAGE = 50.0` - Minimum passing marks

---

## 2. Validation Module

### Module Name: `validation.c` / `validation.h`

### Purpose
Provides all validation functions for student data.

### Module Characteristics
- **Cohesion**: High - All validation logic in one place
- **Coupling**: Low - Minimal dependencies
- **Reusability**: High - Can be used in other academic systems

### Functions

#### 2.1 validateStudentID()

**Input:**
- `id` (const char*) - Student ID to validate
- `students[]` (struct Student[]) - Existing students array
- `count` (int) - Number of existing students

**Pre-condition:**
- `id` should not be NULL
- `students` array should be valid

**Logic:**
```
Algorithm:
1. Check if ID is empty -> return 0
2. Check if ID is alphanumeric using isAlphanumeric()
   - If not alphanumeric -> return 0
3. Loop through existing students
   - If ID matches any existing ID -> return 0 (duplicate)
4. Return 1 (valid and unique)
```

**Output:**
- Returns `1` if valid and unique
- Returns `0` if invalid or duplicate

---

#### 2.2 validateName()

**Input:**
- `name` (const char*) - Student name to validate

**Pre-condition:**
- `name` should not be NULL

**Logic:**
```
Algorithm:
1. Check if name is empty -> return 0
2. Call isAlphabetic() helper function
3. Return result
```

**Output:**
- Returns `1` if valid (only alphabets)
- Returns `0` if invalid

---

#### 2.3 validateMarks()

**Input:**
- `mark` (float) - Mark value to validate

**Pre-condition:** None

**Logic:**
```
Algorithm:
1. Check if mark >= 0 AND mark <= 100
2. Return 1 if true, 0 if false
```

**Output:**
- Returns `1` if marks in range [0, 100]
- Returns `0` otherwise

---

#### 2.4 isAlphanumeric()

**Input:**
- `str` (const char*) - String to check

**Pre-condition:**
- `str` should not be NULL

**Logic:**
```
Algorithm:
1. Check if string is empty -> return 0
2. For each character in string:
   - If not alphanumeric -> return 0
3. Return 1 (all characters are alphanumeric)
```

**Output:**
- Returns `1` if alphanumeric
- Returns `0` otherwise

---

#### 2.5 isAlphabetic()

**Input:**
- `str` (const char*) - String to check

**Pre-condition:**
- `str` should not be NULL

**Logic:**
```
Algorithm:
1. Check if string is empty -> return 0
2. For each character in string:
   - If not alphabetic -> return 0
3. Return 1 (all characters are alphabetic)
```

**Output:**
- Returns `1` if alphabetic
- Returns `0` otherwise

---

## 3. Computation Module

### Module Name: `computation.c` / `computation.h`

### Purpose
Handles all grade and result calculations.

### Module Characteristics
- **Cohesion**: High - All computation logic together
- **Coupling**: Low - Only depends on student.h
- **Reusability**: High - Can be used in any grading system

### Functions

#### 3.1 calculateStudentResults()

**Input:**
- `student` (struct Student*) - Pointer to student structure

**Pre-condition:**
- Student marks should be valid (0-100)

**Logic:**
```
Algorithm:
1. Initialize total = 0
2. For i = 0 to NUM_SUBJECTS-1:
   - total += student->marks[i]
3. student->total = total
4. student->percentage = (total / 500) * 100
5. Call checkPassingStatus(student)
6. Call assignGrade(student)
7. student->cgpa = calculateCGPA(student->percentage)
```

**Output:**
- Updates student structure with calculated values

---

#### 3.2 assignGrade()

**Input:**
- `student` (struct Student*) - Pointer to student structure

**Pre-condition:**
- Student percentage should be calculated

**Logic:**
```
Algorithm:
1. Get percentage from student
2. If student->passed == 0:
   - grade = "F", cgpa = 0, return
3. Else if percentage >= 90:
   - grade = "O"
4. Else if percentage >= 85:
   - grade = "A+"
5. Else if percentage >= 75:
   - grade = "A"
6. Else if percentage >= 65:
   - grade = "B+"
7. Else if percentage >= 60:
   - grade = "B"
8. Else if percentage >= 55:
   - grade = "C"
9. Else if percentage >= 50:
   - grade = "D"
10. Else:
    - grade = "F"
```

**Output:**
- Updates student->grade

---

#### 3.3 calculateCGPA()

**Input:**
- `percentage` (float) - Percentage value

**Pre-condition:**
- Percentage should be valid (0-100)

**Logic:**
```
Algorithm:
1. CGPA = percentage / 10
2. Return CGPA
```

**Output:**
- Returns CGPA (float)

---

#### 3.4 checkPassingStatus()

**Input:**
- `student` (struct Student*) - Pointer to student structure

**Pre-condition:**
- Student marks should be valid

**Logic:**
```
Algorithm:
1. For i = 0 to NUM_SUBJECTS-1:
   - If marks[i] < 50:
     - Return 0 (failed)
2. Return 1 (passed all)
```

**Output:**
- Returns `1` if passed all subjects
- Returns `0` if failed in any subject

---

## 4. File I/O Module

### Module Name: `fileio.c` / `fileio.h`

### Purpose
Handles all file input/output operations.

### Module Characteristics
- **Cohesion**: High - All file operations together
- **Coupling**: Medium - Depends on validation and computation
- **Interoperability**: High - Supports multiple file formats

### Functions

#### 4.1 readStudentsFromFile()

**Input:**
- `filename` (const char*) - Name of input file
- `students[]` (struct Student[]) - Array to store students
- `count` (int*) - Pointer to store number of students

**Pre-condition:**
- File should exist and be readable

**Logic:**
```
Algorithm:
1. Open file in read mode
2. If file == NULL:
   - Print error, return -1
3. Initialize count = 0, lineNum = 0
4. While reading lines from file:
   - lineNum++
   - Skip comments (#) and empty lines
   - Parse line: ID, Name, 5 marks
   - If parsing fails: skip line
   - Validate ID using validateStudentID()
   - Validate name using validateName()
   - Validate all marks using validateMarks()
   - If all valid:
     - Store data in temp student
     - Call calculateStudentResults()
     - Add to students array
     - count++
5. Close file
6. Return 0
```

**Output:**
- Returns `0` on success
- Returns `-1` on failure
- Updates `count` with number of valid students

---

#### 4.2 writeStudentsToFile()

**Input:**
- `filename` (const char*) - Output file name
- `students[]` (struct Student[]) - Students array
- `count` (int) - Number of students

**Pre-condition:**
- Students array should have valid data

**Logic:**
```
Algorithm:
1. Open file in write mode
2. If file == NULL: return -1
3. Write header
4. Write table header
5. For i = 0 to count-1:
   - Write student data in formatted way
6. Close file
7. Return 0
```

**Output:**
- Returns `0` on success
- Returns `-1` on failure
- Creates text file with results

---

#### 4.3 exportToCSV()

**Input:**
- `filename` (const char*) - CSV file name
- `students[]` (struct Student[]) - Students array
- `count` (int) - Number of students

**Pre-condition:**
- Students array should have valid data

**Logic:**
```
Algorithm:
1. Open file in write mode
2. If file == NULL: return -1
3. Write CSV header line
4. For i = 0 to count-1:
   - Write student data as CSV (comma-separated)
5. Close file
6. Return 0
```

**Output:**
- Returns `0` on success
- Returns `-1` on failure
- Creates CSV file (Excel compatible)

---

## 5. Display Module

### Module Name: `display.c` / `display.h`

### Purpose
Handles all user interface and output display.

### Module Characteristics
- **Cohesion**: High - All display functions together
- **Coupling**: Medium - Depends on student and statistics
- **Usability**: High - User-friendly formatted output

### Functions

#### 5.1 displayStudentReport()

**Input:**
- `students[]` (struct Student[]) - Students array
- `count` (int) - Number of students

**Pre-condition:**
- Students array should have valid data

**Logic:**
```
Algorithm:
1. Print report header
2. Print table column headers
3. For i = 0 to count-1:
   - Print student ID, name
   - Print all 5 marks
   - Print total, percentage, grade, CGPA
4. Print footer line
```

**Output:**
- Prints formatted table to console

---

#### 5.2 displayStatistics()

**Input:**
- `students[]` (struct Student[]) - Students array
- `count` (int) - Number of students

**Pre-condition:**
- Students array should have valid data

**Logic:**
```
Algorithm:
1. Call calculateClassAverage()
2. Call findHighestPercentage()
3. Call findLowestPercentage()
4. Call calculatePassPercentage()
5. Call calculateGradeDistribution()
6. Print all statistics in formatted way
7. Print grade distribution
```

**Output:**
- Prints statistics to console

---

## 6. Statistics Module

### Module Name: `statistics.c` / `statistics.h`

### Purpose
Provides statistical analysis functions.

### Module Characteristics
- **Cohesion**: High - All statistical calculations
- **Coupling**: Low - Only depends on student.h
- **Reusability**: Very High - Generic statistical functions

### Functions

#### 6.1 calculateClassAverage()

**Input:**
- `students[]` (struct Student[]) - Students array
- `count` (int) - Number of students

**Pre-condition:**
- count > 0

**Logic:**
```
Algorithm:
1. If count == 0: return 0
2. total = 0
3. For i = 0 to count-1:
   - total += students[i].percentage
4. average = total / count
5. Return average
```

**Output:**
- Returns average percentage (float)

---

#### 6.2 findHighestPercentage()

**Input:**
- `students[]` (struct Student[]) - Students array
- `count` (int) - Number of students

**Pre-condition:**
- count > 0

**Logic:**
```
Algorithm:
1. If count == 0: return 0
2. highest = students[0].percentage
3. For i = 1 to count-1:
   - If students[i].percentage > highest:
     - highest = students[i].percentage
4. Return highest
```

**Output:**
- Returns highest percentage (float)

---

#### 6.3 calculateGradeDistribution()

**Input:**
- `students[]` (struct Student[]) - Students array
- `count` (int) - Number of students
- `stats` (struct GradeStatistics*) - Pointer to statistics structure

**Pre-condition:**
- count > 0
- stats should not be NULL

**Logic:**
```
Algorithm:
1. Initialize all grade counts to 0
2. For i = 0 to count-1:
   - If grade == "O": gradeO++
   - Else if grade == "A+": gradeAPlus++
   - Else if grade == "A": gradeA++
   - ... (for all grades)
3. Update stats structure
```

**Output:**
- Updates GradeStatistics structure

---

## Module Dependency Diagram

```
main.c
  |
  +-- student.h (Data Structures)
  |
  +-- validation.h
  |     |-- student.h
  |
  +-- computation.h
  |     |-- student.h
  |
  +-- fileio.h
  |     |-- student.h
  |     |-- validation.h
  |     |-- computation.h
  |
  +-- display.h
  |     |-- student.h
  |     |-- statistics.h
  |
  +-- statistics.h
        |-- student.h
```

---

## Quality Characteristics Achieved

### 1. Usability
- Interactive menu system
- Clear error messages
- User-friendly output formats
- Command-line argument support

### 2. Efficiency
- Modular compilation (compile only changed modules)
- Optimized algorithms (O(n) complexity)
- Minimal memory usage
- Efficient file I/O

### 3. Reusability
- Independent modules with clear interfaces
- Generic validation functions
- Reusable statistical functions
- Standard data structures

### 4. Interoperability
- CSV export for Excel/Spreadsheet
- Text file output
- Command-line interface
- Standard C libraries only

---

**Last Updated:** 22-1-2026