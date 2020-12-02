all:main
.PHONY:test clean
CFILES:=$(wildcard *.c)
OBJS:=$(patsubst %.c,%.o,$(CFILES))
FLAGS:=-O3 -Wall -std=c99
ifdef DEBUG
FLAGS+=-g
endif
main:$(OBJS)  *.h
	gcc $(OBJS) -o $@ $(FLAGS)
%.o:%.c type.h
	gcc $< -c -o $@ $(FLAGS)
test:
	@echo $(CFILES)
	@echo $(OBJS)
clean:
	-@rm main *.o 
	