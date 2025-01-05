# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = -lraylib -lm -lpthread -ldl -lX11

# Directory for object files
OBJ_DIR = build/obj

# List of source files
SRC = $(wildcard src/*.cc)

# List of object files (keeping the directory structure)
OBJ = $(SRC:src/%.cc=$(OBJ_DIR)/model/%.o)

# Output executable file
EXEC = game

# Rule to build the executable
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o ./build/$(EXEC) $(LDFLAGS)  # Add LDFLAGS during linking

# Rule to create object files from source files, preserving subdirectory structure
$(OBJ_DIR)/model/%.o: src/%.cc
	@mkdir -p $(dir $@)  # Create the necessary directories for object files
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -rf $(OBJ_DIR) $(EXEC)


run: $(EXEC)
	./build/$(EXEC)


# Phony targets
.PHONY: clean
