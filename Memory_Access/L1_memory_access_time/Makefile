CC=g++
CFLAGS=-I.

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: L1_memory_access_time.o
	$(CC) -o L1_memory_access_time L1_memory_access_time.o

clean:
	rm -rf L1_memory_access_time
	rm -rf L1_memory_access_time.o
