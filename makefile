CC = g++
FLAGS = -g -Iinclude -Llibs -lmsgl -lglfw -lGL -lm -lgcc_s -lgcc -std=c++11 -Wl,-rpath=/usr/local/lib/,-rpath=./,-rpath=./libs/
BUILD_DIR = ./bin
SOURCE_FILES := $(wildcard src/*.cpp)
HEADERS  := $(wildcard include/*.h)
OBJECTS := $(SOURCE_FILES:src/%.cpp=$(BUILD_DIR)/%.o)

All: SpritePreviewer Clean

SpritePreviewer: main.cpp $(OBJECTS) $(HEADERS) makefile
	$(CC) -o $(BUILD_DIR)/SpritePreviewer main.cpp $(OBJECTS) $(FLAGS)

$(BUILD_DIR)/%.o : src/%.cpp $(HEADERS) makefile
	$(CC) $(FLAGS) -o $@ -c $< 

Clean:
	rm bin/*.o
