CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

#output folder
BIN_DIR := bin

#main exe source and include
SRC_DIR := src
INC_DIR := include

#main exe excluded files
MAIN_SRC_EXCLUDE_FILES := src/builder.cpp

#builder exe excluded files
BUIL_SRC_EXCLUDE_FILES := src/main.cpp

#the complete set of files without excluded files
MAIN_SRC_FILES := $(filter-out $(MAIN_SRC_EXCLUDE_FILES),$(shell find $(SRC_DIR) -name *.cpp))
BUIL_SRC_FILES := $(filter-out $(BUIL_SRC_EXCLUDE_FILES),$(shell find $(SRC_DIR) -name *.cpp))

LIBRARIES   :=
EXECUTABLE  := main


all: main

run: clean all
	clear
	./main

main:
	$(CXX) $(CXX_FLAGS) -I$(INC_DIR) $(MAIN_SRC_FILES) -o $(BIN_DIR)/$@ $(LIBRARIES)

builder:
	$(CXX) $(CXX_FLAGS) -I$(INC_DIR) $(BUIL_SRC_FILES) -o $(BIN_DIR)/$@ $(LIBRARIES)

clean:
	-rm $(BIN_DIR)/*

new: clean all