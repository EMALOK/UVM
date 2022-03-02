CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN     := bin
SRC     := src
BUILDER_SRC := src/builder
BUILDER_INCLUDE := include/builder
INCLUDE := include

LIBRARIES   :=
EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(filter-out $(SRC)/builder.cpp, $(wildcard $(SRC)/*.cpp))
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

builder: $(filter-out $(SRC)/main.cpp, $(wildcard $(SRC)/*.cpp) $(wildcard $(BUILDER_SRC)/*.cpp))
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -I$(BUILDER_INCLUDE) $^ -o $(BIN)/$@ $(LIBRARIES)

clean:
	-rm $(BIN)/*

new: clean all