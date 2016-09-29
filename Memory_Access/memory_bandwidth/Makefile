CC=g++
CFLAGS=-I.

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: memory_bandwidth.o
	$(CC) -o memory_bandwidth memory_bandwidth.o

clean:
	rm -rf memory_bandwidth
	rm -rf memory_bandwidth.o
