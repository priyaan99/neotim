#ifndef FILEIO_H
#define FILEIO_H

#include "rowcol.h"

void read_file(Row* r, const char* filename);
void write_file(Row* r, const char* filename);

#endif
