CC=g++
CFLAGS=-I.

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: ram_memory_access_time.o
	g++ -o ram_memory_access_time ram_memory_access_time.o

clean:
	rm -rf ram_memory_access_time
	rm -rf ram_memory_access_time.o
