#ifndef EDITOR_H
#define EDITOR_H

#include "rowcol.h"

typedef struct {
	int c;
	Row rows;
} Editor;

void init();
void run();
void end();

#endif
