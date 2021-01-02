ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

ifeq "$(PLATFORM)" "linux"
  EXTRALIBS=-lrt
endif
ifeq "$(PLATFORM)" "solaris"
  EXTRALIBS=-lrt
endif

PROGS =	add2 add2stdio devzero myuclc pipe1 pipe2 pipe3 pipe4 popen1 popen2 tshm fifo read_fifo write_fifo \
         read_shm write_shm mq_client mq_server
MOREPROGS = shm_put shm_get
all:	$(PROGS) $(MOREPROGS) popen.o slock.o tellwait.o shm_fifo.o

shm_get:	shm_get.o shm_fifo.o
		$(CC) $(CFLAGS) -o shm_get shm_get.o shm_fifo.o $(LDFLAGS) $(LDLIBS)

shm_put:	shm_put.o shm_fifo.o
		$(CC) $(CFLAGS) -o shm_put shm_put.o shm_fifo.o $(LDFLAGS) $(LDLIBS)

slock.o:	slock.c slock.h

$(PROGS):	$(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc
