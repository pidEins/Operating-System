CC=g++
CFLAGS=-I.
#DEPS = hellomake.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: context_switch.o
	$(CC) -pthread -o context_switch context_switch.o

clean:
	rm -rf context_switch
	rm -rf context_switch.o
