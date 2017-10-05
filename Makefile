
FLAGS   := -g -Wall -fdiagnostics-color=always -fno-diagnostics-show-caret -DARCH=\"$(shell uname -m)\"
OBJLIST := $(patsubst src/%.cpp,%.o,$(wildcard src/*.cpp))

.PHONY: test
.PHONY: distclean

all: neuralNetwork


sinclude .depend


neuralNetwork: $(OBJLIST)
	@echo ""
	@echo "linking ..."
	@g++ $(FLAGS) -o neuralNetwork *.o -lSDL2
	@echo ""
	@stat -c '%n      %s Bytes' $@
	@echo ""


%.o: src/%.cpp
	@echo "compiling $< ..."
	@g++ -c $(FLAGS) -o $@ $<


.depend: src/*.cpp src/*.h
	@for f in src/*.cpp ; do k=$$(basename $$f); cpp -M -MG -MT $${k%.*}.o $$f ; done > .depend
	

distclean:
	@rm -vf *.o .depend neuralNetwork
	@rm -rfv cache


test:
	@echo "OBJLIST='$(OBJLIST)'"

