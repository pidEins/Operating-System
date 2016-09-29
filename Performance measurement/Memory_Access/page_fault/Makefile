CC=g++
CFLAGS=-I.

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: page_fault.o
	$(CC) -o page_fault page_fault.o

clean:
	rm -rf page_fault
	rm -rf page_fault.o
