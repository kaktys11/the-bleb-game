PROJECT_NAME = bleb_game

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = -lraylib -lm -lpthread -ldl -lX11

# Files and directories
BUILD_DIR = build
EXEC_FILE = $(BUILD_DIR)/$(PROJECT_NAME)

SRC_DIRS = src src/model
SRC = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cc))

OBJ_DIR = $(BUILD_DIR)/obj
OBJ = $(SRC:$(SRC_DIRS)/%.cc=$(OBJ_DIR)/%/%.o)


# Main targets
$(PROJECT_NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC_FILE) $^

$(OBJ_DIR)/%/%.o: $(SRC_DIRS)/%/%.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(EXEC_FILE)

run: clean $(PROJECT_NAME)
	$(EXEC_FILE)

leaks: clean $(PROJECT_NAME)
	valgrind --leak-check=full --track-origins=yes $(EXEC_FILE)

# Phony targets
.PHONY: clean
