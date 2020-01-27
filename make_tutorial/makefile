CC=gcc
CFLAGS=-I.
DEPS = hellomake.h
OBJ = hellomake.o hellofunc.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS) 

# Notice format: 
# Compiler + Output File + Dependencies + Compile Flags
#gcc -o hellomake hellomake.c hellofunc.c -I.
#$(CC) -o hellomake hellomake.o hellofunc.o

