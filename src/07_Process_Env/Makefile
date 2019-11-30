ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS = doatexit echoarg getrlimit testjmp testenv

all:	$(PROGS)

$(PROGS):	$(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)
clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc
