#ifndef COMMON_H
#define COMMON_H

// it is called "feature test macro"
// on define enable some featue in lib
#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void die(const char *s);

#endif
