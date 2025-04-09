PROJECT_NAME =THE_BLEB_GAME

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = -lraylib -lm -lpthread -ldl -lX11

# Files and directories
BUILD_DIR = ./build
EXEC_FILE = $(BUILD_DIR)/$(PROJECT_NAME)

# BUILD_DIR_TEST = ./build
# EXEC_FILE_TEST = $(BUILD_DIR_TEST)/$(PROJECT_NAME)

# SRC_DIRS = src/model
# SRC = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cc)) test_DialogTree.cc

# OBJ_DIR = $(BUILD_DIR_TEST)/obj
# OBJ = $(SRC:$(SRC_DIRS)/%.cc=$(OBJ_DIR)/%/%.o)

# dialog: $(OBJ)
# 	$(CXX) $(CXXFLAGS) -o $(EXEC_FILE_TEST) $^ $(LDFLAGS)

# $(OBJ_DIR)/%/%.o: $(SRC_DIRS)/%/%.cc
# 	@mkdir -p $(dir $@)
# 	$(CXX) $(CXXFLAGS) -c $< -o $@


BUILD_DIR_TEST = ./build
EXEC_FILE_TEST = $(BUILD_DIR_TEST)/$(PROJECT_NAME)_DIALOGTREE

SRC_DIRS = src/model
SRC = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cc)) src/test_DialogTree.cc

OBJ_DIR = $(BUILD_DIR_TEST)/obj

# Create a flat list of object files in OBJ_DIR
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cc=.o)))

# vpath helps make find the source files
vpath %.cc $(SRC_DIRS) .

# Rule to compile .cc files to .o
$(OBJ_DIR)/%.o: %.cc
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/test_DialogTree.o:
	$(CXX) $(CXXFLAGS) -c src/test_DialogTree.cc -o $@

# Link objects into final executable
build_dialog: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC_FILE_TEST) $^


dialog:
	make clean
	make build_dialog
	./$(EXEC_FILE_TEST)

clean:
	rm -rf $(BUILD_DIR)

# run: clean $(PROJECT_NAME)
# 	$(EXEC_FILE)

build:
	mkdir -p ${BUILD_DIR}
	cmake -S ./src -B ${BUILD_DIR}
	cmake --build ${BUILD_DIR}

run: clean build
	./$(EXEC_FILE)

leaks: clean $(PROJECT_NAME)
	valgrind --leak-check=full --track-origins=yes $(EXEC_FILE)

clang-format:
	@echo "Fixing style with clang-format..."
	@find . -name "*.cc" -o -name "*.h" | while read file; do \
		clang-format -i $$file; \
	done
	@echo "clang-format completed."

# Phony targets
.PHONY: clean build dialog
