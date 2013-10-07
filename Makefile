CC=gcc

dirchat: dirchat.c dirchat.h
	$(CC) dirchat.h dirchat.c -o dirchat
clean:
	rm dirchat -f
veryclean:
	rm *.c~ -f
	rm *.h~ -f