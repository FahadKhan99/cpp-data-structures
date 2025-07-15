# Compiler and flags
COMPILER = clang++
COMPILER_FLAGS = -std=c++17 -Wall

# Directories
INCLUDE_DIR = -Idata_structures/linked_list -Idata_structures/stack -Idata_structures/queue

# this for scaling up in future
# INCLUDE_DIRS = -Idata_structures/linked_list -Idata_structures/trees -Idata_structures/graphs  

BUILD_DIR = build

# Source and output
SRC  = main.cpp
# SRC = main.cpp / $(wildcard data_structures/linked_list/*.cpp)     this if i seperate .h and .cpp
OUT = $(BUILD_DIR)/main

# Default target
all: $(OUT)

# Build rule
$(OUT): $(SRC)
	mkdir -p $(BUILD_DIR)
	$(COMPILER) $(COMPILER_FLAGS) $(INCLUDE_DIR) $(SRC) -o $(OUT)

# Clean build output
clean:
	rm -rf $(BUILD_DIR)
