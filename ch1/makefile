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
PATHL = /usr/local/opt/openssl/lib/

CC=gcc-9
CFLAGS=-L$(PATHL) -I$(PATHI) -O2 -pipe -ansi -DONLINE_JUDGE

# Take header files in PATHI 
DEPS = $(wildcard $(PATHI)*.h)

# Take source files in PATHS 
SRCS = $(wildcard $(PATHS)*.c)

# Replace pattern PATHS/*.c -> PATHB/*.o 
OBJ = $(patsubst $(PATHS)%.c,$(PATHB)%.o,$(SRCS))

LIBS=-lm -lcrypto

$(PATHB)%.o: $(PATHS)%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

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
	$(CLEANUP) hellomake 

