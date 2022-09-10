#include "common.h"
#include "rowcol.h"

Col col_init() {
	Col col;
	col.size = 0;
	col.cap = 2;
	col.buf = (char*) malloc(sizeof(char)*col.cap);
	if (col.buf == NULL) die("col_init");
	return col;
}

Row row_init() {
	Row row;
	row.size = 0;
	row.cap = 2;
	row.col = (Col*) malloc(sizeof(Col)*row.cap);
	if (row.col == NULL) die("init row");
	return row;
}


void col_insert(Col* col, int at, char c) {
	if (at > col->size || at < 0) return;

	if (col->size+1 >= col->cap) {
		col->cap *= 2;
		col->buf = (char*) realloc(col->buf, sizeof(char)*col->cap);
	}

	for (ssize_t i = col->size; i > at; i--) col->buf[i] = col->buf[i-1];

	col->buf[at] = c;
	col->size++;
}

void row_insert(Row* row, Col col, int at) {
	if (at > row->size || at < 0) return; 

	if (row->size+1 >= row->cap) {
		row->cap *= 2;
		row->col = (Col*) realloc(row->col, sizeof(Col)*row->cap);
	}
	
	for (ssize_t i = row->size; i > at; i--) row->col[i] = row->col[i-1];
	
	row->col[at] = col;
	row->size++;
}

void col_delete(Col* col, int at) {
	if (at >= col->size || at < 0) return;

	for (ssize_t i = at; i < col->size-1; i++) col->buf[i] = col->buf[i+1];
	col->size--;
}

void row_delete(Row* row, int at) {
	if (at < 0 || at >= row->size) return;
	for (ssize_t i = at; i < row->size-1; i++) row->col[i] = row->col[i+1];
	row->size--;
}

void free_col(Col* col) {
	free(col->buf);
}

void free_row(Row* row, int at) {
	free_col(row[at].col); // frees col buf
	free(row[at].col); // free col
}
