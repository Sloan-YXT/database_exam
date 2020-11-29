all:main
.PHONY:test clean
CFILES:=$(wildcard *.cpp)
OBJS:=$(patsubst %.cpp,%.o,$(CFILES))
FLAGS:=-O3 -Wall
ifdef DEBUG
FLAGS+=-g
endif
main:$(OBJS) *.h
	g++ $^ -o $@ $(FLAGS)
%.o:%.cpp
	g++ $^ -c -o $@ $(FLAGS)
test:
	@echo $(CFILES)
	@echo $(OBJS)
clean:
	-@rm main *.o 