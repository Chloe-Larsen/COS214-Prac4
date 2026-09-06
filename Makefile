# ---- TaskForge: Shipping Logistics ----
CXX      := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -pedantic -g
TARGET   := taskforge

SRC := $(wildcard src/*.cpp) main.cpp
OBJ := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

# Memory investigation for the marker (Task 5)
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Debug session entry point (Task 5)
debug: $(TARGET)
	gdb ./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all run valgrind debug clean
