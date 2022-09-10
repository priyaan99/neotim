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

void free_col(Col* col) {
	free(col->buf);
}

void row_delete(Row* row, int at) {
	if (at < 0 || at >= row->size) return;
	free_col(&row->col[at]);
	for (ssize_t i = at; i < row->size-1; i++) row->col[i] = row->col[i+1];
	row->size--;
}

// Tests

void print_col(Col *c) {
	//printf("col size :: %ld, cap :: %ld\n", c->size, c->cap);
	for (int i = 0; i < c->size; i++) {
		putchar(c->buf[i]);
	}
	printf("-\n");
}

void print_row(Row* r) {
	printf("Row size :: %ld, capacity :: %ld\n", r->size, r->cap);
	for (int i = 0; i < r->size; i++) {
		print_col(&r->col[i]);
	}
}

void test_col() {
	Col c1 = col_init();
	col_insert(&c1, c1.size, 'h');
	col_insert(&c1, c1.size, 'e');
	col_insert(&c1, c1.size, 'l');
	col_insert(&c1, c1.size, 'l');
	col_insert(&c1, c1.size, 'o');
	col_insert(&c1, 0, '-');
	col_insert(&c1, 2, '-');
	col_insert(&c1, c1.size+1, '-');
	col_insert(&c1, c1.size-1, '-');
	col_insert(&c1, -1, '-');

	for (int i = 0; i < c1.size; i++) putchar(c1.buf[i]);
	putchar('\n');

	free_col(&c1);
}

void test_row() {
	char *s[5] = {"hello", "two-two-two-two-two-two", "three-three-three-three-three-three-three-three-", "four", "five"};

	Row row = row_init();
	for (int i = 0; i < 5; i++) {
		Col c = col_init();
		for (int j = 0; j < strlen(s[i]); j++) {
			col_insert(&c, c.size, s[i][j]);
		}

		row_insert(&row, c, row.size);
	}

    Col c = col_init();
    col_insert(&c, c.size, 'a');
    col_insert(&c, c.size, 'a');
    col_insert(&c, c.size, 'a');

    row_insert(&row, c, row.size);

	for (int i = 0; i < row.size; i++) {
		for (int j = 0; j < row.col[i].size; j++) {
			putchar(row.col[i].buf[j]);
		}
        printf("\t col.size %ld, col.cap %ld\n", row.col[i].size, row.col[i].cap);
	}

    printf("\nRow size %ld, cap %ld\n", row.size, row.cap);
}
