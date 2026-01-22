#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "validation.h"

int StudentIDvalidation(const char *id, struct Student students[], int count) {
    // Check if ID is empty
    if (id == NULL || strlen(id) == 0) {
        return 0;
    }
    
    // Check if alphanumeric
    if (!Isalphanum
        (id)) {
        return 0;
    }
    
    // Check for duplicate ID
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            return 0;  // Duplicate found
        }
    }
    
    return 1;  // Valid and unique
}

int validateStudentName(const char *name) {
    if (name == NULL || strlen(name) == 0) {
        return 0;
    }
    
    return isAlphabet(name);
}

int validateStudentMarks(float mark) {
    return (mark >= 0.0 && mark <= 100.0);
}

int Isalphanum(const char *str) {
    if (str == NULL || strlen(str) == 0) {
        return 0;
    }
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalnum(str[i])) {
            return 0;
        }
    }
    return 1;
}

int isAlphabet(const char *str) {
    if (str == NULL || strlen(str) == 0) {
        return 0;
    }
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}