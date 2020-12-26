#
# Makefile for misc library 'libapue'.
#
ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

LIBMISC = libapue.a
OBJS = error.o pathalloc.o tellwait.o prexit.o prmask.o lockreg.o locktest.o writen.o readn.o setfl.o setfd.o clrfl.o \
    openmax.o

all: $(LIBMISC) 

$(LIBMISC): $(OBJS)
	$(AR) rv $(LIBMISC) $?
	$(RANLIB) $(LIBMISC)

clean:
	rm -rf *.o a.out core temp.* $(LIBMISC)
	
include $(ROOT)/Make.libapue.inc