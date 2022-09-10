CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99
LIB=-lncurses
OBJS=main.o editor.o render.o fileio.o rowcol.o
NAME=neotim

neotim: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

main.o: main.c editor.h render.h common.h
	$(CC) -c $< $(CFLAGS)

editor.o: editor.c editor.h fileio.h rowcol.h common.h
	$(CC) -c $< $(CFLAGS)

render.o: render.c render.h rowcol.h common.h 
	$(CC) -c $< $(CFLAGS)

fileio.o: fileio.c fileio.h common.h
	$(CC) -c $< $(CFLAGS)

rowcol.o: rowcol.c rowcol.h common.h
	$(CC) -c $< $(CFLAGS)

clean:
	rm $(OBJS) $(NAME)
