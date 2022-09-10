#include "editor.h"
#include "common.h"
#include "fileio.h"
#include "rowcol.h"

void die(const char *s) {
	end();
	fprintf(stderr, "%s ", s);

	perror(s);
	exit(1);
}

int main() {
    Row erow = row_init();
    read_file(&erow, "main.c");
    print_row(&erow);
    write_file(&erow, "write");
    for (int i = 0; i < erow.size; i++) row_delete(&erow, 0);

	//init(); run(); end();
    return 0;
}




