all: main
run: clean main ./main

CXX = clang++
override CXXFLAGS += -g -Wall -Werror -fsanitize=bounds

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cc' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

main: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"

main-debug: $(SRCS) $(HEADERS)
	NIX_HARDENING_ENABLE= $(CXX) $(CXXFLAGS) -O0  $(SRCS) -o "$@"

clean:
	rm -f main main-debug