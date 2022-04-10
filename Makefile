# Declaratiile de variabile
CC = gcc
CFLAGS = -g -Wall -lm -std=c11
 
# Regula de compilare
all: build

build: tema1

tema1: tema1.c
	$(CC) -o tema1 tema1.c $(CFLAGS)


clean:
	rm -f tema1
	rm -f *.out
