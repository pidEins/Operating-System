CC=g++
CFLAGS=-I.

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: L2_memory_access_time.o
	$(CC) -o L2_memory_access_time L2_memory_access_time.o

clean:
	rm -rf L2_memory_access_time
	rm -rf L2_memory_access_time.o
