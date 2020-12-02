all:main
.PHONY:test clean
CFILES:=$(wildcard *.cpp)
OBJS:=$(patsubst %.cpp,%.o,$(CFILES))
FLAGS:=-O3 -Wall -std=c++11 -lpthread
ifdef DEBUG
FLAGS+=-g
endif
main:$(OBJS)  *.h
	g++ $(OBJS) -o $@ $(FLAGS)
%.o:%.cpp type.h
	g++ $< -c -o $@ $(FLAGS)
test:
	@echo $(CFILES)
	@echo $(OBJS)
clean:
	-@rm main *.o 
	