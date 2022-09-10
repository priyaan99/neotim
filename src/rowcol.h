#ifndef ROWCOL_H
#define ROWCOL_H

#include <sys/types.h> // for ssize_t
#include "common.h"

typedef struct {
	size_t cap;
	ssize_t size; 
	char* buf;
} Col;

typedef struct {
	size_t cap;
	ssize_t size;
	Col* col;
} Row;

Col col_init();
Row row_init();

void col_insert(Col* col, int at, char c);
void row_insert(Row* row, Col col, int at);

void col_delete(Col* col, int at);
void row_delete(Row* row, int at);

void free_col(Col* col);
void free_row(Row* row, int at);

#endif
