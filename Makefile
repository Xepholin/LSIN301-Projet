CC = gcc
CFLAGS = -c -Wall
LDFLAGS = -lm
CSRC = *.c
HSRC = *.h
OBJS = main.o fonctions.o

run: dico
	./dico pg31469.txt

dico : $(OBJS)
	$(CC) -o $@ $^
	
%.o: %.c
	$(CC) $(CFLAGS) $<
	
valgrind: dico
	valgrind ./dico


clean:
	rm -f *.o
	rm -f dico
