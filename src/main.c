#include "editor.h"
#include "common.h"

#include "rowcol.h"

void die(const char *s) {
	end();
	fprintf(stderr, "%s ", s);

	perror(s);
	exit(1);
}

int main() {
	init(); run(); end();
    return 0;
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
