CC=g++
CFLAGS=-I.

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: system_call_overhead.o
	$(CC) -o system_call_overhead system_call_overhead.o

clean:
	rm -rf system_call_overhead
	rm -rf system_call_overhead.o
