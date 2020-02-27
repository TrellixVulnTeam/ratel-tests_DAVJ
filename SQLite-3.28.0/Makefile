CC=gcc
CFLAGS=-Os -I -g -pie -fPIC
LDFLAGS=-ldl -lz -lpthread
all: speedtest1

speedtest1: speedtest1.c sqlite3.c
	$(CC) $(CFLAGS) -o speedtest1 speedtest1.c sqlite3.c $(LDFLAGS)

clean:
	rm -rf speedtest1
