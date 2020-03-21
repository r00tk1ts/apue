ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS =	critical read1 read2 reenter sigtstp sigusr suspend1 suspend2 sigint
MOREPROGS = systest2 tsleep2

all:	$(PROGS) $(MOREPROGS) sleep1.o sleep2.o system.o abort.o

$(PROGS):	$(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

tsleep2:	tsleep2.o sleep2.o
		$(CC) $(CFLAGS) -o tsleep2 tsleep2.o sleep2.o $(LDFLAGS) $(LDLIBS)

systest2:	systest2.o system.o
		$(CC) $(CFLAGS) -o systest2 systest2.o system.o $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(MOREPROGS) $(TEMPFILES) *.o file.hole

include $(ROOT)/Make.libapue.inc
