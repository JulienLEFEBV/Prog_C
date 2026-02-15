CC=gcc
CFLAGS=-std=c11 -Wpedantic -Wall -Wextra
RM=rm -f
LDLIBS=-lm
OBJ=TP9.o matrice.o image.o ti.o
EXE=TP9
$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) $(LDLIBS)
TP9.o:TP9.c ti.h image.h
	$(CC) $(CFLAGS) -c TP9.c
ti.o: ti.c image.h
	$(CC) $(CFLAGS) -c ti.c
image.o: image.c matrice.h
	$(CC) $(CFLAGS) -c image.c
matrice.o:matrice.c matrice.h
	$(CC) $(CFLAGS) -c matrice.c
clean:
	$(RM) $(OBJ) $(EXE)