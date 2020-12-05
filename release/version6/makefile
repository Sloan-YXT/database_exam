all:main
.PHONY:main clean test
CFILES:= $(wildcard *.cpp)
OBJFILES:=$(patsubst %.cpp,%.o,$(CFILES))
FLAGS:= -g -Wall -std=c++11 -O3
LIBS:=-lpthread
ifdef DEBUG
FLAGS+=-g
endif
main:$(OBJFILES)
	g++ $(OBJFILES)  -o main $(FLAGS) $(LIBS)
%.o:%.cpp type.h
	g++ $<  -c -o $@ $(FLAGS)
shell_sort.o:shellsort.cpp shell_sort.h type.h
	g++ $<  -c -o $@ $(FLAGS)
test:
	@echo $(CFILES)
	@echo $(OBJFILES)
clean:
	@-rm main $(OBJFILES)