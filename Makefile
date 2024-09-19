# Compiler and flags
CC = g++
CFLAGS = -Wall -g -std=c++17 -fpermissive

# Directories (with spaces in paths handled by quotes)
SRC_DIR = /Users/baibhavpathak/Documents/Development/hw1-pathakbaibhav/src
OBJ_DIR = /Users/baibhavpathak/Documents/Development/hw1-pathakbaibhav/obj
TARGET_DIR = /Users/baibhavpathak/Documents/Development/hw1-pathakbaibhav/bin
VCD_DIR = /Users/baibhavpathak/Documents/Development/hw1-pathakbaibhav/vcd-writer
RESULTS_DIR = /Users/baibhavpathak/Documents/Development/hw1-pathakbaibhav/results
LIB_DIR = /Users/baibhavpathak/Documents/Development/hw1-pathakbaibhav/lib

# Target executable name
TARGET = $(TARGET_DIR)/countersim

# Source files (added clkdiv.cpp)
SRCS = $(SRC_DIR)/countersim.cpp $(SRC_DIR)/simengine.cpp $(SRC_DIR)/clkgen.cpp $(SRC_DIR)/tracer.cpp $(SRC_DIR)/counter.cpp $(SRC_DIR)/clkdiv.cpp

# Object files (added clkdiv.o)
OBJS = $(OBJ_DIR)/countersim.o $(OBJ_DIR)/simengine.o $(OBJ_DIR)/clkgen.o $(OBJ_DIR)/tracer.o $(OBJ_DIR)/counter.o $(OBJ_DIR)/clkdiv.o

# GitHub repository for VCD Writer
VCD_REPO = https://github.com/favorart/vcd-writer.git

# Default target: build the executable
all: $(TARGET)

# Ensure the object, target, results, and lib directories exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

$(RESULTS_DIR):
	mkdir -p $(RESULTS_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

# Rule to clone the VCD writer repository if it doesn't exist
$(VCD_DIR):
	@echo "Cloning VCD Writer repository..."
	[ -d $(VCD_DIR) ] || git clone $(VCD_REPO) $(VCD_DIR)

# Rule to build the VCD Writer project and ensure lib directory exists
$(LIB_DIR)/libvcdwriter.so: $(VCD_DIR) $(LIB_DIR)
	@echo "Building VCD Writer project..."
	cd $(VCD_DIR) && make
	cp $(VCD_DIR)/build/libvcdwriter.so $(LIB_DIR)/
	cp $(VCD_DIR)/build/libvcdwriter.a $(LIB_DIR)/

# Link the object files to create the final executable, adding -rpath for runtime library search path
$(TARGET): $(TARGET_DIR) $(RESULTS_DIR) $(LIB_DIR)/libvcdwriter.so $(OBJS)
	$(CC) $(CFLAGS) -I$(VCD_DIR)/include -L$(LIB_DIR) -o $(TARGET) $(OBJS) -lvcdwriter -Wl,-rpath,$(LIB_DIR)
	install_name_tool -change build/libvcdwriter.so $(LIB_DIR)/libvcdwriter.so $(TARGET)

# Rule to compile each .cpp file into its corresponding .o file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(VCD_DIR)/include -c $< -o $@

# Clean up object files, executable, and results directory
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
	rm -rf $(VCD_DIR)
	rm -rf $(RESULTS_DIR)
	rm -rf $(LIB_DIR)

# Rule to execute the binary for testing
test: $(TARGET)
	$(TARGET)
