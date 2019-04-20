DIRS = lib 01_UNIX_Introduction 02_UNIX_Standard 03_Unbuffered_IO 05_Standard_IO

all:
	for i in $(DIRS); do \
		(cd $$i && echo "making &&i" && $(MAKE) ) || exit 1; \
	done
	
clean:
	for i in $(DIRS); do \
		(cd $$i && echo "cleaning $$i" && $(MAKE) clean) || exit 1; \
	done
