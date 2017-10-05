#Copyright Notice:
#The files within this zip file are copyrighted by Lazy Foo' Productions (2004-2014)
#and may not be redistributed without written permission.

#OBJS specifies which files to compile as part of the project
OBJS = src/main.cpp

#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -IC:\mingw_dev_lib\include\SDL2

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -LC:\mingw_dev_lib\lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)




# FLAGS   := -g -Wall -fdiagnostics-color=always -fno-diagnostics-show-caret -DARCH=\"$(shell uname -m)\"
# OBJLIST := $(patsubst src/%.cpp,%.o,$(wildcard src/*.cpp))
#
# .PHONY: test
# .PHONY: distclean
#
# all: neuralNetwork
#
#
# sinclude .depend
#
#
# neuralNetwork: $(OBJLIST)
# 	@echo ""
# 	@echo "linking ..."
# 	@g++ $(FLAGS) -o neuralNetwork *.o -lSDL2
# 	@echo ""
# 	@stat -c '%n      %s Bytes' $@
# 	@echo ""
#
#
# %.o: src/%.cpp
# 	@echo "compiling $< ..."
# 	@g++ -c $(FLAGS) -o $@ $<
#
#
# .depend: src/*.cpp src/*.h
# 	@for f in src/*.cpp ; do k=$$(basename $$f); cpp -M -MG -MT $${k%.*}.o $$f ; done > .depend
#
#
# distclean:
# 	@rm -vf *.o .depend neuralNetwork
# 	@rm -rfv cache
#
#
# test:
# 	@echo "OBJLIST='$(OBJLIST)'"