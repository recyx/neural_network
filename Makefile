OBJS 	 = main.cpp
OBJ_NAME = neuralNetwork

CC = g++
#COMPILER_FLAGS = -w
LINKER_FLAGS = -lSDL2 -lSDL2_image

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
