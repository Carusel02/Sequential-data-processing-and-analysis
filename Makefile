# Declaratiile de variabile
CC = gcc
CFLAGS = -g -Wall -lm
 
# Regula de compilare
all: build

build:
	$(CC) -o tema1 tema1.c $(CFLAGS)


clean:
	rm -f tema1
	rm -f *.out
