CC=g++
CFLAGS=-I.

SUBDIRS = L1_memory_access_time L2_memory_access_time ram_memory_access_time \
	memory_bandwidth page_fault

MYMAKEFLAGS = 'BINDIR=$(BINDIR)' 'MANDIR=$(MANDIR)' 'MANSECT=$(MANSECT)'\
 'INSTALL=$(INSTALL)' 'INSTALLBIN=$(INSTALLBIN)' 'INSTALLMAN=$(INSTALLMAN)'\
 'CC=$(CC)' 'SWITCHES=$(SWITCHES)' 'O=$(O)' 'LIBRARYOBJS=$(LIBRARYOBJS)' \
 'OPTIMIZE=$(OPTIMIZE)' 'MACHINE=$(MACHINE)'

 
all:
	@for i in $(SUBDIRS); do \
	echo "make all in $$i..."; \
	(cd $$i; $(MAKE) $(MFLAGS) $(MYMAKEFLAGS) all); \
	echo "\n"; done

clean:
	@for i in $(SUBDIRS); do \
	echo "Clearing in $$i..."; \
	(cd $$i; $(MAKE) $(MFLAGS) $(MYMAKEFLAGS) clean); \
	echo "\n"; done
