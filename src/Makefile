DIRS = lib 01_UNIX_Introduction

all:
	for i in $(DIRS); do \
		(cd $$i && echo "making &&i" && $(MAKE) ) || exit 1; \
	done
	
clean:
	for i in $(DIRS); do \
		(cd $$i && echo "cleaning $$i" && $(MAKE) clean) || exit 1; \
	done