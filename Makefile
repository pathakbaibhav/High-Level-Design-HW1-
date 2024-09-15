# Compiler and flags
CC = g++
CFLAGS = -Wall -g -std=c++17

# Directories (with spaces in paths handled by quotes)
SRC_DIR = /Users/baibhavpathak/Documents/Development/hw1-pathakbaibhav/src
OBJ_DIR = /Users/baibhavpathak/Documents/Development/hw1-pathakbaibhav/obj
TARGET_DIR = /Users/baibhavpathak/Documents/Development/hw1-pathakbaibhav/bin

# Target executable name
TARGET = $(TARGET_DIR)/countersim

# Source files
SRCS = $(SRC_DIR)/countersim.cpp $(SRC_DIR)/simengine.cpp

# Object files
OBJS = $(OBJ_DIR)/countersim.o $(OBJ_DIR)/simengine.o

# Default target: build the executable
all: $(TARGET)

# Ensure the object and target directories exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

# Link the object files to create the final executable
$(TARGET): $(TARGET_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile each .cpp file into its corresponding .o file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

# Rule to execute the binary for testing
test: $(TARGET)
	$(TARGET)
