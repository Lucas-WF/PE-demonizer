#pragma once

#include <stdio.h>
#include <inttypes.h>

void demonize_dos_header(FILE* file);
void demonize_coff_header(FILE* file);