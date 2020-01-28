#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OSTYPE),cygwin)
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
else ifeq ($(OS),Windows_NT)
	CLEANUP = del /F /Q
	MKDIR = mkdir
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

PATHB = build/
PATHI = include/
PATHS = src/

CC=gcc
CFLAGS=-I$(PATHI)

_DEPS = hellomake.h
DEPS = $(patsubst %,$(PATHI)%,$(_DEPS))

_OBJ = hellomake.o hellofunc.o 
OBJ = $(patsubst %,$(PATHB)%,$(_OBJ))

LIBS=-lm

$(PATHB)%.o: $(PATHS)%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# Notice format: 
# Compiler + Output File + Dependencies + Compile Flags
#gcc -o hellomake hellomake.c hellofunc.c -I.
#$(CC) -o hellomake hellomake.o hellofunc.o

.PHONY: clean

$(PATHB):
	$(MKDIR) $(PATHB)

clean:
	$(CLEANUP) $(PATHB)*.o

