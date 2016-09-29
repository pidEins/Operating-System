CC=g++
CFLAGS=-I.

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: procedure_call_overhead.o
	g++ -o procedure_call_overhead procedure_call_overhead.o

clean:
	rm -rf procedure_call_overhead
	rm -rf procedure_call_overhead.o
