clean:
	rm -rf ./sci

all: main.c
	make clean && clang main.c cipher.c -o ./sci

