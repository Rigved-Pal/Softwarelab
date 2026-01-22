# Makefile for Student Result Processing System
# Demonstrates modular compilation

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = student_system

# Object files
OBJS = main.o validation.o computation.o fileio.o display.o statistics.o

# Default target
all: $(TARGET)

# Link all object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	@echo "Build successful! Run with: ./$(TARGET)"

# Compile main.c
main.o: main.c student.h validation.h computation.h fileio.h display.h statistics.h
	$(CC) $(CFLAGS) -c main.c

# Compile validation module
validation.o: validation.c validation.h student.h
	$(CC) $(CFLAGS) -c validation.c

# Compile computation module
computation.o: computation.c computation.h student.h
	$(CC) $(CFLAGS) -c computation.c

# Compile fileio module
fileio.o: fileio.c fileio.h student.h validation.h computation.h
	$(CC) $(CFLAGS) -c fileio.c

# Compile display module
display.o: display.c display.h student.h statistics.h
	$(CC) $(CFLAGS) -c display.c

# Compile statistics module
statistics.o: statistics.c statistics.h student.h
	$(CC) $(CFLAGS) -c statistics.c

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)
	@echo "Clean complete"

# Run the program
run: $(TARGET)
	./$(TARGET)

# Help
help:
	@echo "Available targets:"
	@echo "  make         - Build the project"
	@echo "  make clean   - Remove build files"
	@echo "  make run     - Build and run the program"
	@echo "  make help    - Show this help message"