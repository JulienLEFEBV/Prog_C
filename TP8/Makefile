CC=gcc
CFLAGS=-std=c11 -Wpedantic -Wall -Wextra
RM=rm -f
LDLIBS=-lm
OBJ=TP8_EX2.o matrice.o image.o
EXE=TP8_EX2
$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) $(LDLIBS)
TP8_EX2.o:TP8_EX2.c matrice.h
	$(CC) $(CFLAGS) -c TP8_EX2.c
image.o: image.c matrice.h
	$(CC) $(CFLAGS) -c image.c
matrice.o:matrice.c matrice.h
	$(CC) $(CFLAGS) -c matrice.c
clean:
	$(RM) $(OBJ) $(EXE)