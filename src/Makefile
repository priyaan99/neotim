CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99
LIB=-lncurses
OBJS=main.o
NAME=neotim

neotim: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

main.o: main.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm $(OBJS) $(NAME)
