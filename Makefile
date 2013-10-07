CC=gcc

dirchat: dirchat.c dirchat.h
	$(CC) dirchat.h dirchat.c -o dirchat

dirchatlyle: dirchatlyle.o utils.o
	gcc -o dirchatlyle.o utils.o
clean:
	rm *.o -f
	rm dirchat -f
veryclean:
	rm *.c~ -f
	rm *.h~ -f
