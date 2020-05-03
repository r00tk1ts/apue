ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

ifeq "$(PLATFORM)" "linux"
  EXTRALIBS=-lrt
endif
ifeq "$(PLATFORM)" "solaris"
  EXTRALIBS=-lrt
endif

PROGS =	deadlock mandatory mcopy2 nonblockw

all:	$(PROGS) $(MOREPROGS) lockfile.o

$(PROGS):	$(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(MOREPROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc
