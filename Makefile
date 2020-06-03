# set C++ compiler
CC := g++
CFLAGS := -std=c++11

# source
ifeq ($(OS), Windows_NT)
SRC_LIST := $(shell dir /b .\src\*.cpp)
else
SRC_LIST := $(shell ls ./src/*.cpp)
endif
SRC_PATH := ./src/
SRC := $(SRC_LIST)

# object
OBJ_PATH := ./obj/
ifeq ($(OS), Windows_NT)
OBJ := $(patsubst %.cpp, $(OBJ_PATH)%.o, $(SRC_LIST))
else
OBJ := $(patsubst $(SRC_PATH)%.cpp, $(OBJ_PATH)%.o, $(SRC_LIST))
endif

# whole compile
all: $(OBJ)
ifeq ($(OS), Windows_NT)
	$(CC) $(CFLAGS) -o Visual_Computer.exe $(OBJ)
else
	$(CC) $(CFLAGS) -o Visual_Computer.out $(OBJ)
endif

# compile main
$(OBJ_PATH)main.o: $(SRC_PATH)main.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

# compile pair of .cpp and .h 	
$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp $(SRC_PATH)%.h
	$(CC) $(CFLAGS) -o $@ -c $<

# clean .exe/.out and .o
.PHONY: clean
clean:
ifeq ($(OS), Windows_NT)
	del Visual_Computer.exe
	del .\obj\*.o
else
	rm ./Visual_Computer.out
	rm ./obj/*.o
endif