# Compiler to use
CC = g++

# Compiler flags
CFLAGS = -Wall -std=c++11

# Name of file
OUTPUT = playlist

# List of source files
SOURCES = playlist.cpp Menu.cpp Database.cpp Song.cpp

# List of object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(OUTPUT)

# Link object files to create the output file
$(OUTPUT): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files to create object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

# Clean up object files and output file
clean:
	rm -f $(OBJECTS) $(OUTPUT)