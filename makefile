# Target executable name
TARGET = main

# Header files
HDRS = node.hpp tree.hpp bfs.hpp dfs.hpp inOrder.hpp preOrder.hpp postOrder.hpp myHeap.hpp

# Source files
SRCS = main.cpp TestCounter.cpp Test.cpp tree.cpp node.cpp bfs.cpp dfs.cpp inOrder.cpp preOrder.cpp postOrder.cpp myHeap.cpp

# Object files (generated from source files)
OBJS = $(SRCS:.cpp=.o)

# Default compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11 -Wall -Wextra -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

LDLIBS =

all: $(TARGET) 

# Build rule for the target executable
$(TARGET): main.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o $(LDLIBS) $(LDFLAGS)

# Build rule for the test executable
test: TestCounter.o Test.o 
	$(CXX) $(CXXFLAGS) $^ -o test $(LDLIBS) $(LDFLAGS)

# Build and run the tree program
tree: $(TARGET)
	./$(TARGET)

# Compile source files into object files
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean command
clean:
	rm -f $(OBJS) $(TARGET) test

.PHONY: all clean test tree
