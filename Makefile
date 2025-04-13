# Makefile for Recovery Code CLI

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude

# Source files
SRCS = $(wildcard src/*.cpp)

# Header files
HEADERS = $(wildcard include/*.hpp)

# Output executable
TARGET = recovery_cli

# Build rules
all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
