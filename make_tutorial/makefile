IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

ODIR=obj
_OBJ = hellomake.o hellofunc.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS) 

# Notice format: 
# Compiler + Output File + Dependencies + Compile Flags
#gcc -o hellomake hellomake.c hellofunc.c -I.
#$(CC) -o hellomake hellomake.o hellofunc.o

