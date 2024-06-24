# Makefile for C++ code

# Target executable name
TARGET = main 

# Header files
HDRS = node.hpp tree.hpp bfs.hpp dfs.hpp inOrder.hpp preOrder.hpp postOrder.hpp myHeap.hpp

# Object files (generated from source files)
OBJS = $(SRCS:.cpp=.o)

# Default compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

LDLIBS =

SRCS = main.cpp

all: $(TARGET)

# Build rule for the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS) $(LDFLAGS)

# Clean command
clean:
	rm -f $(OBJS) $(TARGET) 

.PHONY: all clean
