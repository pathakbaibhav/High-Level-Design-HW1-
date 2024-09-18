# Compiler and flags
CC = g++
CFLAGS = -Wall -g -std=c++17

# Directories (with spaces in paths handled by quotes)
SRC_DIR = /Users/baibhavpathak/Documents/Development/hw1-pathakbaibhav/src
OBJ_DIR = /Users/baibhavpathak/Documents/Development/hw1-pathakbaibhav/obj
TARGET_DIR = /Users/baibhavpathak/Documents/Development/hw1-pathakbaibhav/bin
VCD_DIR = /Users/baibhavpathak/Documents/Development/hw1-pathakbaibhav/vcd-writer

# Target executable name
TARGET = $(TARGET_DIR)/countersim

# Source files (add clkgen.cpp here)
SRCS = $(SRC_DIR)/countersim.cpp $(SRC_DIR)/simengine.cpp $(SRC_DIR)/clkgen.cpp

# Object files (add clkgen.o here)
OBJS = $(OBJ_DIR)/countersim.o $(OBJ_DIR)/simengine.o $(OBJ_DIR)/clkgen.o

# GitHub repository for VCD Writer
VCD_REPO = https://github.com/favorart/vcd-writer.git

# Default target: build the executable
all: $(TARGET)

# Ensure the object and target directories exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

# Rule to clone the VCD writer repository if it doesn't exist
$(VCD_DIR):
	git clone $(VCD_REPO) $(VCD_DIR)

# Link the object files to create the final executable
$(TARGET): $(TARGET_DIR) $(OBJS) $(VCD_DIR)
	$(CC) $(CFLAGS) -I$(VCD_DIR)/include -o $(TARGET) $(OBJS)

# Rule to compile each .cpp file into its corresponding .o file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(VCD_DIR)/include -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
	rm -rf $(VCD_DIR)

# Rule to execute the binary for testing
test: $(TARGET)
	$(TARGET)
