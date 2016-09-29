CC=g++
CFLAGS=-I.
#DEPS = hellomake.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: measurement_overhead.o
	g++ -o measurement_overhead measurement_overhead.o

clean:
	rm -rf measurement_overhead
	rm -rf measurement_overhead.o
