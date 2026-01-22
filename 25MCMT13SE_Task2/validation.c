/*
 * validation.c
 * Implementation of validation module
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "validation.h"

int validateStudentID(const char *id, struct Student students[], int count) {
    // Check if ID is empty
    if (id == NULL || strlen(id) == 0) {
        return 0;
    }
    
    // Check if alphanumeric
    if (!isAlphanumeric(id)) {
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

int validateName(const char *name) {
    if (name == NULL || strlen(name) == 0) {
        return 0;
    }
    
    return isAlphabetic(name);
}

int validateMarks(float mark) {
    return (mark >= 0.0 && mark <= 100.0);
}

int isAlphanumeric(const char *str) {
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

int isAlphabetic(const char *str) {
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