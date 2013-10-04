CC=gcc

dirchat: dirchat.c dirchat.h
	$(CC) dirchat.h dirchat.c -o dirchat
