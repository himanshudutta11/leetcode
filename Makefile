CC     = gcc
CFLAGS = -Wall -Wextra

SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c,build/%.o,$(SRC))
EXE := $(patsubst src/%.c,build/%,$(SRC))

.PHONY: all obj

all: $(EXE)

obj: $(OBJ)

$(EXE): %: %.o
	$(CC) $(LDFLAGS) $< -o $@

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $< -c -o $@

.PHONY: clean

clean:
	rm -f $(OBJ) $(EXE)