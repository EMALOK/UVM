CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN     := bin
SRC     := src
INCLUDE := include

LIBRARIES   :=
EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

builder: $(filter-out src/main.cpp, $(wildcard src/*.cpp))
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $(BIN)/$@ $(LIBRARIES)

clean:
	-rm $(BIN)/*

new: clean all