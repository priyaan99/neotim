#include "common.h"
#include "fileio.h"
#include "rowcol.h"

void read_file(Row* r, const char* filename) {
	FILE* f = fopen(filename, "rb");
	if (f == NULL) {
		return;
	}

	while (1) {

		Col col = col_init();
		col.size = getline(&col.buf, &col.cap, f);
		if (col.size == EOF) break;

		while (col.buf[col.size-1] == '\n' || col.buf[col.size-1] == '\r')
			col.size -= 1;

		row_insert(r, col, r->size);
	}

	fclose(f);
}

void write_file(Row* r, const char* filename) {
	FILE* f = fopen(filename, "wb+");
	if (f == NULL) return;

	for (int i = 0; i < r->size; i++)
	{
		col_insert(&r->col[i], r->col[i].size, '\n');
		if (fwrite(r->col[i].buf, sizeof(char), r->col[i].size, f) == -1)
		{
			break;
		}
	}

	fclose(f);
}
