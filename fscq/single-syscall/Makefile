CC=gcc
CFLAGS=-Wall -g -pie -fPIC

C_FILES = $(wildcard *.c)
EXE_FILES = $(patsubst  %.c,%,${C_FILES})

all: ${EXE_FILES}

${EXE_FILES}: % : %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	@rm -rf ${EXE_FILES} testdir
