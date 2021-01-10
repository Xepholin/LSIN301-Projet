CC = gcc
CFLAGS = -c -Wall
LDFLAGS = -lm
CSRC = *.c
HSRC = *.h
OBJS = main.o constantes.o lectStock.o ABR.o recherche.o

run: dico
	./dico fichier.txt

dico : $(OBJS)
	$(CC) -g -o $@ $^
	
%.o: %.c
	$(CC) $(CFLAGS) $<
	
valgrind: dico
	valgrind ./dico fichier.txt


clean:
	rm -f *.o
	rm -f dico
