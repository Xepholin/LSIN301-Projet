CC = gcc
CFLAGS = -c -Wall
LDFLAGS = -lm
CSRC = *.c
HSRC = *.h
OBJS = main.o constantes.o lectStock.o ABR.o recherche.o chrono.o

run: dico
	./dico pg31469.txt Project

dico : $(OBJS)
	$(CC) -g -o $@ $^
	
%.o: %.c
	$(CC) $(CFLAGS) $<
	
valgrind: dico
	valgrind ./dico pg31469.txt Project


clean:
	rm -f *.o
	rm -f dico
