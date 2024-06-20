# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -O3 -g -pg -std=c++20

# Source files
SOURCES = main.cpp AStar.cpp Graph.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Header files
HEADERS = AStar.h Graph.h

# Executable name
EXECUTABLE = main_gprof

# Rule to compile .cpp files to .o files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I.

# Default rule to compile the executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Rule to clean the generated files
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)