#include <ncurses.h>
#include "common.h"
#include "editor.h"
#include "render.h"

Editor E;

static void update() {
    E.c = getch();
}

void run() {
    render();
    while (E.c != 'q') {
        update();
        render();
    }
}

void init() {
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    E.c = -1;
}

void end() {
    endwin();
}

/***

initscr();
raw();
keypad(stdscr, TRUE);
noecho();

while (notquite) {
    clear();
    printw("hello");
    refresh();
}

endwin();

***/
