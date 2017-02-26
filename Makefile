CXX = g++
CXXFLAGS = -c -Wall -O2 -std=c++11
LDFLAGS = -lSDL2
CXXFILES = program.cpp game.cpp cnake.cpp
OBJFILES = $(CXXFILES:.cpp=.o)
BIN = program

default: $(BIN)

$(BIN): $(OBJFILES)
	$(CXX) $^ -o $@ $(LDFLAGS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	-rm $(OBJFILES) $(BIN)
