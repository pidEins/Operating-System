CC=g++
CFLAGS=-I.

SUBDIRS = Context_Switch System_Call_Overhead Procedure_Overhead Measurement_Overhead Task_Creation_Overhead \
	Memory_Access 

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
