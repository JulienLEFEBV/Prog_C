CC=gcc
CFLAGS=-std=c11 -Wpedantic -Wall -Wextra
RM=rm -f
OBJ=TP8_EX1.o matrice.o
EXE=TP8_EX1
$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE)
TP8_EX1.o:TP8_EX1.c matrice.h
	$(CC) $(CFLAGS) -c TP8_EX1.c
matrice.o:matrice.c matrice.h
	$(CC) $(CFLAGS) -c matrice.c
clean:
	$(RM) $(OBJ) $(EXE)