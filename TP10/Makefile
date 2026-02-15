CC=gcc
CFLAGS=-std=c11 -Wpedantic -Wall -Wextra
RM=rm -f
LDLIBS=-lm
OBJ=TP10.o matrice.o image.o ti.o
EXE=TP10
$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) $(LDLIBS)
TP10.o:TP10.c ti.h image.h
	$(CC) $(CFLAGS) -c TP10.c
ti.o: ti.c image.h
	$(CC) $(CFLAGS) -c ti.c
image.o: image.c matrice.h
	$(CC) $(CFLAGS) -c image.c
matrice.o:matrice.c matrice.h
	$(CC) $(CFLAGS) -c matrice.c
clean:
	$(RM) $(OBJ) $(EXE)