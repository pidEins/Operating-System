CC=g++
CFLAGS=-I.
#DEPS = hellomake.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: task_creation_overhead.o
	g++ -pthread -o task_creation_overhead task_creation_overhead.o

clean:
	rm -rf task_creation_overhead
	rm -rf task_creation_overhead.o
