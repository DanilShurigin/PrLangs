NAME = lw1_2

CXX = g++
CXXFLAGS = -Wall
# LDFLAGS = -l

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

EXEC = $(NAME).exec
# COMMANDLINE_OPTIONS = 

PROJECT = $(BIN_DIR)/$(EXEC)

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard $(SRC_DIR)/*.h)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))


.PHONY: all clean clean-test test run

all: $(PROJECT)

$(PROJECT): $(OBJECTS)
	$(CXX) $^ $(LDFLAGS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJECTS): $(HEADERS)

clean:
	rm -f $(BIN_DIR)/* $(BUILD_DIR)/*
