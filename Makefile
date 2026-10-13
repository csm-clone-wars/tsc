
CXX = g++

CXXFLAGS = -std=c++20 -O2 -Wall -Wextra -Wpedantic -Werror -Iinclude -MMD -MP

SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp,build/obj/%.o,$(SRC))
DEP = $(OBJ:.o=.d)

TARGET = build/tsc

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p build
	$(CXX) $(OBJ) -o $@

build/obj/%.o: src/%.cpp
	mkdir -p build/obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEP)

clean:
	rm -rf build